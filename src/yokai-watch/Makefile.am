SUBDIRS = lib

bin_PROGRAMS = yokai-watch_ctl yokai-watch-zero_ctl

SOURCES = yokai-watch_ctl.cpp
LDADD = ../common/libtoyhack_common.a
BASE_CXXFLAGS = -Wall -std=c++11 -I../common

yokai_watch_ctl_SOURCES = $(SOURCES)
yokai_watch_ctl_LDFLAGS = -Llib -lyokai-watch
yokai_watch_ctl_LDADD = $(LDADD)
yokai_watch_ctl_CXXFLAGS = $(BASE_CXXFLAGS) -DDX

yokai_watch_zero_ctl_SOURCES = $(SOURCES)
yokai_watch_zero_ctl_LDFLAGS = -Llib -lyokai-watch
yokai_watch_zero_ctl_LDADD = $(LDADD)
yokai_watch_zero_ctl_CXXFLAGS = $(BASE_CXXFLAGS) -DZERO
