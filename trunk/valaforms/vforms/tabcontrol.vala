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
	public class TabControl : Control
	{
		protected int _selected_index = -1;
		
		public int selected_index
		{
			get {
				return _selected_index;
			}
			set {
				if (_selected_index != value) {
					on_selected_index_changing ();
					_selected_index = value;
					on_selected_index_changed ();
				}
			}
		}
		
		public override void create_control ()
		{
			window = Window.create (
				0,
				WindowClass.TABCONTROL, 
				null,
				(WindowStyle.CLIPCHILDREN | WindowStyle.CHILD | WindowStyle.VISIBLE),
				(int) location.x,
				(int) location.y,
				size.width, 
				size.height,
        			parent.window, (Menu) this, _wce.instance, this);
        			
        		if (window == Window.NULL) {
        			MessageBox.error ("Create tabcontrol failed");
        			return;
			}
			window.set_long_ptr (WindowLong.USERDATA, this);
			create_children_controls ();
		}
				
		internal override void create_children_controls ()
		{
			int i = 0;
			foreach (Control control in controls) {
				if (!control.is_handle_created && control is TabPage) {
					var tab_page = (TabPage) control;
					tab_page.index = i++;
					tab_page.parent = this; /* TODO: implement observable collection */
					tab_page.create_control ();
				}
			}
			
			selected_index = ((TabCtrl)window).get_cur_sel ();
		}
		
		public override int process_message (Window win, uint msg_id, WParam w_param, LParam l_param, ref bool processed)
		{
			int result = 0;
			switch (msg_id) {
				case MessageId.NOTIFY:
					var nmh = (NotifyMessageHeader*)l_param;
					if (nmh->code == TabCtrlNotification.SELCHANGE) {
						var tctl = (TabCtrl) nmh->hwndFrom;
						selected_index = tctl.get_cur_sel ();
						processed = true;
					}
					break;
			}
			
			return result;
		}
		
		protected virtual void on_selected_index_changing ()
		{
			if (_selected_index >= 0) {
				/* hide previous tab */
				controls.nth_data (_selected_index).hide ();
			}
		}
				
		protected virtual void on_selected_index_changed ()
		{
			if (_selected_index >= 0) {
				/* show current tab */
				controls.nth_data (_selected_index).show ();
			}
		}
	}
}

