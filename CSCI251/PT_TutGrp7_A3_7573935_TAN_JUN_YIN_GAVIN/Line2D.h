#ifndef LINE2D_H
#define LINE2D_H
#include "Point2D.h"
#include <iostream>
#include <sstream>
using namespace std;

class Line2D
{
	friend ostream &operator<<(ostream &, Line2D &);
	friend bool operator==(const Line2D &, const Line2D &);
	friend bool operator<(const Line2D &, const Line2D &);
	friend bool operator>(const Line2D &, const Line2D &);

public:
	// default constructor
	Line2D();

	// other constructor
	Line2D(Point2D, Point2D);

	// destructor
	~Line2D();

	// copy constructor
	Line2D(const Line2D &);

	// accessor methods
	Point2D getP1() const;

	Point2D getP2() const;

	double getScalarValue() const;

	string getSort();

	// operations
	virtual string print();

	// mutator methods
	void setP1(Point2D);

	void setP2(Point2D);

	void setSort(string);

protected:
	double length;
	string sorting;
	virtual void setLength();
	virtual double round(double);

private:
	Point2D pt1;
	Point2D pt2;
	static int id;
};

#endif
