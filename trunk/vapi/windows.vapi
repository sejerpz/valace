/*
 * This file is part of ValaCE 
 *
 * Copyright (C) 2010 - Andrea Del Signore
 *
 * ValaCE is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * ValaCE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
 
[CCode (cprefix = "G")]
namespace GLib
{
	namespace TypeSystem
	{
		[CCode (cname = "g_type_init")]
		public static void init ();
	}

	namespace ThreadSystem
	{
		[CCode (cname = "g_thread_init")]
		public static void init (void* params = null);
	}
}

[CCode (cname="DWORD", default_value = "0U")]
[IntegerType (rank = 7)]
public struct DWord { }

[CCode (cname="long")]
[SimpleType]
public struct LResult { }

[CCode (cname="WPARAM")]
[SimpleType]
public struct WParam { }

[CCode (cname="LPARAM")]
[SimpleType]
public struct LParam { }

[CCode (cname="ATOM")]
[SimpleType]
[IntegerType (rank = 7)]
public struct Atom 
{
}

[CCode (cprefix="CP_")]
public enum CodePage
{
	UTF8,
}

[CCode (cprefix="WC_")]
[Flags]
public enum WideToMultiFlags
{
	COMPOSITECHECK,
	DISCARDNS,
	SEPCHARS,
	DEFAULTCHAR,
}

[Compact]
[Immutable]
[CCode (cname = "TCHAR", const_cname = "TCHAR", copy_function = "wcsdup", free_function = "free")]
public class StringW {
	public static StringW? from_string (string? data)
	{
		if (data == null)
			return null;
			
		int len = Windows.multi_byte_to_wide_char ( /* CP_UTF8 */ 65001, /* MB_PRECOMPOSED */ 0, data, -1, null);
		char[] msgw = new char[len * 2 + 1];
		Windows.multi_byte_to_wide_char ( /* CP_UTF8 */ 65001, /* MB_PRECOMPOSED */ 0, data, -1, msgw);
		return (StringW)msgw;
	}
	
	public string? to_string ()
	{
		int len = Windows.wide_char_to_multi_byte ( CodePage.UTF8, 0 /*WideToMultiFlags.COMPOSITECHECK*/, this, -1, null);
		if (len == 0) {
			int errno = (int)Windows.get_last_error ();
			string errdes = GLib.Win32.error_message (errno);
			string error = "%s\r\n error code %d - %s".printf ("Convert to UTF8 string", errno, errdes);
			Windows.message_box (null, StringW.from_string (error), null);
			return null;
		}
		var buff = new char[len + 1];
		Windows.wide_char_to_multi_byte ( CodePage.UTF8, 0 /*WideToMultiFlags.COMPOSITECHECK*/, this, -1, buff);
		return (string)buff;		
	}
}

[CCode (cheader_filename="windows.h")]
namespace Windows
{
	[CCode (cprefix="COLOR_")]
	public enum Color
	{
		WINDOW
	}

	[CCode (cprefix="CS_")]
	[Flags]
	public enum ClassStyle
	{
		DBLCLKS,
		HREDRAW,
		NOCLOSE,
		PARENTDC,
		VREDRAW
	}
	
	[CCode (cprefix="CW_")]
	public enum ClassWindowStyle
	{
		USEDEFAULT
	}
	
	[CCode (cprefix="WS_")]
	[Flags]
	public enum WindowStyle
	{
		BORDER,
		CAPTION,
		CHILD,
		CLIPCHILDREN,
		CLIPSIBLINGS,
		DISABLED,
		DLGFRAME,
		GROUP,
		HSCROLL,
		MAXIMIZEBOX,
		MINIMIZEBOX,
		OVERLAPPED,
		POPUP,
		POPUPWINDOW,
		SIZEBOX,
		SYSMENU,
		TABSTOP,
		THICKFRAME,
		VISIBLE,
		VSCROLL,
		OVERLAPPEDWINDOW = OVERLAPPED | CAPTION | SYSMENU | THICKFRAME | MINIMIZEBOX | MAXIMIZEBOX;
	}

	[CCode (cheader_filename = "commctrl.h")]
	namespace WindowClass
	{
		[CCode (cname="WC_BUTTON")]
		public const string BUTTON;
		[CCode (cname="WC_EDIT")]
		public const string EDIT;
		[CCode (cname="WC_STATIC")]
		public const string STATIC;
		[CCode (cname="WC_LINK")]
		public const string LINK;
		[CCode (cname="WC_COMBOBOXEX")]
		public const string COMBOBOXEX;
		[CCode (cname="WC_HEADER")]
		public const string HEADER;
		[CCode (cname="WC_IPADDRESS")]
		public const string IPADDRESS;
		[CCode (cname="WC_LISTVIEW")]
		public const string LISTVIEW;
		[CCode (cname="WC_TABCONTROL")]
		public const string TABCONTROL;
		[CCode (cname="WC_TREEVIEW")]
		public const string TREEVIEW;
		[CCode (cname="WC_PAGESCROLLER")]
		public const string PAGESCROLLER;
		[CCode (cname="WC_NATIVEFONTCTL")]
		public const string NATIVEFONTCTL;
		[CCode (cname="WC_LISTBOX")]
		public const string LISTBOX;
		[CCode (cname="WC_COMBOBOX")]
		public const string COMBOBOX;
		[CCode (cname="WC_SCROLLBAR")]
		public const string SCROLLBAR;
	}
	
	
	[CCode (cprefix="BS_")]
	[Flags]
	public enum ButtonStyle
	{
		DEFPUSHBUTTON,
		PUSHBUTTON,
		AUTORADIOBUTTON,
		AUTOCHECKBOX,
		GROUPBOX
	}
	
	[CCode (cprefix="ES_")]
	[Flags]
	public enum EditStyle
	{
		LEFT,
		AUTOSCROLL
	}
	
	[CCode (cprefix="WS_EX_")]
	public enum WindowStyleEx
	{
		ACCEPTFILES,
		CAPTIONOKBTN,
		CLIENTEDGE,
		CONTEXTMENU,
		DLGMODALFRAME,
		INK,
		LAYOUTRTL,
		LTRREADING,
		NOACTIVATE,
		NOANIMATION,
		NODRAG,
		NOINHERITLAYOUT,
		OVERLAPPEDWINDOW,
		PALETTEWINDOW,
		RTLREADING,
		STATICEDGE,
		TOOLWINDOW,
		TOPMOST,
		WINDOWEDGE,
		APPWINDOW,
		NOPARENTNOTIFY
	}
	
	[CCode (cname="int", cprefix="SW_")]
	public enum ShowCommand
	{
		SHOWNORMAL,
		HIDE,
		MAXIMIZE,
		MINIMIZE,
		RESTORE,
		SHOW,
	}
	
	[CCode (cprefix="IDI_")]
	public enum IconId
	{
		APPLICATION,
		ASTERISK,
		ERROR,
		EXCLAMATION,
		HAND,
		INFORMATION,
		QUESTION,
		WARNING,
		WINLOGO,
		SHIELD
	}
	
	[CCode (cprefix="GWLP_", cname="int")]
	public enum WindowLong
	{
		WNDPROC,
		HINSTANCE,
		ID,
		USERDATA
	}
	
	[CCode (cprefix="MB_", cname="intStringW")]
	public enum MessageBoxStyle
	{
		SETFOREGROUND
	}
	
	[CCode (cname="HINSTANCE")]
	[IntegerType (rank = 7)]
	public struct Instance { }

	[CCode (cname="HICON")]
	[IntegerType (rank = 7)]
	public struct Icon : Handle { }
	
	[CCode (cname="HCURSOR")]
	[IntegerType (rank = 7)]
	public struct Cursor : Handle { }

	[CCode (cname="HGDIOBJ")]
	[IntegerType (rank = 7)]
	public struct GDIObj : Handle { }
	
	[CCode (cname="HBRUSH")]
	[SimpleType]
	public struct Brush : Windows.Handle { }
	
	[CCode (cname="HANDLE")]
	[IntegerType (rank = 7)]
	public struct Handle 
	{ 
	}
	
	[CCode (cname="HMENU")]
	[IntegerType (rank = 7)]
	public struct Menu : Handle { }
	
	[CCode (cname="HWND",  has_copy_function = false, has_destroy_function = false)]
	[IntegerType (rank = 7)]
	public struct Window {
		[CCode (cname="NULL")]
		public static Window NULL;
		[CCode (cname="DestroyWindow")]
		public void destroy();
		
		[CCode (cname="CreateWindowEx", has_new_function= "false")]
		public static Window create (DWord dwExStyle, string lpClassName, StringW? lpWindowName, DWord dwStyle, int x, int y, int nWidth, int nHeight, Window hWndParent, Menu hMenu,Instance hInstance, void* lpParam);
		

		[CCode (cname="ShowWindow")]
		public bool show (ShowCommand cmdShow);
		
		[CCode (cname="UpdateWindow")]
		public bool update ();
		
		[CCode (cname="DefWindowProc")]
		public LResult def_window_proc (uint msg, WParam w_param, LParam l_param);

		[CCode (cname="SetWindowLongPtr")]		
		public uint set_long_ptr (WindowLong index, void* new_value);
		
		[CCode (cname="GetWindowLongPtr")]		
		public void* get_long_ptr (WindowLong index);
		
		[CCode (cname="SetWindowText")]
		public bool set_text (StringW text);
		
		[CCode (cname="GetWindowTextLength")]
		public int get_text_lenght ();
		
		[CCode (cname="GetWindowText")]
		public int get_text (char[] buff);
		
		[CCode (cname="GetWindowRect")]
		public bool get_rect (ref Rectangle rect);
		
		[CCode (cname="SendMessage")]
		public LResult send_message (uint msg_id, WParam wparam, LParam lparam);
		
		[CCode (cname="PostMessage")]
		public LResult post_message (uint msg_id, WParam wparam, LParam lparam);
	}
	
	[CCode (cname="POINT")]
	public struct Point {
		uint x;
		uint y;
	}

	[CCode (cname="strlen")]	
	static int strlen (string data);
	
	[CCode (cname="TEXT", cheader_filename="tchar.h")]
	static unowned StringW T(string data);

	[CCode (cname="MultiByteToWideChar")]
	static int multi_byte_to_wide_char (uint code_page, DWord flags, string data, int length, char[]? output);

	[CCode (cname="WideCharToMultiByte")]
	static int wide_char_to_multi_byte (CodePage code_page, WideToMultiFlags flags, StringW data, int length, char[]? output, char? default_char = null, bool use_default_char = false);

	[CCode (cname="MessageBoxW")]
	public static void message_box (Window? parent, StringW message, StringW? caption, MessageBoxStyle type = MessageBoxStyle.SETFOREGROUND);

	namespace Utils
	{
		[CCode (cname="ZeroMemory")]
		public static void zero_memory (void* memory, ulong size);
	}
		
	[CCode (cname="GetLastError")]
	public static DWord get_last_error ();
	
	[CCode (has_target = false, cname = "WNDPROC")]
	public delegate LResult wnd_proc (Window window, MessageId msg_id, WParam w_param, LParam l_param);

	[CCode (cname="WNDCLASS",  has_copy_function = false, has_destroy_function = false)]	
	public struct WndClass {
	    public uint style;
	    public wnd_proc lpfnWndProc;
	    public int cbClsExtra;
	    public int cbWndExtra;
	    public unowned Instance hInstance;
	    public unowned Icon hIcon;
	    public unowned Cursor hCursor;
	    public unowned Brush hbrBackground;
	    public StringW lpszMenuName;
	    public string lpszClassName;

	    [CCode (cname="RegisterClassW")]	    
	    public Atom register();
	    
	}
	
	[CCode (cprefix="WM_", cname="int")]
	public enum MessageId
	{
		CLOSE,
		DESTROY,
		CREATE,
		INITDIALOG,
		LBUTTONUP,
		COMMAND,
		PARENTNOTIFY,
		NOTIFY
	}
	
	[CCode (cprefix="LB_", cname="int")]
	public enum ListBoxMsg
	{
		ADDSTRING,
		DELETESTRING,
		GETITEMDATA,
		INSERTSTRING,
		SELECTSTRING,
		SETITEMDATA,
		GETCURSEL,
		ERR
	}

	[CCode (cprefix="CB_", cname="int")]
	public enum ComboBoxMsg
	{
		ADDSTRING,
		DELETESTRING,
		GETITEMDATA,
		INSERTSTRING,
		SELECTSTRING,
		SETITEMDATA,
		GETCURSEL,
		ERR
	}
	
	[CCode (cprefix="CBS_")]
	public enum ComboBoxStyle
	{
		DROPDOWNLIST
	}
	[CCode (cname="MSG")]
	public struct Message 
	{
		Window hwnd;
		MessageId message;
		WParam wParam;
		LParam lParam;
		DWord time;
		Point pt;
	}
	
	[CCode (cname="CREATESTRUCT")]
	public struct CreateStruct
	{
		void* lpCreateParams;
		Instance hInstance;
		Menu hMenu;
		Window hwndParent;
		int cy;
		int cx;
		int y;
		int x;
		long style;
		string lpszName;
		string lpszClass;
		DWord dwExStyle;
	}
	
	[CCode (cprefix="ICC_")]
	[Flags]
	public enum InitCommonControlsClass
	{
		ANIMATE_CLASS,
		BAR_CLASSES,
		CAPEDIT_CLASS,
		COOL_CLASSES,
		DATE_CLASSES,
		LISTVIEW_CLASSES,
		PROGRESS_CLASS,
		FE_CLASSES,
		TAB_CLASSES,
		TOOLTIP_CLASSES,
		TREEVIEW_CLASSES,
		UPDOWN_CLASS,
	}
	[CCode (cname="INITCOMMONCONTROLSEX")]
	public struct InitCommonControlsEx
	{
		DWord dwSize;
		DWord dwICC;
	}

	[CCode (cname="InitCommonControlsEx", cheader_filename = "commctrl.h")]
	public static bool init_common_controls_ex (InitCommonControlsEx init_ctrls);
	
	namespace MessageLoop 
	{
		[CCode (cname="GetMessage")]
		public static int get_message (Message msg, Window? window = null, uint wMsgFilterMin = 0, uint wMsgFilterMax = 0);
		[CCode (cname="TranslateMessage")]
		public static bool translate_message (Message msg);
		[CCode (cname="DispatchMessage")]
		public static LResult dispatch_message (Message msg);
		
		[CCode (cname="PostQuitMessage")]
		public static void post_quit_message (int exit_code);
	}
	
	[CCode (cprefix="")]
	public enum StockObjectId
	{
		WHITE_BRUSH
	}
	
	namespace StockObject 
	{
		[CCode (cname="GetStockObject")]
		GDIObj @get (StockObjectId id);
	}		

	[CCode (cname="TabCtrl_GetItemRect")]
	public bool get_item_rect (int index, ref Rectangle rectangle);
	
	[CCode (cname="RECT", has_copy_function = false, has_destroy_function = false)]
	public struct Rectangle { 
		long left;
		long top;
		long right;
		long bottom;
	}
	
	[CCode (cprefix = "TCN_")]
	public enum TabCtrlNotification
	{
		KEYDOWN,
		SELCHANGE,
		SELCHANGING
	}
	
	[CCode (cprefix = "TCIF_", cheader_filename="commctrl.h")]
	[Flags]
	public enum TabCtrlFlags
	{
		IMAGE,
		PARAM,
		RTLREADING,
		STATE,
		TEXT
	}
	
	[CCode (cname="TCITEM", has_copy_function = false, has_destroy_function = false)]
	public struct TabCtrlItem { 
		uint mask;
		DWord dwState;
		DWord dwStateMask;
		StringW pszText;
		int cchTextMax ;
		int iImage;
		LParam lParam;
	}

	[CCode (cname="HWND")]
	public struct TabCtrl : Window
	{
		[CCode (cname="TabCtrl_InsertItem")]
		public int insert_item (int index, TabCtrlItem item);
		
		[CCode (cname="TabCtrl_GetItemRect")]
		public bool get_item_rect (int index, ref Rectangle rectangle);
		
		[CCode (cname="TabCtrl_AdjustRect")]
		public bool adjust_rect (bool larger, ref Rectangle rectangle);
		
		[CCode (cname="TabCtrl_GetCurSel")]
		public int get_cur_sel ();
	}
	
	[CCode (cname="NMHDR", cheader_filename = "winuser.h")]
	public struct NotifyMessageHeader
	{ 
		Window hwndFrom; 
		uint idFrom; 
		uint code; 
	}
}
