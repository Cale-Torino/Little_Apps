// ambig.c - ambiguities
#include <iostream.h>

class Window {											// class Library
public:
	void resize() {									// resize a Window
		cout << "Window::resize()" << endl;
	}									
};

class Font {											// class Library
public:
	void resize() {									// resize a Font
		cout << "Font::resize()" << endl;
	}									
};

class WFont : public Window, public Font {
public:
	void w_resize() { Window::resize(); }
	void f_resize() { Font::resize(); }
};

int main()
{
	WFont w;
	//w.resize();										// error, which one?

	w.Font::resize();									// call resize() in Font
	w.Window::resize();								// call resize() in Window

	w.w_resize();										// call resize in Window
	w.f_resize();										// call resize in Font
	return 0;
}

/**********************************************************************

$ ambig
Font::resize()
Window::resize()
Window::resize()
Font::resize()

*/
