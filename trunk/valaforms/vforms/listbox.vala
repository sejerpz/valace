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
	public class ListBox : Control
	{
		protected List<ListItem> items = new List<ListItem> ();
		
		public override void create_control ()
		{
			window = Window.create (
				WindowStyleEx.CLIENTEDGE,
				WindowClass.LISTBOX, 
				null,
				(WindowStyle.CLIPCHILDREN | WindowStyle.CHILD | WindowStyle.VISIBLE  | WindowStyle.HSCROLL | WindowStyle.VSCROLL),
				(int) location.x,
				(int) location.y,
				size.width, 
				size.height,
        			parent.window, (Menu) this, _wce.instance, this);
        			
        		if (window == Window.NULL) {
        			MessageBox.error ("Create listbox failed");
        			return;
			}
			
			initialize_items ();
		}
		
		public virtual int selected_index
		{
			get {
				var res = (int)window.send_message (ListBoxMsg.GETCURSEL, (WParam) 0, (LParam) 0);
				if (res == ListBoxMsg.ERR)
					return -1;
					
				return res;
			}
		}
	
		public ListItem add_item (string text, void* data = null)
		{
			var item = new ListItem ();
			item.text = text;
			item.data = data;
			items.append (item);
			add_item_to_list (item);
			return item;
		}
		
		public ListItem remove_item (int index)
		{
			var item = items.nth_data (index);
			if (item != null)
				remove_item_from_list (index);
				
			items.remove (item);
			return item;
		}
		
		protected void initialize_items ()		
		{
			foreach (ListItem item in items) {
				add_item_to_list (item);
			}
		}
		
		protected virtual void add_item_to_list (ListItem item)
		{
			int index = (int)window.send_message (ListBoxMsg.ADDSTRING, (WParam) 0, (LParam) StringW.from_string (item.text));
			window.send_message (ListBoxMsg.SETITEMDATA, (WParam) index, (LParam) item);
		}
		
		protected virtual void remove_item_from_list (int index)
		{
			window.send_message (ListBoxMsg.DELETESTRING, (WParam) index, (LParam) 0);
		}
	}
}

