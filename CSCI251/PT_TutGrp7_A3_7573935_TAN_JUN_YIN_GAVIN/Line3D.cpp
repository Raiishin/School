#include "Line3D.h"

int Line3D::id = 0;

ostream &operator<<(ostream &os, Line3D &l3d)
{
	os << l3d.print();

	return os;
}

bool operator==(const Line3D &l1, const Line3D &l2)
{
	if ((l1.pt1 == l2.pt1) &&
		(l1.pt2 == l2.pt2))
	{
		return true;
	}

	return false;
}

// if pt1 and pt2 are the same points already means duplicated
bool operator<(const Line3D &l1, const Line3D &l2)
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
			else if (l1.getP1().getY() == l2.getP1().getY())
			{
				if (l1.getP1().getZ() < l2.getP1().getZ())
				{
					return true;
				}
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
			else if (l1.getP2().getY() == l2.getP2().getY())
			{
				if (l1.getP2().getZ() < l2.getP2().getZ())
				{
					return true;
				}
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
				else if (l1.getP1().getY() == l2.getP1().getY())
				{
					if (l1.getP1().getZ() < l2.getP1().getZ())
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

// if pt1 and pt2 are the same points already means duplicated
bool operator>(const Line3D &l1, const Line3D &l2)
{
	if (l1.sorting == "Pt. 1")
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
			else if (l1.getP1().getY() == l2.getP1().getY())
			{
				if (l1.getP1().getZ() > l2.getP1().getZ())
				{
					return true;
				}
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
			else if (l1.getP2().getY() == l2.getP2().getY())
			{
				if (l1.getP2().getZ() > l2.getP2().getZ())
				{
					return true;
				}
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
				else if (l1.getP1().getY() == l2.getP1().getY())
				{
					if (l1.getP1().getZ() > l2.getP1().getZ())
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

Line3D::Line3D()
{
	this->pt1.setX(0);
	this->pt1.setY(0);
	this->pt2.setX(0);
	this->pt2.setY(0);
	this->pt1.setZ(0);
	this->pt2.setZ(0);
	this->sorting = "Pt. 1";
	this->setLength();
	this->id = id;
	this->id++;
}

Line3D::Line3D(Point3D pt1, Point3D pt2)
{
	this->pt1 = pt1;
	this->pt2 = pt2;
	this->sorting = "Pt. 1";
	this->setLength();
	this->id = id;
	this->id++;
}

Line3D::~Line3D()
{
	// let compiler do it
}

Line3D::Line3D(const Line3D &l3d)
{
	this->pt1 = l3d.pt1;
	this->pt2 = l3d.pt2;
	this->sorting = l3d.sorting;
	this->length = l3d.length;
	this->id = l3d.id;
}

Point3D Line3D::getP1() const
{
	return pt1;
}

Point3D Line3D::getP2() const
{
	return pt2;
}

string Line3D::print()
{
	stringstream oss;

	oss << "[" << setw(4) << right << getP1().getX() << ","
		<< setfill(' ') << setw(5) << right << getP1().getY() << ","
		<< setfill(' ') << setw(5) << right << getP1().getZ() << "]   " // including comma (+1); include 3 spaces aft [
		<< "[" << setw(4) << right << getP2().getX() << ","
		<< setfill(' ') << setw(5) << right << getP2().getY() << ","
		<< setfill(' ') << setw(5) << right << getP2().getZ() << "]   "
		<< setfill(' ') << fixed << setprecision(3) << this->length; // default print as left

	return (oss.str());
}

void Line3D::setP1(Point3D pt1)
{
	this->pt1 = pt1;
}

void Line3D::setP2(Point3D pt2)
{
	this->pt2 = pt2;
}

void Line3D::setLength()
{
	this->length = this->round(sqrt((pow((getP1().getX() - getP2().getX()), 2)) + (pow((getP1().getY() - getP2().getY()), 2)) + (pow((getP1().getZ() - getP2().getZ()), 2))));
}
