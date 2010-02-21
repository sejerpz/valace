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
	public abstract class ButtonBase : Control
	{
		public signal void clicked ();
		
		public ButtonBase ()
		{
			this.with_text ("");
		}
		
		public ButtonBase.with_text (string text)
		{
			_text = text;
		}
		
		public override void create_control ()
		{
			int button_style = ButtonStyle.PUSHBUTTON;
			
			if (this.get_type () == typeof(Button)) {
				button_style = ButtonStyle.PUSHBUTTON;
			} else if (this.get_type () == typeof(CheckBox)) {
				button_style = ButtonStyle.AUTOCHECKBOX;
			} else {
				button_style = ButtonStyle.AUTORADIOBUTTON;
			}
			
			window = Window.create (
				0,
				WindowClass.BUTTON, 
				StringW.from_string (text),
				WindowStyle.VISIBLE | WindowStyle.TABSTOP | WindowStyle.CHILD | button_style,
				(int) location.x,
				(int) location.y,
				size.width, 
				size.height,
        			parent.window, (Menu) this, _wce.instance, this);
        			
        		if (window == Window.NULL) {
        			MessageBox.error ("Create button failed");
			}
		}
		
				
		public override int process_message (Window win, uint msg_id, WParam w_param, LParam l_param, ref bool processed)
		{
			int result = 0;
			switch (msg_id) {
				case MessageId.COMMAND:
					on_click ();
					processed = true;
					break;
				default:
					result = base.process_message (win, msg_id, w_param, l_param, ref processed);
					break;
			}
			
			return result;
		}
		
		protected void on_click ()
		{
			this.clicked ();
		}
	}
}
