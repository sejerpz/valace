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
	public class CheckBox : ButtonBase
	{
		protected bool _checked = false;
		
		public bool checked
		{
			get {
				if (is_handle_created) {
					_checked = ((int)window.send_message (ButtonMsg.GETCHECK, (WParam) 0, (LParam) 0)) == ButtonStatus.CHECKED;
				}
				return _checked;
			}
			set {
				_checked = value;
				if (is_handle_created) {
					window.send_message (ButtonMsg.SETCHECK, (WParam) (_checked ? ButtonStatus.CHECKED : ButtonStatus.UNCHECKED), (LParam) 0);
				}
			}
		}
		public CheckBox ()
		{
			this.with_text ("");
		}
		
		public CheckBox.with_text (string text)
		{
			base.with_text (text);
		}
	}
}
