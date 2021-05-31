#include <X11/extensions/XTest.h>
int
main(int argc,char *argv[])
{
	Display *dpy;
	if(argc>1){
		dpy = XOpenDisplay(NULL);
		if(dpy == NULL){
			return -1;
		}
		for(;;){
			XTestFakeButtonEvent(dpy,1,1,CurrentTime);
			XTestFakeButtonEvent(dpy,1,0,CurrentTime);
			XFlush(dpy);
		}
	}
}
