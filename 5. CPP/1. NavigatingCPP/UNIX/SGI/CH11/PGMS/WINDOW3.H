#ifndef WINDOW3H
#define WINDOW3H
// Window3.h - Window and XWindow interface, virtual copy constructor (clone)
#include <iostream.h>
#include "Point5.h"

class Frame {
friend class Window;
protected:
	Point topleft, bottomright;
	Frame(Point tl, Point br) { 
		cout << "Frame constr" << endl;
		topleft = tl; bottomright = br;
	}
	virtual ~Frame() { } 
	virtual Frame *clone() const { return new Frame(*this); }
	virtual void draw() const { cout << "Frame draw()" << endl; }
};

class XFrame : public Frame {
friend class XWindow;					// XWindow must access
protected:
	XFrame(Point tl, Point br) : Frame(tl, br) { 
		cout << "XFrame constr" << endl;
	}
	~XFrame() { }
	Frame *clone() const { return new XFrame(*this); }
	void move() { cout << "XFrame move()" << endl; }
	void draw() const { cout << "XFrame draw()" << endl; }
};

class Window {							// manage Frames
private:
	Frame *pf;
	virtual Frame *createFrame(Point tl, Point br) {
		return new Frame(tl, br);
	}
	void free() { delete pf; }
	void copy(const Window & w) 
			{ if (w.pf) pf = w.pf->clone(); }
	void operator=(const Window &);						// disallow assignment
public:
	Window() : pf(0) { cout << "Window constr" << endl; }
	Window(const Window & w) : pf(0) { copy(w); }	// copy constructor
	virtual ~Window() { free(); }
	virtual Window *clone() const { return new Window(*this); }
	void refresh() const { if (pf) pf->draw(); }
	virtual void resize(Point tl, Point br) {
		Frame *pfnew = createFrame(tl, br);		// virtual call
		free();											// release old Frame
		pf = pfnew;										// initialize new Frame
		pf->draw();										// draw new Frame
	}
};

class XWindow : public Window {					// manage XFrames
private:
	Frame *createFrame(Point tl, Point br) {
		return new XFrame(tl, br);
	}
public:
	XWindow() { cout << "XWindow constr" << endl; }
	~XWindow() { }
	void resize(Point tl, Point br) {			// virtual
		Window::resize(tl, br);
		// perform other XWindow tasks
	}
	Window *clone() const { return new XWindow(*this); }
};
#endif
