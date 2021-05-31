#!/usr/bin/tcc -run -lX11 -lXtst
#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
int
main(int argc,char *argv[])
{
	Display *display;
	unsigned int keycode;
	display = XOpenDisplay(NULL);
	if (display == NULL) {
		return -1;
	}
	if (argc > 1) {
		int i;
		for (i=1;i<argc;i++) {
			keycode = atoi(argv[i]);
			XTestFakeKeyEvent(display, keycode, 1, CurrentTime);
			XTestFakeKeyEvent(display, keycode, 0, CurrentTime);
		}
	} 
   	XFlush(display);
	return 0;
}
