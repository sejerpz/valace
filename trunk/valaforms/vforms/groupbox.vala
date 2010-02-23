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
	public class GroupBox : Container
	{
		protected Window groupbox_window = Window.NULL;
		
		public GroupBox ()
		{
			this.with_text ("");
		}
		
		public GroupBox.with_text (string text)
		{
			_text = text;
		}
		
		internal override void create_children_controls ()
		{
			base.create_children_controls ();
			
			// last window created is the GroupBox Button
			groupbox_window = Window.create (
				0,
				WindowClass.BUTTON, 
				StringW.from_string (text),
				WindowStyle.VISIBLE | WindowStyle.CHILD | ButtonStyle.GROUPBOX,
				(int) 0,
				(int) 0,
				size.width, 
				size.height,
        			this.window, (Menu) ((int) this + 1), _wce.instance, null);
        			
        		//MessageBox.show ("groubox %d".printf((int)groupbox_window));
		}
		
		public override bool enabled
		{
			get {
				return base.enabled;
			}
			set {
				base.enabled = value;
				if (groupbox_window != Window.NULL) {
					groupbox_window.enable (_enabled);
				}
			}
		}
	}

}
