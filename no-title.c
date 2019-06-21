#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

int main(int argc, char **argv) {
  Display* d = XOpenDisplay(NULL);
  int s = DefaultScreen(d);
  Window w = XCreateSimpleWindow(d, RootWindow(d, s), 100, 100, 400, 100, 1,
                                 BlackPixel(d, s), WhitePixel(d, s));
  Atom window_type = XInternAtom(d, "_NET_WM_WINDOW_TYPE", False);
  long value = XInternAtom(d, "_NET_WM_WINDOW_TYPE_DOCK", False);
  XEvent e;
  XChangeProperty(d, w, window_type, XA_ATOM, 32, PropModeReplace, (unsigned char *) &value, 1);
  XMapWindow(d, w);
  while (1) {
    XNextEvent(d, &e);
    if (e.type == Expose) {
      XFillRectangle(d, w, DefaultGC(d, s), 20, 20, 10, 10);
    }
    if (e.type == KeyPress)
      break;
  }
  XCloseDisplay(d);
  return 0;
}
