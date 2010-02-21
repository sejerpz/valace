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
	public class TabPage : Container
	{
		internal int index = 0;
		
		public TabPage ()
		{
			this.with_text ("");
		}
		
		public TabPage.with_text (string text)
		{
			_text = text;
		}
		
		public override void create_control ()
		{
			var tctrl = (TabCtrl)((TabControl)parent).window;
			var tc_item = TabCtrlItem ();
			tc_item.mask = TabCtrlFlags.TEXT | TabCtrlFlags.PARAM;
			tc_item.pszText = StringW.from_string (_text);
			tc_item.lParam = (LParam)this;
			if (tctrl.insert_item (index, tc_item) < 0) {
				MessageBox.error ("insert_item failed for tabpage");
			}
			
			var rectangle = Rectangle ();
			if (!tctrl.get_item_rect (index, ref rectangle)) {
				MessageBox.error ("get_item_rect failed for tabpage");
				return; 
			}
							
			window = Window.create (
				0,
				"VFormsWindowClass", 
				StringW.from_string (text),
				WindowStyle.CLIPCHILDREN | WindowStyle.CHILD | WindowStyle.GROUP,
				(int) 2,
				(int) (rectangle.bottom - rectangle.top) + 4,
				(int) (parent.size.width - 4),
				(int) (parent.size.height - (rectangle.bottom - rectangle.top) - 6),
        			parent.window, (Menu) this, _wce.instance, this);
        			
        		if (window == Window.NULL) {
        			MessageBox.error ("Create tabpage failed");
        			return;
			}
			
			create_children_controls ();
		}
	}
}

