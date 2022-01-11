#ifndef WINDOW2H
#define WINDOW2H
// Window2.h - Window and XWindow interface, virtual constructor
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
	virtual void draw() const { cout << "Frame draw()" << endl; }
};

class XFrame : public Frame {
friend class XWindow;					// XWindow must access
protected:
	XFrame(Point tl, Point br) : Frame(tl, br) { 
		cout << "XFrame constr" << endl;
	}
	~XFrame() { }
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
public:
	Window() : pf(0) { cout << "Window constr" << endl; }
	virtual ~Window() { free(); }
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
	XFrame *createFrame(Point tl, Point br) {
		return new XFrame(tl, br);
	}
public:
	XWindow() { cout << "XWindow constr" << endl; }
	~XWindow() { }
	void resize(Point tl, Point br) {			// virtual
		Window::resize(tl, br);
		// perform other XWindow tasks
	}
};
#endif
