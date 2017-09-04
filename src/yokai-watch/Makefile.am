SUBDIRS = lib

bin_PROGRAMS = yokai-watch_ctl
yokai_watch_ctl_SOURCES = yokai-watch_ctl.cpp
yokai_watch_ctl_LDFLAGS = -Llib -lyokai-watch
yokai_watch_ctl_LDADD = ../common/libtoyhack_common.a
yokai_watch_ctl_CXXFLAGS = -Wall -std=c++11 -I../common -DDX
