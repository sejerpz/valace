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
	public static int loop_run ()
	{
		Message msg = Message ();
		
		while(MessageLoop.get_message(msg) > 0)
		{
			MessageLoop.translate_message(msg);
			MessageLoop.dispatch_message(msg);
		}
    		return (int)msg.wParam;
	}
	
	public static void loop_quit (int code = 0)
	{
		MessageLoop.post_quit_message (code);
	}
}
