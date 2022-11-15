#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;

class Point2D
{
	friend ostream &operator<<(ostream &, const Point2D &);
	friend bool operator==(const Point2D &, const Point2D &);
	friend bool operator<(const Point2D &, const Point2D &);
	friend bool operator>(const Point2D &, const Point2D &);
	friend double operator-(const Point2D &, const Point2D &);

public:
	// default constructor
	Point2D();

	// other constructor
	Point2D(int, int);

	// destructor
	~Point2D();

	// copy constructor
	Point2D(const Point2D &);

	// accessor methods
	int getX();

	int getY();

	double getScalarValue();

	string getQuadrant();

	// operations
	virtual string print() const;

	// mutator methods
	void setX(int);

	void setY(int);

	virtual void setSort(string);

protected:
	virtual void setDistFrOrigin();
	virtual double round(double);
	void setQuadrant(string);

	int x;
	int y;
	double distFrOrigin;
	string sorting;
	string quadrant;
	static int id;
};

#endif
