### Introduction ###

Compiling ValaCE it isn't an easy task, but even not a very difficult one. You'll need to be familiar with the cegcc compiler and you'll need some time.

I tried to automate as much as possible, but there are some manual step that need to be done.

You may ask why?

These are some reasons:

  1. I'm not very good when dealing with GLib automake "pretty complex" build scripts
  1. I lack the time and knowledge to do a better work
  1. My GLib port is partial and was done with an "axe", not with a bistury!

In the source root directory there is a script called **build-all** that should do most of the work.

### Required tools ###

To compile ValaCE you need:

  1. mingw32ce flavour of the CE Gcc compiler: http://cegcc.sourceforge.net/
  1. the Vala compiler: http://live.gnome.org/Vala
  1. time & patience

### Build procedure ###

First edit the **mingw32ce.sh** file present in the root folder to reflect you installation (I installed mingw32ce under ~/opt/mingw32ce/)

Then do:

`$source mingw32ce.sh`

and finally:

`$./build-all`

If all goes well you should have the GLib / GObject library built under the _glibce_ folder and the vforms library with some example programs under the _valaforms_ folder.

It's now time to do a

`$make install`

and all the headers and libraries will be installed under the _wince_ folder of the source distribution.