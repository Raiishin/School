#ifndef POINT3D_H
#define POINT3D_H
#include "Point2D.h"
#include <iostream>
#include <sstream>
using namespace std;

class Point3D : public Point2D
{
	friend ostream &operator<<(ostream &, const Point3D &);
	friend bool operator==(const Point3D &, const Point3D &);
	friend bool operator<(const Point3D &, const Point3D &);
	friend bool operator>(const Point3D &, const Point3D &);

public:
	// default constructor
	Point3D();

	// other constructor
	Point3D(int x, int y, int z);

	// destructor
	~Point3D();

	// copy constructor
	Point3D(const Point3D &);

	// accessor methods
	int getZ();

	// operations
	string print() const override;

	// mutator methods
	void setZ(int);

protected:
	void setDistFrOrigin() override;

	int z;
	static int id;
};

#endif
