bin_PROGRAMS = libyokai-watch.so

libyokai_watch_so_SOURCES = libyokai-watch.c
libyokai_watch_so_CPPFLAGS = -I@WIRINGPI_DIR@ -I./../../../common
libyokai_watch_so_CFLAGS = -Wall -fPIC
libyokai_watch_so_LDFLAGS = -shared -lwiringPi


install-binPROGRAMS:
	$(mkdir_p) $(DESTDIR)/$(libdir)
	$(INSTALL_PROGRAM) $(srcdir)/$(bin_PROGRAMS) $(DESTDIR)/$(libdir)

uninstall-binPROGRAMS:
	$(RM) $(DESTDIR)/$(libdir)/$(bin_PROGRAMS)

