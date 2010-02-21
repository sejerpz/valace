using GLib;
using Windows;

namespace VForms
{



	

	

	
	


	

	


	

	
	public class Button : ButtonBase
	{
		public Button ()
		{
			this.with_text ("");
		}
		
		public Button.with_text (string text)
		{
			base.with_text (text);
		}

	}
	
	public class TreeView : Control
	{
		
	}
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
	}
	
	public class RadioButton : ButtonBase
	{
		public RadioButton ()
		{
			this.with_text ("");
		}
		
		public RadioButton.with_text (string text)
		{
			base.with_text (text);
		}

	}

	public class CheckBox : ButtonBase
	{
		public CheckBox ()
		{
			this.with_text ("");
		}
		
		public CheckBox.with_text (string text)
		{
			base.with_text (text);
		}		
	}
	
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
	
	public class TextBox : Control
	{
		public signal void clicked ();
		
		public TextBox ()
		{
			this.with_text ("");
		}
		
		public TextBox.with_text (string text)
		{
			_text = text;
		}
		
		public override void create_control ()
		{
			window = Window.create (
				WindowStyleEx.STATICEDGE,
				WindowClass.EDIT, 
				StringW.from_string (text),
				WindowStyle.VISIBLE | WindowStyle.CHILD | EditStyle.LEFT,
				(int) location.x,
				(int) location.y,
				size.width, 
				size.height,
        			parent.window, (Menu) this, _wce.instance, this);
        			
        		if (window == Window.NULL) {
        			MessageBox.error ("Create button failed");
			}
		}
	}
	
	public class Label : Control
	{
		public signal void clicked ();
		
		public Label ()
		{
			this.with_text ("");
		}
		
		public Label.with_text (string text)
		{
			_text = text;
		}
		
		public override void create_control ()
		{
			window = Window.create (
				0,
				WindowClass.STATIC, 
				StringW.from_string (text),
				WindowStyle.VISIBLE | WindowStyle.CHILD | EditStyle.LEFT,
				(int) location.x,
				(int) location.y,
				size.width, 
				size.height,
        			parent.window, (Menu) this, _wce.instance, this);
        			
        		if (window == Window.NULL) {
        			MessageBox.error ("Create label failed");
			}
		}
	}
	
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
