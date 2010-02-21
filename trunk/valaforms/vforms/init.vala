/*
 * This file is part of ValaForms 
 *
 * Copyright (C) 2010 - Andrea Del Signore
 *
 * ValaForms is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ValaForms is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
using GLib;
using Windows;

namespace VForms
{
	public class WCeData
	{
		public Instance instance;
		public WndClass wc_window;
		
		public WCeData ()
		{
			wc_window = WndClass ();
			Windows.Utils.zero_memory (&wc_window, sizeof(WndClass));
		}
	}
	
	public static WCeData _wce;
	
	public static void init (Instance instance)
	{
		GLib.ThreadSystem.init (null);	
		GLib.TypeSystem.init ();
		_wce = new WCeData ();
		
		//Registering the Window Class
		_wce.wc_window.style         = ClassStyle.DBLCLKS | ClassStyle.HREDRAW | ClassStyle.VREDRAW;
		_wce.wc_window.lpfnWndProc   = _vform_default_wnd_proc;
		_wce.wc_window.cbClsExtra    = 0;
		_wce.wc_window.cbWndExtra    = 0;
		_wce.wc_window.hInstance     = _wce.instance;
		_wce.wc_window.hIcon         = 0; //LoadIcon(NULL, IDI_APPLICATION);
		_wce.wc_window.hCursor       = 0; //LoadCursor(NULL, IDC_ARROW);
		_wce.wc_window.hbrBackground = (Brush) StockObject.@get (StockObjectId.WHITE_BRUSH);
		if (_wce.wc_window.hbrBackground == 0)
			MessageBox.error ("Brush is null");
			
		_wce.wc_window.lpszMenuName  = null;
		_wce.wc_window.lpszClassName = "VFormsWindowClass";
		if (_wce.wc_window.register () == 0)
			MessageBox.error ("Register 'VFormsWindowClass' failed");
		
		/* Init common controls */
		InitCommonControlsEx comm_ctls = InitCommonControlsEx ();
		comm_ctls.dwSize = (DWord) sizeof (InitCommonControlsEx);
		comm_ctls.dwICC = InitCommonControlsClass.TAB_CLASSES;
		
		if (!init_common_controls_ex(comm_ctls))
			MessageBox.error ("Init common controls failed");
		
	}
	
	private static LResult _vform_default_wnd_proc (Window window, MessageId msg_id, WParam w_param, LParam l_param) 
	{
		Control control = null;
		bool need_create_child = false;
		
		// check to see if a copy of the 'this' pointer needs to be saved
		if (msg_id == MessageId.CREATE ) {
			control = (Control) ((CreateStruct*)l_param)->lpCreateParams;
			if (control != null) {
				control.is_dialog = false;
				control.window = window;
				window.set_long_ptr (WindowLong.USERDATA, control);
				need_create_child = true;
			}
		} else if (msg_id == MessageId.INITDIALOG ) {
			control = (Control) l_param;
			if (control != null) {
				control.is_dialog = true;
				window.set_long_ptr (WindowLong.USERDATA, control);
			}
		} else if (msg_id == MessageId.NOTIFY) {
			var nmh = (NotifyMessageHeader*)l_param;
			control = (Control) (int) nmh->hwndFrom.get_long_ptr (WindowLong.USERDATA);
		} else {
			control = (Control) window.get_long_ptr (WindowLong.USERDATA);
		}

		bool processed = false;
		LResult result = (LResult)false;

		if ( control != null ) {
			result = (LResult) control.process_message (window, msg_id, w_param, l_param, ref processed );
			if (control.is_dialog) {
				result = (LResult) processed;     // processing a dialog message return TRUE if processed
			}
			
			if (need_create_child)
				control.create_children_controls ();
				
			if (!processed && !control.is_dialog) {
				// If message was unprocessed and not a dialog, send it back to Windows.
				result = window.def_window_proc (msg_id, w_param, l_param);
			}
		} else {
			MessageBox.show ("No control found for window %d".printf ((int) window));
		}
		
		return result;
	}
}
