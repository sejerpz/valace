// this was an hack
using VForms;
using Windows;

public class MyForm : VForms.Form
{
	private TextBox _text_box;
	private Label _label;
	private ListBox _list_box;
	private ComboBox _combo_box;
	private GroupBox _group_box;
	private int id_item;
	
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
		
		ButtonBase button = new Button.with_text ("Quit");
		button.location = Point () { x = 5, y = 235 };
		button.size = Size () { width = 225, height = 30 };
		button.clicked.connect (on_button_quit);
		this.controls.append (button);
		
		/*

		

		 
		button = new Button.with_text ("ClickMe");
		button.location = Point () { x = 145, y = 20 };
		button.size = Size () { width = 50, height = 50 };
		button.clicked.connect (on_button_clicked);
		panel.controls.append (button);
		 */
		 
		var tab = new TabControl ();
		tab.location = Point () { x = 5, y = 5 };
		tab.size = Size () { width = 225, height = 225 };
		this.controls.append (tab);
		
		var tab_page = new TabPage.with_text ("Buttons");
		tab.controls.append (tab_page);
		
		button = new CheckBox.with_text ("I'm a checkbox");
		button.location = Point () { x = 10, y = 1 };
		button.size = Size () { width = 200, height = 20 };
		button.clicked.connect (on_check_box_clicked);
		tab_page.controls.append (button);
 		
		_group_box = new GroupBox.with_text ("Some radio button here");
		_group_box.location = Point () { x = 10, y = 25 };
		_group_box.size = Size () { width = 200, height = 70 };
		tab_page.controls.append (_group_box);
	
		button = new RadioButton.with_text ("Radio button 1");
		button.location = Point () { x = 20, y = 20 };
		button.size = Size () { width = 170, height = 20 };
		button.clicked.connect (on_button_clicked);
		_group_box.controls.append (button);
		
		button = new RadioButton.with_text ("Radio button 2");
		button.location = Point () { x = 20, y = 40 };
		button.size = Size () { width = 170, height = 20 };
		button.clicked.connect (on_button_clicked);
		_group_box.controls.append (button);
		
		button = new Button.with_text ("Add");
		button.location = Point () { x = 10, y = 100 };
		button.size = Size () { width = 80, height = 40 };
		button.clicked.connect (on_button_combo_add_item_clicked);
		tab_page.controls.append (button);

		button = new Button.with_text ("Remove");
		button.location = Point () { x = 110, y = 100 };
		button.size = Size () { width = 80, height = 40 };
		button.clicked.connect (on_button_combo_remove_item_clicked);
		tab_page.controls.append (button);
		
		_combo_box = new ComboBox ();
		_combo_box.location = Point () { x = 10, y = 150 };
		_combo_box.size = Size () { width = 200, height = 40 };
		for (id_item = 0; id_item < 10; id_item++)
			_combo_box.add_item ("Item #%d".printf (id_item + 1));
		tab_page.controls.append (_combo_box);	
		
		tab_page = new TabPage.with_text ("More buttons");
		tab.controls.append (tab_page);
		
		button = new Button.with_text ("ClickMe!");
		button.location = Point () { x = 10, y = 90 };
		button.size = Size () { width = 80, height = 40 };
		button.clicked.connect (on_button_clicked);
		tab_page.controls.append (button);
		
		var panel = new Panel ();
		panel.location = Point () { x = 10, y = 5 };
		panel.size = Size () { width = 200, height = 80 };
		tab_page.controls.append (panel);

		var label = new Label.with_text ("Controls in a panel");
		label.location = Point () { x = 20, y = 2 };
		label.size = Size () { width = 200, height = 18 };
		panel.controls.append (label);
	
		button = new RadioButton.with_text ("Radio button 2-1");
		button.location = Point () { x = 20, y = 30 };
		button.size = Size () { width = 115, height = 20 };
		button.clicked.connect (on_button_clicked);
		panel.controls.append (button);

		button = new RadioButton.with_text ("Radio button 2-2");
		button.location = Point () { x = 20, y = 50 };
		button.size = Size () { width = 115, height = 20 };
		button.clicked.connect (on_button_clicked);
		panel.controls.append (button);
		
		tab_page = new TabPage.with_text ("Text && label");
		tab.controls.append (tab_page);
		
		_text_box = new TextBox.with_text ("Hello ValaCE!");
		_text_box.location = Point () { x = 10, y = 5 };
		_text_box.size = Size () { width = 200, height = 20 };
		tab_page.controls.append (_text_box);
		
		_label = new Label.with_text (_text_box.text);
		_label.location = Point () { x = 10, y = 35 };
		_label.size = Size () { width = 200, height = 20 };
		tab_page.controls.append (_label);

		button = new Button.with_text ("Add");
		button.location = Point () { x = 10, y = 60 };
		button.size = Size () { width = 80, height = 40 };
		button.clicked.connect (on_button_list_add_item_clicked);
		tab_page.controls.append (button);

		button = new Button.with_text ("Remove");
		button.location = Point () { x = 110, y = 60 };
		button.size = Size () { width = 80, height = 40 };
		button.clicked.connect (on_button_list_remove_item_clicked);
		tab_page.controls.append (button);
		
		_list_box = new ListBox ();
		_list_box.location = Point () { x = 10, y = 110 };
		_list_box.size = Size () { width = 200, height = 90 };
		for (id_item = 0; id_item < 10; id_item++)
			_list_box.add_item ("Item #%d".printf (id_item + 1));
		tab_page.controls.append (_list_box);	
	}

	private void on_check_box_clicked (Control sender)
	{
		var cb = sender as CheckBox;
		
		_group_box.enabled = cb.checked;
	}
		
	private void on_button_clicked (Control sender)
	{
		MessageBox.show ("button %s\r\n\n%s".printf (sender.text, _text_box.text), "VForms test!");
		_label.text = "label: %s".printf (_text_box.text);
	}

	private void on_button_list_add_item_clicked (Control sender)
	{
		_list_box.add_item ("%s #%d".printf (_text_box.text, id_item++));
	}
	
	private void on_button_list_remove_item_clicked (Control sender)
	{
		int sel = _list_box.selected_index;
		if (sel >= 0) {
			_list_box.remove_item (sel);
		}
	}
	
	private void on_button_combo_add_item_clicked (Control sender)
	{
		_combo_box.add_item ("%s #%d".printf (_text_box.text, id_item++));
	}
	
	private void on_button_combo_remove_item_clicked (Control sender)
	{
		int sel = _combo_box.selected_index;
		if (sel >= 0) {
			_combo_box.remove_item (sel);
		}
	}
	
	protected void on_button_quit (Control sender)
	{
		if (MessageBox.show ("Exit now?", "VForms test!", MessageBoxButtons.YESNO, MessageBoxIcon.QUESTION) == DialogResult.YES)
		{
			close ();
		}
	}
	
	protected override void on_destroy ()
	{
		loop_quit ();
	}
}

static int WinMain(Instance instance, Instance prev_instance, StringW? args, int show_mode)
{
	VForms.init (instance);
	var my_form = new MyForm.with_text ("VForm test!");
	my_form.show ();
	my_form.update ();
	return VForms.loop_run ();
}
