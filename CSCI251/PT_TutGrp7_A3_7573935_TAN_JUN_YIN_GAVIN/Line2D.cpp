#include "Line2D.h"

int Line2D::id = 0;

ostream &operator<<(ostream &os, Line2D &l2d)
{
	os << l2d.print();

	return os;
}

bool operator==(const Line2D &l1, const Line2D &l2)
{
	if ((l1.pt1 == l2.pt1) &&
		(l1.pt2 == l2.pt2))
	{
		return true;
	}

	return false;
}

// if pt1 and pt2 are the same points already means duplicated
bool operator<(const Line2D &l1, const Line2D &l2)
{
	if (l1.sorting == "Pt. 1")
	{
		if (l1.getP1().getX() < l2.getP1().getX())
		{
			return true;
		}
		else if (l1.getP1().getX() == l2.getP1().getX())
		{
			if (l1.getP1().getY() < l2.getP1().getY())
			{
				return true;
			}
		}
	}
	else if (l1.sorting == "Pt. 2")
	{
		if (l1.getP2().getX() < l2.getP2().getX())
		{
			return true;
		}
		else if (l1.getP2().getX() == l2.getP2().getX())
		{
			if (l1.getP2().getY() < l2.getP2().getY())
			{
				return true;
			}
		}
	}
	else if (l1.sorting == "Length")
	{
		if (l1.getScalarValue() < l2.getScalarValue())
		{
			return true;
		}
		else if (l1.getScalarValue() == l2.getScalarValue())
		{
			if (l1.getP1().getX() < l2.getP1().getX())
			{
				return true;
			}
			else if (l1.getP1().getX() == l2.getP1().getX())
			{
				if (l1.getP1().getY() < l2.getP1().getY())
				{
					return true;
				}
			}
		}
	}

	return false;
}

// if pt1 and pt2 are the same points already means duplicated
bool operator>(const Line2D &l1, const Line2D &l2)
{
	if (l1.sorting == "Pt. 1")
	{
		if (l1.getP1().getX() > l2.getP1().getX())
		{
			return true;
		}
		else if (l1.getP1().getX() == l2.getP1().getX())
		{
			if (l1.getP1().getY() > l2.getP2().getY())
			{
				return true;
			}
		}
	}
	else if (l1.sorting == "Pt. 2")
	{
		if (l1.getP2().getX() > l2.getP2().getX())
		{
			return true;
		}
		else if (l1.getP2().getX() == l2.getP2().getX())
		{
			if (l1.getP2().getY() > l2.getP2().getY())
			{
				return true;
			}
		}
	}
	else if (l1.sorting == "Length")
	{
		if (l1.getScalarValue() > l2.getScalarValue())
		{
			return true;
		}
		else if (l1.getScalarValue() == l2.getScalarValue())
		{
			if (l1.getP1().getX() > l2.getP1().getX())
			{
				return true;
			}
			else if (l1.getP1().getX() == l2.getP1().getX())
			{
				if (l1.getP1().getY() > l2.getP1().getY())
				{
					return true;
				}
			}
		}
	}

	return false;
}

Line2D::Line2D()
{
	this->pt1.setX(0);
	this->pt1.setY(0);
	this->pt2.setX(0);
	this->pt2.setY(0);
	this->sorting = "Pt. 1";
	this->setLength();
	this->id = id;
	this->id++;
}

Line2D::Line2D(Point2D pt1, Point2D pt2)
{
	this->pt1 = pt1;
	this->pt2 = pt2;
	this->sorting = "Pt. 1";
	this->setLength();
	this->id = id;
	this->id++;
}

Line2D::~Line2D()
{
	// let compiler do it
}

Line2D::Line2D(const Line2D &l2d)
{
	this->pt1 = l2d.pt1;
	this->pt2 = l2d.pt2;
	this->sorting = l2d.sorting;
	this->length = l2d.length;
	this->id = l2d.id;
}

Point2D Line2D::getP1() const
{
	return this->pt1;
}

Point2D Line2D::getP2() const
{
	return this->pt2;
}

double Line2D::getScalarValue() const
{
	return this->length;
}

string Line2D::getSort()
{
	return sorting;
}

string Line2D::print()
{
	stringstream oss;

	oss << "[" << setw(4) << right << getP1().getX() << ","
		<< setfill(' ') << setw(5) << right << getP1().getY() << "]   " // including comma (+1); include 3 spaces aft [
		<< "[" << setw(4) << right << getP2().getX() << ","
		<< setfill(' ') << setw(5) << right << getP2().getY() << "]   "
		<< setfill(' ') << fixed << setprecision(3) << this->length; // default print as left

	return (oss.str());
}

void Line2D::setP1(Point2D pt1)
{
	this->pt1 = pt1;
}

void Line2D::setP2(Point2D pt2)
{
	this->pt2 = pt2;
}

void Line2D::setSort(string sorting)
{
	this->sorting = sorting;
}

void Line2D::setLength()
{
	this->length = this->round(sqrt((pow((getP1().getX() - getP2().getX()), 2)) + (pow((getP1().getY() - getP2().getY()), 2))));
}

double Line2D::round(double origin)
{
	// 37.66666 * 1000 =37666.66
	// 37666.66 + .5 =37667.16    for rounding off value
	// then type cast to int so value is 37667
	// then divided by 1000 so the value converted into 37.667
	double value = (int)(origin * 1000 + .5);

	return (double)value / 1000;
}
