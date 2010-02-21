## Process this file with automake to produce Makefile.in

#if HAVE_GCC_BUILTINS_FOR_ATOMIC_OPERATIONS
#gatomic_c = gatomic-gcc.c
#else
gatomic_c = gatomic.c
#endif

SUBDIRS = libcharset .

DIST_SUBDIRS = libcharset . 

AM_CPPFLAGS = 				\
	-I$(top_srcdir) 		\
	-DG_LOG_DOMAIN=\"GLib\" 	\
	-static-libgcc			\
	$(GLIB_DEBUG_FLAGS) 		\
	-DG_DISABLE_DEPRECATED 		\
	-DGLIB_COMPILATION 		\
	-DPCRE_STATIC

glib.def: glib.symbols
	(echo -e EXPORTS; $(CPP) -P -DINCLUDE_VARIABLES -DINCLUDE_INTERNAL_SYMBOLS -DG_OS_WIN32 -DALL_FILES - <$(srcdir)/glib.symbols | sed -e '/^$$/d' -e 's/^/	/' -e 's/G_GNUC_[^ ]*//g') > glib.def

galias.h: glib.symbols
	  $(PERL) $(srcdir)/makegalias.pl < $(srcdir)/glib.symbols > galias.h

galiasdef.c: glib.symbols
	  $(PERL) $(srcdir)/makegalias.pl -def < $(srcdir)/glib.symbols > galiasdef.c


BUILT_SOURCES = galias.h galiasdef.c

# These may be in the builddir too
BUILT_EXTRA_DIST = 		\
	makefile.msc		\
	glib.rc			\
	galias.h		\
	galiasdef.c

lib_LTLIBRARIES = libglibce-2.0.la

if OS_WIN32_AND_DLL_COMPILATION
if MS_LIB_AVAILABLE
noinst_DATA = glib-2.0.lib

install_ms_lib_cmd = $(INSTALL) glib-2.0.lib $(DESTDIR)$(libdir)
uninstall_ms_lib_cmd = -rm $(DESTDIR)$(libdir)/glib-2.0.lib
endif
endif

install-ms-lib:
	$(install_ms_lib_cmd)

uninstall-ms-lib:
	$(uninstall_ms_lib_cmd)

libglibce_2_0_la_SOURCES = 	\
        garray.c \
	$(gatomic_c)		\
	ghook.c \
	gutf8.c \
	gconvert.c \
	gtestutils.c \
	gmessages.c \
	giochannel.c \
	gdate.c \
        gdataset.c \
	glist.c \
        gslice.c \
        gstrfuncs.c \
        gslist.c \
        gmem.c \
        gerror.c \
        galiasdef.c \
        gthread.c \
        gmain.c \
        gqsort.c \
        gprintf.c \
        ghash.c \
        gstring.c \
        gutils.c
        

EXTRA_libglibce_2_0_la_SOURCES = \
	gwin32.c

glibceincludedir=$(includedir)/glibce-2.0
glibceinclude_HEADERS =   \
	glib.h

glibcesubincludedir=$(includedir)/glibce-2.0/glib
glibcesubinclude_HEADERS =   \
	gtypes.h \
	../glibconfig.h \
	glib-object.h \
	gdebug.h \
	gtestutils.h \
	gbacktrace.h \
	gconvert.h \
	gscanner.h \
	gunicode.h \
	gpoll.h \
	gmacros.h \
        garray.h \
	gatomic.h	\
	gmessages.h \
	galloca.h \
	giochannel.h \
	gquark.h \
	ghook.h \
	glist.h \
	gdate.h \
        gdataset.h \
        gslice.h \
        gstrfuncs.h \
        gslist.h \
        gmem.h \
        gerror.h \
        gwin32.h \
        gthread.h \
        gmain.h \
        gqsort.h \
        gprintf.h \
        ghash.h \
        gstring.h \
        gutils.h

install-data-local: install-ms-lib install-def-file
	@if test -f $(glibceincludedir)/glist.h ; then					\
	  echo "*** Old headers found in $(glibincludedir). You should remove the" ;	\
	  echo "*** contents of this directory and type 'make install' again." ;	\
	  false ;									\
        fi

uninstall-local: uninstall-ms-lib uninstall-def-file

if PLATFORM_WIN32
no_undefined = -no-undefined
endif

if OS_WIN32_AND_DLL_COMPILATION
export_symbols = -export-symbols glib.def

glibce_win32_res = glib-win32-res.o
glibce_win32_res_ldflag = -Wl,$(glib_win32_res)

glibce_def = glib.def

install-def-file:
	$(INSTALL) glib.def $(DESTDIR)$(libdir)/glibce-2.0.def

uninstall-def-file:
	-rm $(DESTDIR)$(libdir)/glibce-2.0.def
else
install-def-file:
uninstall-def-file:

export_symbols = $(LIBTOOL_EXPORT_OPTIONS)
endif

libglibce_2_0_la_LIBADD =  libcharset/libcharset.la $(printf_la) @PLATFORMDEP@ @G_LIBS_EXTRA@ $(pcre_lib)
libglibce_2_0_la_DEPENDENCIES = $(printf_la) @PLATFORMDEP@ $(glib_win32_res) $(glib_def)

libglibce_2_0_la_LDFLAGS = \
	 $(glib_win32_res_ldflag) \
	-static-libgcc \
	-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
	-export-dynamic $(no_undefined) $(export_symbols)

INSTALL_PROGS=

glib-win32-res.o: glib.rc
	$(WINDRES) glib.rc $@

bin_PROGRAMS	 = ${INSTALL_PROGS}

glibce-2.0.lib: libglib-2.0.la glib.def
	lib -machine:@LIB_EXE_MACHINE_FLAG@ -name:libglib-2.0-$(LT_CURRENT_MINUS_AGE).dll -def:glib.def -out:$@

dist-hook: $(BUILT_EXTRA_DIST)
	files='$(BUILT_EXTRA_DIST)'; \
	for f in $$files; do \
	  if test -f $$f; then d=.; else d=$(srcdir); fi; \
	  cp $$d/$$f $(distdir) || exit 1; done

distclean-local:
	if test $(srcdir) = .; then :; else \
	    rm -f libglib-gdb.py; \
	fi
