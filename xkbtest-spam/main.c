//#!/usr/bin/tcc -run -lX11 -lXtst -lpthreads
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>
int
main(int argc,char *argv[])
{	
	int keycode;
	Display *display;
	display = XOpenDisplay(NULL);
	if (display == NULL) {
		return -1;
	}
	if (argc > 1) {
		keycode = atoi(argv[1]);
		for (;;) {
			XTestFakeKeyEvent(display, keycode, 1, CurrentTime);
			XTestFakeKeyEvent(display, keycode, 0, CurrentTime);
			XFlush(display);
		}
	} 
	return 0;
}
