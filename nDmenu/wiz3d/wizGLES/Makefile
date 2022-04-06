OPEN2X = /opt/local/devkitpro/devkitGP2X
HOST = arm-linux

CC = $(OPEN2X)/bin/$(HOST)-gcc
CXX = $(OPEN2X)/bin/$(HOST)-g++

all: wizGLES.o libwizGLES.so

wizGLES.o:
	$(CC) -I. -fPIC -c wizGLES.cpp
libwizGLES.so:
	$(CC) -shared -W1,-soname,libwizGLES.so.0 -o libwizGLES.so wizGLES.o

install:
	mkdir -p $(OPEN2X)/lib
	mkdir -p $(OPEN2X)/include
	cp -f libwizGLES.so $(OPEN2X)/lib/libwizGLES.so
	cp -f wizGLES.h $(OPEN2X)/include/wizGLES.h
	cp -f libwizGLES.so libwizGLES.so

clean:
	rm -f *.o
	rm -rf lib*


