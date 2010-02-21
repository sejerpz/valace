NULL = 

AUTOMAKE_OPTIONS = subdir-objects

SUBDIRS = \
	$(NULL)

AM_CPPFLAGS = \
	$(VFORMS_CFLAGS) \
	-DPACKAGE_DATADIR=\""$(pkgdatadir)"\" \
	-I $(top_srcdir)/glibce/ \
	-I $(top_srcdir)/glibce/glib \
	-I $(top_srcdir)/glibce/gobject \
	-I ../vforms/ \
	-include $(CONFIG_HEADER) \
	$(NULL)

BUILT_SOURCES = example1.vala.stamp \
	example-all.vala.stamp \
	$(NULL)

noinst_PROGRAMS = example1 \
	example-all \
	$(NULL)

##########################################################
# Example 1
##########################################################

example1_VALASOURCES = \
	example1.vala \
	$(NULL)


example1_SOURCES = \
	example1.vala.stamp \
	$(example1_VALASOURCES:.vala=.c) \
	$(NULL)

example1.vala.stamp: $(example1_VALASOURCES)
	$(VALAC) $(DEBUG) -C --vapidir ../../vapi --vapidir ../vforms --pkg vforms-1.0 --pkg config --pkg windows $(example1_VALASOURCES) 
	touch $@

example1_LDFLAGS = \
	-L$(top_srcdir)/valaforms/vforms \
	-L$(top_srcdir)/glibce/gthread/ \
	-L$(top_srcdir)/glibce/glib/ \
	-L$(top_srcdir)/glibce/gobject/ \
	$(NULL)

example1_LDADD = \
	-lvforms \
	-lglibce-2.0 \
	-lgobject-2.0 \
	-lgthread-2.0 \
	$(NULL)

##########################################################
# Example ALL
##########################################################

example_all_VALASOURCES = \
	example-all.vala \
	$(NULL)


example_all_SOURCES = \
	example-all.vala.stamp \
	$(example_all_VALASOURCES:.vala=.c) \
	$(NULL)

example-all.vala.stamp: $(example_all_VALASOURCES)
	$(VALAC) $(DEBUG) -C --vapidir ../../vapi --vapidir ../vforms --pkg vforms-1.0 --pkg config --pkg windows $(example_all_VALASOURCES) 
	touch $@

example_all_LDFLAGS = \
	-L$(top_srcdir)/valaforms/vforms \
	-L$(top_srcdir)/glibce/gthread/ \
	-L$(top_srcdir)/glibce/glib/ \
	-L$(top_srcdir)/glibce/gobject/ \
	$(NULL)

example_all_LDADD = \
	-lvforms \
	-lglibce-2.0 \
	-lgobject-2.0 \
	-lgthread-2.0 \
	$(NULL)


##########################################################

EXTRA_DIST = \
	$(example1_VALASOURCES) \
	example1.vala.stamp \
	$(NULL)

DISTCLEANFILES = \
	$(NULL)

MAINTAINERCLEANFILES = \
	$(example1_VALASOURCES:.vala=.c) \
	$(NULL)

