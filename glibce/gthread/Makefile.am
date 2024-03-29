## Process this file with automake to produce Makefile.in
include $(top_srcdir)/Makefile.decl

SUBDIRS = .
#DIST_SUBDIRS = tests

#@GTHREAD_COMPILE_IMPL_DEFINES@ 	\
#@GLIB_DEBUG_FLAGS@ 		


AM_CPPFLAGS = 				\
	-I$(top_srcdir) 		\
	-I$(top_srcdir)/glib 		\
	-I$(top_srcdir)/gthread 	\
	-DG_LOG_DOMAIN=\"GThread\" 	\
	-DG_DISABLE_DEPRECATED

EXTRA_DIST +=				\
		makefile.msc.in		\
		gthread-posix.c		\
		gthread-win32.c		\
		gthread-none.c		\
		gthread.def		\
		gthread.rc.in

BUILT_EXTRA_DIST = 			\
		makefile.msc		\
		gthread.rc

libglib = $(top_builddir)/glib/libglibce-2.0.la

top_builddir_full=`cd \$(top_builddir); pwd`

lib_LTLIBRARIES = libgthread-2.0.la

if OS_WIN32_AND_DLL_COMPILATION
if MS_LIB_AVAILABLE
noinst_DATA = gthread-2.0.lib

install_ms_lib_cmd = $(INSTALL) gthread-2.0.lib $(DESTDIR)$(libdir)
uninstall_ms_lib_cmd = -rm $(DESTDIR)$(libdir)/gthread-2.0.lib
endif
endif

install-ms-lib:
	$(install_ms_lib_cmd)

uninstall-ms-lib:
	$(uninstall_ms_lib_cmd)

if PLATFORM_WIN32
no_undefined = -no-undefined
endif

if OS_WIN32_AND_DLL_COMPILATION
export_symbols = -export-symbols $(srcdir)/gthread.def
gthread_def = gthread.def

install-def-file:
	$(INSTALL) $(srcdir)/gthread.def $(DESTDIR)$(libdir)/gthread-2.0.def

uninstall-def-file:
	-rm $(DESTDIR)$(libdir)/gthread-2.0.def
else
install-def-file:
uninstall-def-file:
endif

if OS_WIN32_AND_DLL_COMPILATION
gthread_win32_res = gthread-win32-res.o
gthread_win32_res_ldflag = -Wl,$(gthread_win32_res)
endif

libgthread_2_0_la_SOURCES = gthread-impl.c
libgthread_2_0_la_LDFLAGS = \
	$(gthread_win32_res_ldflag) \
	-version-info 2:0:0 \
	-export-dynamic $(no_undefined) $(export_symbols)

#$(gthread_win32_res_ldflag) \
#-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
#-export-dynamic $(no_undefined) $(export_symbols)

libgthread_2_0_la_LIBADD = $(G_THREAD_LIBS_EXTRA) $(G_THREAD_LIBS_FOR_GTHREAD) $(libglib)

libgthread_2_0_la_DEPENDENCIES = $(gthread_win32_res) $(gthread_def)

gthread-win32-res.o: gthread.rc
	$(WINDRES) gthread.rc $@

gthread-2.0.lib: libgthread-2.0.la gthread.def
	lib -machine:@LIB_EXE_MACHINE_FLAG@ -name:libgthread-2.0-$(LT_CURRENT_MINUS_AGE).dll -def:$(srcdir)/gthread.def -out:$@

dist-hook: $(BUILT_EXTRA_DIST)
	files='$(BUILT_EXTRA_DIST)'; \
	for f in $$files; do \
	  if test -f $$f; then d=.; else d=$(srcdir); fi; \
	  cp $$d/$$f $(distdir) || exit 1; done

install-data-local: install-ms-lib install-def-file

uninstall-local: uninstall-ms-lib uninstall-def-file

if HAVE_GLIB_RUNTIME_LIBDIR
install-data-hook:
	mkdir -p $(DESTDIR)$(libdir)/$(GLIB_RUNTIME_LIBDIR)
	mv $(DESTDIR)$(libdir)/libgthread-2.0.so.0 $(DESTDIR)$(libdir)/$(GLIB_RUNTIME_LIBDIR)
	mv $(DESTDIR)$(libdir)/libgthread-2.0.so.0.$(LT_CURRENT).$(LT_REVISION) $(DESTDIR)$(libdir)/$(GLIB_RUNTIME_LIBDIR)
	rm -f $(DESTDIR)$(libdir)/libgthread-2.0.so
	ln -s $(GLIB_RUNTIME_LIBDIR)/libgthread-2.0.so.0.$(LT_CURRENT).$(LT_REVISION) $(DESTDIR)$(libdir)/libgthread-2.0.so
endif
