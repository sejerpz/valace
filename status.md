# Type system & Threading #

| Component | Status |
|:----------|:-------|
| GLib      | Minimal functionality supported, no intl and character set conversion fails most of the time |
| GThread   | Done   |
| GObject   | Done   |


# Vala Forms #

| Item | Description| Status | Notes |
|:-----|:-----------|:-------|:------|
| Control | Base class from which all other controls derive | Basic  | Very simple support for show / hide and text |
| Container | Base class from which all other containers derive | Intermediate | Support for grouping and control subcontrol creation |
| ButtonBase | Base class from which all other buttons derive | Basic  | Just the click event is supported |
| Button | Push button | Basic  | Nothing more than what is already present in ButtonBase |
| RadioButton | Radio button | Basic  | Nothing more than what is already present in ButtonBase |
| CheckBox | CheckBox button | Basic  | Nothing more than what is already present in ButtonBase |
| ListBox | Listbox control | Basic  | Adding & removing items, getting the current item |
| ComboBox | Combobox control | Basic  | Adding & removing items, getting the current item |
| TextBox | Textbox control | Basic  | getting and setting the text |
| GroupBox | GroupBox container | Basic  | Nothing more than what is already present in Container |
| Panel | Panel container | Basic  | Nothing more than what is already present in Container |
| TabPage | TabControl page container | Basic  | Nothing more than what is already present in Container |
| TabControl | TabControl aka Notebook container | Basic  | Adding & removing pages |