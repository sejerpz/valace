NULL = 

AUTOMAKE_OPTIONS = subdir-objects

SUBDIRS = \
	$(NULL)

AM_CPPFLAGS = \
	$(VFORMS_CFLAGS) \
	-DPACKAGE_DATADIR=\""$(pkgdatadir)"\" \
	-D_WIN32_IE=0x0400 \
	-include $(CONFIG_HEADER) \
	-I $(top_srcdir)/glibce/ \
	-I $(top_srcdir)/glibce/glib/ \
	-I $(top_srcdir)/glibce/gobject/ \
	$(NULL)

BUILT_SOURCES = libvforms.vala.stamp

lib_LTLIBRARIES = libvforms.la

libvforms_la_VALASOURCES = \
	buttonbase.vala \
	button.vala \
	checkbox.vala \
	combobox.vala \
	container.vala \
	control.vala \
	form.vala \
	groupbox.vala \
	init.vala \
	label.vala \
	listbox.vala \
	listitem.vala \
	messagebox.vala \
	messageloop.vala \
	panel.vala \
	radiobutton.vala \
	size.vala \
	tabcontrol.vala \
	tabpage.vala \
	textbox.vala \
	$(NULL)


libvformsincludedir = $(includedir)/vforms-1.0

libvformsinclude_HEADERS = \
	vforms.h \
	$(NULL)


libvforms_la_SOURCES = \
	libvforms.vala.stamp \
	$(libvforms_la_VALASOURCES:.vala=.c) \
	$(NULL)

libvforms.vala.stamp: $(libvforms_la_VALASOURCES) ../../vapi/windows.vapi
	$(VALAC) $(DEBUG) -C -H vforms.h --library vforms-1.0 --vapidir ../../vapi --pkg config --pkg windows --basedir $(top_srcdir)/valaforms $(libvforms_la_VALASOURCES)
	touch $@

libvforms_la_LDFLAGS = \
	-version-info 0:1:0 \
	-L$(top_srcdir)/glibce/gthread/ \
	-L$(top_srcdir)/glibce/glib/ \
	-L$(top_srcdir)/glibce/gobject/ \
	$(NULL)

libvforms_la_LIBADD = \
	$(VFORMS_LIBS) \
	-lcommctrl \
	-lglibce-2.0 \
	-lgobject-2.0 \
	-lgthread-2.0 \
	$(NULL)


vformsvapi_DATA = \
	vforms-1.0.vapi \
	$(NULL)

vformsvapidir = ${prefix}/share/valace/vapi

EXTRA_DIST = \
	$(libvforms_la_VALASOURCES) \
	libvforms.vala.stamp \
	vforms-1.0.vapi \
	$(NULL)

DISTCLEANFILES = \
	$(NULL)

MAINTAINERCLEANFILES = \
	vforms-1.0.vapi \
	vforms.h \
	$(libvforms_la_VALASOURCES:.vala=.c) \
	$(NULL)

