#include "Point3D.h"

int Point3D::id = 0;

ostream &operator<<(ostream &os, const Point3D &p3d)
{
	os << p3d.print();

	return os;
}

bool operator==(const Point3D &pt1, const Point3D &pt2)
{
	if ((pt1.x == pt2.x) &&
		(pt1.y == pt2.y) && (pt1.z == pt2.z))
	{
		return true;
	}

	return false;
}

// if all x, y and z are the same means pt1 and pt2 are the same points
bool operator<(const Point3D &pt1, const Point3D &pt2)
{
	if (pt1.sorting == "x-ordinate")
	{
		if (pt1.x < pt2.x)
		{
			return true;
		}
		else if (pt1.x == pt2.x)
		{
			if (pt1.y < pt2.y)
			{
				return true;
			}
			else if (pt1.y == pt2.y)
			{
				if (pt1.z < pt2.z)
				{
					return true;
				}
			}
		}
	}
	else if (pt1.sorting == "y-ordinate")
	{
		if (pt1.y < pt2.y)
		{
			return true;
		}
		else if (pt1.y == pt2.y)
		{
			if (pt1.x < pt2.x)
			{
				return true;
			}
			else if (pt1.x == pt2.x)
			{
				if (pt1.z < pt2.z)
				{
					return true;
				}
			}
		}
	}
	else if (pt1.sorting == "z-ordinate")
	{
		if (pt1.z < pt2.z)
		{
			return true;
		}
		else if (pt1.z == pt2.z)
		{
			if (pt1.x < pt2.x)
			{
				return true;
			}
			else if (pt1.x == pt2.x)
			{
				if (pt1.y < pt2.y)
				{
					return true;
				}
			}
		}
	}
	else if (pt1.sorting == "dist. fr origin")
	{
		if (pt1.distFrOrigin < pt2.distFrOrigin)
		{
			return true;
		}
		else if (pt1.distFrOrigin == pt2.distFrOrigin)
		{
			if (pt1.x < pt2.x)
			{
				return true;
			}
			else if (pt1.x == pt2.x)
			{
				if (pt1.y < pt2.y)
				{
					return true;
				}
				else if (pt1.y == pt2.y)
				{
					if (pt1.z < pt2.z)
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

// if all x, y and z are the same means pt1 and pt2 are the same points
bool operator>(const Point3D &pt1, const Point3D &pt2)
{
	if (pt1.sorting == "x-ordinate")
	{
		if (pt1.x > pt2.x)
		{
			return true;
		}
		else if (pt1.x == pt2.x)
		{
			if (pt1.y > pt2.y)
			{
				return true;
			}
			else if (pt1.y == pt2.y)
			{
				if (pt1.z > pt2.z)
				{
					return true;
				}
			}
		}
	}
	else if (pt1.sorting == "y-ordinate")
	{
		if (pt1.y > pt2.y)
		{
			return true;
		}
		else if (pt1.y == pt2.y)
		{
			if (pt1.x > pt2.x)
			{
				return true;
			}
			else if (pt1.x == pt2.x)
			{
				if (pt1.z > pt2.z)
				{
					return true;
				}
			}
		}
	}
	else if (pt1.sorting == "z-ordinate")
	{
		if (pt1.z > pt2.z)
		{
			return true;
		}
		else if (pt1.z == pt2.z)
		{
			if (pt1.x > pt2.x)
			{
				return true;
			}
			else if (pt1.x == pt2.x)
			{
				if (pt1.y > pt2.y)
				{
					return true;
				}
			}
		}
	}
	else if (pt1.sorting == "dist. fr origin")
	{
		if (pt1.distFrOrigin > pt2.distFrOrigin)
		{
			return true;
		}
		else if (pt1.distFrOrigin == pt2.distFrOrigin)
		{
			if (pt1.x > pt2.x)
			{
				return true;
			}
			else if (pt1.x == pt2.x)
			{
				if (pt1.y > pt2.y)
				{
					return true;
				}
				else if (pt1.y == pt2.y)
				{
					if (pt1.z > pt2.z)
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

Point3D::Point3D() : Point2D()
{
	this->z = 0;
	this->setDistFrOrigin();
	this->sorting = "x-ordinate";
	this->quadrant = "";
	this->id = id;
	this->id++;
}

Point3D::Point3D(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
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

Point3D::~Point3D()
{
	// let compiler do it
}

Point3D::Point3D(const Point3D &p3d)
{
	this->x = p3d.x;
	this->y = p3d.y;
	this->z = p3d.z;
	this->distFrOrigin = p3d.distFrOrigin;
	this->sorting = p3d.sorting;
	this->quadrant = p3d.quadrant;
	this->id = p3d.id;
}

int Point3D::getZ()
{
	return z;
}

string Point3D::print() const
{
	stringstream ss;

	ss << "[" << setw(4) << right << this->x << ","
	   << setfill(' ') << setw(5) << right << this->y << ","
	   << setfill(' ') << setw(5) << right << this->z << "]   "
	   << setfill(' ') << setw(10) << this->quadrant << "  "
	   << setfill(' ') << fixed << setprecision(3) << this->distFrOrigin;

	return (ss.str());
}

void Point3D::setZ(int z)
{
	this->z = z;
}

void Point3D::setDistFrOrigin()
{
	this->distFrOrigin = this->round(sqrt((pow(this->x, 2)) + (pow(this->y, 2)) + (pow(this->z, 2))));
}
