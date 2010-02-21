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
	namespace MessageBox
	{
		public static void show (string message, string title = "")
		{
		        message_box (null, StringW.from_string (message), StringW.from_string (title)); //StringW.from_string (title));
		}
		
		internal static void error (string message)
		{
			int errno = (int)get_last_error();
			string errdes = GLib.Win32.error_message (errno);
			string error = "%s\r\n error code %d - %s".printf (message, errno, errdes);
			show (error);
		}
	}
}
