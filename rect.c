#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    Display* display = XOpenDisplay(NULL);

    XVisualInfo vinfo;
    XMatchVisualInfo(display, DefaultScreen(display), 32, TrueColor, &vinfo);

    XSetWindowAttributes attr;
    attr.colormap = XCreateColormap(display, DefaultRootWindow(display), vinfo.visual, AllocNone);
    attr.border_pixel = 0;
    attr.background_pixel = 0;

    Window win = XCreateWindow(display, DefaultRootWindow(display), 0, 0, 300, 200, 0, vinfo.depth, InputOutput, vinfo.visual, CWColormap | CWBorderPixel | CWBackPixel, &attr);

    XDestroyWindow(display, win);
    XCloseDisplay(display);
    return 0;
}
