#include "Point2D.h"

int Point2D::id = 0;

ostream &operator<<(ostream &os, const Point2D &p2d)
{
	os << p2d.print();

	return os;
}

bool operator==(const Point2D &pt1, const Point2D &pt2)
{
	if ((pt1.x == pt2.x) &&
		(pt1.y == pt2.y))
	{
		return true;
	}

	return false;
}

// if all x, y and z are the same means pt1 and pt2 are the same points
bool operator<(const Point2D &pt1, const Point2D &pt2)
{
	if (pt1.sorting == "x-ordinate")
	{
		if ((pt1.x < pt2.x) || ((pt1.x == pt2.x) && (pt1.y < pt2.y)))
		{
			return true;
		}
	}
	else if (pt1.sorting == "y-ordinate")
	{
		if ((pt1.y < pt2.y) || ((pt1.y == pt2.y) && (pt1.x < pt2.x)))
		{
			return true;
		}
	}
	else if (pt1.sorting == "dist. fr origin")
	{
		if ((pt1.distFrOrigin < pt2.distFrOrigin) || ((pt1.distFrOrigin == pt2.distFrOrigin) && (pt1.x < pt2.x)) ||
			((pt1.distFrOrigin == pt2.distFrOrigin) && (pt1.x == pt2.x) && (pt1.y < pt2.y)))
		{
			return true;
		}
	}

	return false;
}

// if all x, y and z are the same means pt1 and pt2 are the same points
bool operator>(const Point2D &pt1, const Point2D &pt2)
{
	if (pt1.sorting == "x-ordinate")
	{
		if ((pt1.x > pt2.x) || ((pt1.x == pt2.x) && (pt1.y > pt2.y)))
		{
			return true;
		}
	}
	else if (pt1.sorting == "y-ordinate")
	{
		if ((pt1.y > pt2.y) || ((pt1.y == pt2.y) && (pt1.x > pt2.x)))
		{
			return true;
		}
	}
	else if (pt1.sorting == "dist. fr origin")
	{
		if ((pt1.distFrOrigin > pt2.distFrOrigin) || ((pt1.distFrOrigin == pt2.distFrOrigin) && (pt1.x > pt2.x)) ||
			((pt1.distFrOrigin == pt2.distFrOrigin) && (pt1.x == pt2.x) && (pt1.y > pt2.y)))
		{
			return true;
		}
	}

	return false;
}

double operator-(const Point2D &pt1, const Point2D &pt2)
{
	return fabs(pt1.distFrOrigin - pt2.distFrOrigin);
}

Point2D::Point2D()
{
	this->x = 0;
	this->y = 0;
	this->setDistFrOrigin();
	this->sorting = "x-ordinate";
	this->quadrant = "";
	this->id = id;
	this->id++;
}

Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
	this->setDistFrOrigin();
	this->sorting = "x-ordinate";
	if ((this->x == 0) && (this->y == 0))
	{
		this->setQuadrant("Center");
	}
	else if ((this->x > 0) && (this->y > 0))
	{
		this->setQuadrant("Quadrant 1");
	}
	else if ((this->x < 0) && (this->y > 0))
	{
		this->setQuadrant("Quadrant 2");
	}
	else if ((this->x < 0) && (this->y < 0))
	{
		this->setQuadrant("Quadrant 3");
	}
	else if ((this->x > 0) && (this->y < 0))
	{
		this->setQuadrant("Quadrant 4");
	}
	this->id = id;
	this->id++;
}

Point2D::~Point2D()
{
	// let compiler do it
}

Point2D::Point2D(const Point2D &p2d)
{
	this->x = p2d.x;
	this->y = p2d.y;
	this->distFrOrigin = p2d.distFrOrigin;
	this->sorting = p2d.sorting;
	this->quadrant = p2d.quadrant;
	this->id = p2d.id;
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}

double Point2D::getScalarValue()
{
	return distFrOrigin;
}

string Point2D::getQuadrant()
{
	return quadrant;
}

string Point2D::print() const
{
	stringstream ss;
	ss << "[" << setw(4) << right << this->x << ","
	   << setfill(' ') << setw(5) << right << this->y << "]   " // including comma (+1); include 3 spaces aft [
	   << setfill(' ') << setw(10) << this->quadrant << "  "
	   << setfill(' ') << fixed << setprecision(3) << this->distFrOrigin; // default print as left

	return (ss.str());
}

void Point2D::setX(int x)
{
	this->x = x;
}

void Point2D::setY(int y)
{
	this->y = y;
}

void Point2D::setSort(string sorting)
{
	this->sorting = sorting;
}

void Point2D::setDistFrOrigin()
{
	this->distFrOrigin = this->round(sqrt((pow(this->x, 2)) + (pow(this->y, 2))));
}

void Point2D::setQuadrant(string quadrant)
{
	this->quadrant = quadrant;
}

double Point2D::round(double origin)
{
	// 37.66666 * 1000 =37666.66
	// 37666.66 + .5 =37667.16    for rounding off value
	// then type cast to int so value is 37667
	// then divided by 1000 so the value converted into 37.667
	double value = (int)(origin * 1000 + .5);

	return (double)value / 1000;
}
