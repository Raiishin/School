#ifndef LINE3D_H
#define LINE3D_H
#include "Point3D.h"
#include "Line2D.h"

class Line3D : public Line2D
{
	friend ostream &operator<<(ostream &, Line3D &);
	friend bool operator==(const Line3D &, const Line3D &);
	friend bool operator<(const Line3D &, const Line3D &);
	friend bool operator>(const Line3D &, const Line3D &);

public:
	// default constructor
	Line3D();

	// other constructor
	Line3D(Point3D, Point3D);

	// destructor
	~Line3D();

	// copy constructor
	Line3D(const Line3D &);

	// accessor methods
	Point3D getP1() const;

	Point3D getP2() const;

	// operations
	string print() override;

	// mutator methods
	void setP1(Point3D);

	void setP2(Point3D);

protected:
	void setLength() override;

private:
	Point3D pt1;
	Point3D pt2;
	static int id;
};

#endif
