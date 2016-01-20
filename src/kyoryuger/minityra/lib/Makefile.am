bin_PROGRAMS = libminityra.so

libminityra_so_SOURCES = libminityra.c
libminityra_so_CPPFLAGS = -I@WIRINGPI_DIR@ -I./../../../common
libminityra_so_CFLAGS = -Wall -fPIC
libminityra_so_LDFLAGS = -shared -lwiringPi


install-binPROGRAMS:
	$(mkdir_p) $(DESTDIR)/$(libdir)
	$(INSTALL_PROGRAM) $(srcdir)/$(bin_PROGRAMS) $(DESTDIR)/$(libdir)

uninstall-binPROGRAMS:
	$(RM) $(DESTDIR)/$(libdir)/$(bin_PROGRAMS)

