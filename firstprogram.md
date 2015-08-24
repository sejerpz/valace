# Introduction #

So you have installed ValaCE and you want use it? Let's go and write a simple Vala program with ValaForms a.k.a. VForms.

**Important Note** You can find all the required files (precompiled binaries and example source) in the valace-runtime-preview archive.

# Project structure #

If you followed the Compile instruction you should ended with a copy of all the required library and headers installed in the _wince_ subfolder, so now you just need to create a simple folder to store your first program.

Just do a:

`mkdir valace-example1`

and create there a simple file called **Makefile** with the following content:
```
###########################################################
# Simple Makefile for ValaForms
###########################################################

WORKING_DIR=$(shell pwd)

# Installation directory of the CE-GCC compiler
MINGW_PATH= ${HOME}/opt/mingw32ce

# Installation directory of ValaCE
VALACE_PATH= ${WORKING_DIR}/../wince

############################################################
VAPIDIR= ${VALACE_PATH}/share/valace/vapi
GLIB_INCLUDE = ${VALACE_PATH}/include/glibce-2.0
GOBJECT_INCLUDE = ${VALACE_PATH}/include/glibce-2.0/glib
VFORMS_INCLUDE = ${VALACE_PATH}/include/vforms-1.0

LD_DIR = ${VALACE_PATH}/lib

ARCH= arm-mingw32ce
CFLAGS= -g -D_WIN32_IE=0x0400 -I ${GOBJECT_INCLUDE} -I ${GLIB_INCLUDE} -I ${VFORMS_INCLUDE} -L${LD_DIR}
LIBS = -lvforms -lglibce-2.0 -lgobject-2.0 -lgthread-2.0 -lcommctrl
CC= ${ARCH}-gcc ${CFLAGS}

example1.exe: example1.c
	${CC} -o $@ $? ${LIBS}

example1.c: example1.vala
	valac -C --vapidir ${VAPIDIR} --pkg windows --pkg vforms-1.0 $?

clean:
	-rm -f *.c *.o *.exe
	-rm -rf deploy-dir

deploy: example1.exe
	./ce-deploy example1.exe

```


Before continuing please check and adjust these two variables according to yours installations paths

```
# Installation directory of the CE-GCC compiler
MINGW_PATH= ${HOME}/opt/mingw32ce

# Installation directory of ValaCE
VALACE_PATH= ${WORKING_DIR}/../wince
```

# Program source #

Now create and edit a vala source with the name **example1.vala** always inside the same folder.

This is the program source

```
/* first simple example */

using VForms;
using Windows;

static int WinMain(Instance instance, Instance prev_instance, StringW? args, int show_mode)
{
	VForms.init (instance);
	MessageBox.show ("Hello ValaCE!", "ValaCE Example");
	return 0;
}
```

Compile it with _make_ and copy the required files to the device. If you want can modify the **ce-deploy** script found in the valaforms subfolder of the source distribution.


## Distribution ##

To copy all the required files from you PC to the target device I use the **synce-pcp** command that is part of the very good SynCE project http://www.synce.org/

I use a script like this (the actual version is _ce-deploy_ under the _valaforms_ folder of the source distribution)

```
#!/bin/sh
DEST_DIR=$2
if ["$DEST_DIR" = ""]; then
	DEST_DIR=":\Temp"
fi

rm -rf ./deploy-dir
mkdir ./deploy-dir

cp $MINGW32CE_PATH/bin/libgcc_s_sjlj-1.dll ./deploy-dir
cp ../glibce/glib/.libs/*.dll ./deploy-dir
cp ../glibce/gthread/.libs/*.dll ./deploy-dir
cp ../glibce/gobject/.libs/*.dll ./deploy-dir
cp $1 ./deploy-dir

../tools/upx-3.04-i386_linux/upx ./deploy-dir/*

synce-pcp ./deploy-dir/libgcc_s_sjlj-1.dll "$DEST_DIR"
synce-pcp ./deploy-dir/libgobject-2.0-0.dll "$DEST_DIR"
synce-pcp ./deploy-dir/libglibce-2.0-0.dll  "$DEST_DIR"
synce-pcp ./deploy-dir/libgthread-2.0-2.dll  "$DEST_DIR"
synce-pcp ./deploy-dir/`basename $1` "$DEST_DIR"
```

it's worth to note this line:

```
../tools/upx-3.04-i386_linux/upx ./deploy-dir/*
```

**The upx step isn't optional, it's required in order to fix a ceGcc dll bug.** Without compressing the dll you will always get and invalid executable message from Window CE!

Enjoy!