bin_PROGRAMS = libgaburevolver.so

libgaburevolver_so_SOURCES = libgaburevolver.c
libgaburevolver_so_CPPFLAGS = -I@WIRINGPI_DIR@ -I./../../../common
libgaburevolver_so_CFLAGS = -Wall -fPIC
libgaburevolver_so_LDFLAGS = -shared -lwiringPi


install-binPROGRAMS:
	$(mkdir_p) $(DESTDIR)/$(libdir)
	$(INSTALL_PROGRAM) $(srcdir)/$(bin_PROGRAMS) $(DESTDIR)/$(libdir)

uninstall-binPROGRAMS:
	$(RM) $(DESTDIR)/$(libdir)/$(bin_PROGRAMS)

