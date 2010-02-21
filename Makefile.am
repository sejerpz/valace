NULL = 

#Build in these directories:

SUBDIRS = \
	glibce \
	valaforms \
	$(NULL)

valace_DATA = \
	vapi/windows.vapi \
	$(NULL)

valacedir = ${prefix}/share/valace/vapi

valacedocdir = ${prefix}/doc/valace

valacedoc_DATA = \
	ChangeLog \
	README \
	COPYING \
	AUTHORS \
	INSTALL \
	NEWS\
	$(NULL)

EXTRA_DIST = \
	$(valacedoc_DATA) \
	intltool-extract.in \
	intltool-merge.in \
	intltool-update.in\
	$(NULL)

DISTCLEANFILES = \
	intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache \
	$(NULL)

