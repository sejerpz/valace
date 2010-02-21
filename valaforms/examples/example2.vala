/* A simple form with a button */

using VForms;
using Windows;

public class MyForm : VForms.Form
{
	public MyForm ()
	{
		this.with_text ("");
	}

	public MyForm.with_text (string text)
	{
		base.with_text (text);
		initialize_components ();
	}

	private void initialize_components ()
	{
		this.size = Size () { width = 240, height = 320 };
		
		ButtonBase button = new Button.with_text ("Click Me!");
		button.location = Point () { x = 20, y = 20 };
		button.size = Size () { width = 200, height = 100 };
		button.clicked.connect (on_button_quit);
		this.controls.append (button);
	}
	
	protected void on_button_quit (Control sender)
	{
		MessageBox.show ("Bye bye!", "ValaCE");
		close ();
	}
	
	protected override void on_destroy ()
	{
		loop_quit ();
	}
}

static int WinMain(Instance instance, Instance prev_instance, StringW? args, int show_mode)
{
	VForms.init (instance);
	var my_form = new MyForm.with_text ("ValaCE");
	my_form.show ();
	my_form.update ();
	return VForms.loop_run ();
}
