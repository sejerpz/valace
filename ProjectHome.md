The ValaCE project was born just as a proof of concept to see if
Vala could be used for developing Windows CE applications.

It was developed in a few nights and weekends and tested only on
my Htc phone so don't expect to be very complete or that it works
everywhere.

It consists of:

  * GLibCE`*`: a port of glib / gobject / gthread to Windows CE
  * windows.vapi: vala bindings to the Win32 C interface
  * valaforms: a simple library that wraps the Win32 UI controls in a more object oriented way.

`*`
**Take in mind that GLib was modified in order to support Windows CE and its porting is very incomplete. If you plan to use it in a C project consider that GLibCE port was done only to support the requirement of the GObject library and it's not very clean.**

## Download ##

Releases: http://code.google.com/p/valace/downloads/list

Source code repository: http://gitorious.org/valace/valace

## Contacts ##

Since ValaCE is very young I haven't setup any discussion group yet. I'll setup if and when it will be required, meanwhile if you want to contribute with code & fixes just use the google code issue tracker or if you want just  contact me wrote an email to this address:

sejerpz at tin dot it

## Where to start ##
Just looking around?
  * See the [example code](http://code.google.com/p/valace/wiki/examples)
  * See the [screenshots](http://code.google.com/p/valace/wiki/screenshots)

Want to write a program with ValaCE?

  * Download and Install the required tools as stated in the [Compile wiki page](http://code.google.com/p/valace/wiki/compile)
  * Download the valace-runtime-preview archive [valace-runtime-preview.tar.bz2](http://valace.googlecode.com/files/valace-runtime-preview.tar.bz2)
  * Then read this wiki page [my first program](http://code.google.com/p/valace/wiki/firstprogram)

Want to enhance the CE porting or ValaForms (VForms) library?
  * Start from here [compile](http://code.google.com/p/valace/wiki/compile)

## Why Vala? ##

Vala is a new object oriented language similar but not equal to C#
and it uses GLib and GObject for the foundation of its object type
system.

So Vala properties, classes interfaces and events can be just thought
as a nice and convenient syntax around the gobject capabilities.

The main advantage of Vala upon C# is that the code is compiled in
machine language and more over that you have a strict control on
the generated C interface and ABI.

Memory is automatically managed at compile time using reference counted
objects, this permits to still have a certain degree of control on
when allocate & deallocate it, but also free the developer to think
every time about leaks etc...

## For more informations ##

The Vala language:

> http://live.gnome.org/Vala

How memory management works in Vala:

> http://live.gnome.org/Vala/ReferenceHandling

GLib & GObjects.

> http://library.gnome.org/devel/gobject/stable/pt01.html
