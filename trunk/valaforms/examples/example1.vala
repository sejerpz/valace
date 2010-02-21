/* first simple example */

using VForms;
using Windows;

static int WinMain(Instance instance, Instance prev_instance, StringW? args, int show_mode)
{
	VForms.init (instance);
	MessageBox.show ("Hello ValaCE!", "ValaCE Example");
	return 0;
}
