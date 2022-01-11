#ifndef PSOLIDH
#define PSOLIDH
// Solid.h - Solid shapes with persistence
#include "Persist.h"
#include "String.h"
#include <math.h>
#define PI M_PI

class Solid : public Persist {					// abstract base
private:
	static int count;
public:
	Solid() { count++; }
	Solid(const Solid &) { count++; }
	virtual ~Solid() { count--; }
	virtual double surface_area() const = 0;
	virtual double volume() const = 0;
	virtual Solid *clone() const = 0;
	String whatsolid() const { return typeid(*this).name(); }
	static int num_solids() { return count; }
};

class Sphere : public Solid {						// persistent Sphere
private:
	double radius;
public:
	explicit Sphere(double r = 1) { radius = r; }
	Sphere(ifstream & ifs) { ifs >> radius; ifs.get(); }
	static Persist *new_sphere(ifstream & ifs) { return new Sphere(ifs); }
	double get_radius() const { return radius; }
	double surface_area() const { return 4 * PI * radius * radius; }
	double volume() const { return surface_area() * radius / 3; }
	void input(istream & is) { is >> radius; }
	void output(ostream & os) const { os << whatsolid() << " with radius " 
				<< radius << endl; } 
	void save(ofstream & ofs) const 
				{ ofs << whatsolid() << '\n' << radius; }
	Sphere *clone() const { return new Sphere(*this); }
};

class Cube : public Solid {						// persistent Cube
private:
	double side;
public:
	explicit Cube(double s = 1) { side = s; }
	Cube(ifstream & ifs) { ifs >> side; ifs.get(); }
	static Persist *new_cube(ifstream & ifs) { return new Cube(ifs); }
	double get_side() const { return side; }
	double surface_area() const { return 6 * side * side; }
	double volume() const { return side * side * side; }
	void input(istream & is) { is >> side; }
	void output(ostream & os) const { os << whatsolid() << " with side " 
				<< side << endl; } 
	void save(ofstream & ofs) const 
				{ ofs << whatsolid() << '\n' << side; }
	Cube *clone() const { return new Cube(*this); }
};

class Cylinder : public Solid {					// persistent Cylinder
private:
	double height;
	double radius;
public:
	explicit Cylinder(double h = 1, double r = 1) { height = h; radius = r; }
	Cylinder(ifstream & ifs) { ifs >> height >> radius; ifs.get(); }
	static Persist *new_cylinder(ifstream & ifs) { return new Cylinder(ifs); }
	double get_height() const { return height; }
	double get_radius() const { return radius; }
	double surface_area() const { return 2 * PI * radius * (height + radius); }
	double volume() const { return PI * radius * radius * height; } 
	void input(istream & is) { is >> height >> radius; }
	void output(ostream & os) const { os << whatsolid() << " with height " 
					<< height << " and radius " << radius << endl; } 
	void save(ofstream & ofs) const 
		{ ofs << whatsolid() << '\n' << height << ' ' << radius; }
	Cylinder *clone() const { return new Cylinder(*this); }
};
#endif
