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
	public class Form : Container
	{
		public Form ()
		{
			this.with_text ("");
		}
		
		public Form.with_text (string text)
		{
			_text = text;    		
		}
				
		public void close ()
		{
			destroy ();
		}
		
		public override void create_control ()
		{
			Window.create (WindowStyleEx.APPWINDOW | WindowStyleEx.CAPTIONOKBTN,
				"VFormsWindowClass", 
				StringW.from_string (text),
				WindowStyle.OVERLAPPEDWINDOW,
				(int)location.x,
				(int)location.y,
				size.width, 
				size.height,
        			Window.NULL, 0, _wce.instance, this);
			if (window == Window.NULL) {
        			MessageBox.error ("Create window failed");
			}	
		}
	}
}

