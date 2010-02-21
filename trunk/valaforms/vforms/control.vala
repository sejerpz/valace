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
	public class Control : GLib.Object
	{
		/* Signals */
		public signal void closed ();
		public signal void destroyed ();
		
		public Point location = Point ();
		public Size size = Size ();
		
		protected string _text = null;
		public Window window = Window.NULL;
		public bool is_dialog = false;
		public List<Control> controls = new List<Control> ();		
		public Control parent = null;
		
		public bool is_handle_created
		{
			get {
				return window != Window.NULL;
			}
		}
		
		public string text
		{
			get {
				if (is_handle_created) {
					int len = window.get_text_lenght ();	
					char[] buff = new char[len * 2 + 1];
					window.get_text (buff);
					_text = ((StringW)buff).to_string ();
				}
				return _text;
			}
			set {
				_text = value;
				if (is_handle_created) {
					window.set_text (StringW.from_string (_text));
				}
			}
			
		}
		public virtual int process_message (Window win, uint msg_id, WParam w_param, LParam l_param, ref bool processed)
		{
			int result = 0;
			switch (msg_id) {
				case MessageId.CLOSE:
					on_close ();
					processed = true;
					break;
				case MessageId.DESTROY:
					on_destroy ();
					processed = true;
					break;
			}
			
			return result;
		}
		
		public Control? find_from_window (Window data)
		{
			if (window == data)
				return this;
				
			foreach (Control child in controls) {
				var result = child.find_from_window (data);
				if (result != null)
					return result;
			}
			
			return null;
		}
		
		protected virtual void on_close ()
		{
			closed ();	
		}
		
		protected virtual void on_destroy ()
		{
			destroyed ();
		}
		
		public virtual void create_control ()
		{
		}

		public bool update ()
		{
			if (!is_handle_created)
				create_control ();

			return window.update ();
		}
		
		public bool show ()
		{
			if (!is_handle_created) {
				create_control ();
				return window.show (ShowCommand.SHOWNORMAL);
			} else {
				return window.show (ShowCommand.SHOW);
			}
		}
		
		public virtual void hide ()
		{
			if (is_handle_created)
				window.show (ShowCommand.HIDE);
		}
		
		public virtual void destroy ()
		{
			window.destroy ();
		}
		
		internal virtual void create_children_controls ()
		{
			Control container = this;
			while (container != null && !(container is Container))
				container = container.parent;
				
			foreach (Control control in controls) {
				if (!control.is_handle_created) {
					control.parent = container; /* TODO: implement observable collection */
					control.create_control ();
				}
			}
		}
	}
}
