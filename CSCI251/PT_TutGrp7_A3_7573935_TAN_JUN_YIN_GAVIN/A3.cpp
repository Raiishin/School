#include "A3.h"

int displayMenuOptions(string f, string sC, string sO)
{
	int choice;

	cout << endl
		 << "Student ID   : 7573935" << endl
		 << "Student Name : TAN JUN YIN GAVIN" << endl
		 << "--------------------------------------------" << endl
		 << "Welcome to Assn3 Program"
		 << endl
		 << endl
		 << "1) \t Read in data" << endl
		 << "2) \t Specify filtering criteria (current: " << f << ")" << endl
		 << "3) \t Specify sorting criteria (current: " << sC << ")" << endl
		 << "4) \t Specify sorting order (current: " << sO << ")" << endl
		 << "5) \t View data" << endl
		 << "6) \t Store data" << endl
		 << "7) \t Quit" << endl
		 << endl
		 << "Please enter your choice: ";
	cin >> choice;

	return choice;
}

int checkValidOption(int option, string f, string sC, string sO)
{
	switch (option)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		return option;
	default:
		do
		{
			cout << endl
				 << "You have entered an invalid menu option. Please re-enter..."
				 << endl;
			option = displayMenuOptions(f, sC, sO);

		} while ((option != 1) || (option != 2) || (option != 3) ||
				 (option != 4) || (option != 5) || (option != 6) || (option != 7));
	}

	return option;
}

bool readFileOK(fstream &afile, string filename)
{
	afile.open(filename, ios::in);

	if (!afile)
	{
		cout << filename << " open for reading failed" << endl;
		return false;
	}

	return true;
}

char to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;

	return c;
}

char to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 32;

	return c;
}

int getSizeOfRecords(fstream &afile)
{
	string aline;
	int i = 0;
	while (getline(afile, aline))
	{
		if (aline.length() != 0)
		{
			++i;
		}
	}

	return i;
}

char displayFilterMenu(string filter)
{
	char choice;
	cout << endl
		 << "[ Specifying filtering criteria (current : " << filter << ") ]"
		 << endl
		 << endl
		 << "\t a) \t Point2D records" << endl
		 << "\t b) \t Point3D records" << endl
		 << "\t c) \t Line2D records" << endl
		 << "\t d) \t Line3D records" << endl
		 << endl
		 << endl
		 << "Please enter your criteria (a-d) : ";
	cin >> choice;

	return choice;
}

string checkValidOption(char option, string filter)
{
	option = to_lowercase(option);

	switch (option)
	{
	case 'a':
		return "Point2D";
	case 'b':
		return "Point3D";
	case 'c':
		return "Line2D";
	case 'd':
		return "Line3D";
	default:
		do
		{
			cout << endl
				 << "You have entered an invalid filter option. Please re-enter..."
				 << endl;
			option = displayFilterMenu(filter);
			option = to_lowercase(option);

		} while ((option != 'a') || (option != 'b') || (option != 'c') ||
				 (option != 'd'));
	}

	switch (option)
	{
	case 'a':
		return "Point2D";
	case 'b':
		return "Point3D";
	case 'c':
		return "Line2D";
	case 'd':
		return "Line3D";
	}

	return filter;
}

char displaySortMenu(string filter, string sort)
{
	char choice;
	cout << endl
		 << "[ Specifying sorting criteria (current : " << sort << ") ]"
		 << endl
		 << endl;

	if (filter.find("Point2D") == 0)
	{
		cout << "\t a) \t X ordinate value" << endl
			 << "\t b) \t Y ordinate value" << endl
			 << "\t c) \t Dist. Fr Origin value" << endl
			 << endl
			 << endl
			 << "Please enter your criteria (a-c) : ";
	}
	else if (filter.find("Point3D") == 0)
	{
		cout << "\t a) \t X ordinate value" << endl
			 << "\t b) \t Y ordinate value" << endl
			 << "\t c) \t Z ordinate value" << endl
			 << "\t d) \t Dist. Fr Origin value" << endl
			 << endl
			 << endl
			 << "Please enter your criteria (a-d) : ";
	}
	else if ((filter.find("Line2D")) || (filter.find("Line3D")))
	{
		cout << "\t a) \t X and Y coordinate values of Pt. 1" << endl
			 << "\t b) \t X and Y coordinate values of Pt. 2" << endl
			 << "\t c) \t Length value" << endl
			 << endl
			 << endl
			 << "Please enter your criteria (a-c) : ";
	}

	cin >> choice;

	return choice;
}

string checkValidSortOption(char option, string filter, string sort)
{
	option = to_lowercase(option);

	if (filter.find("Point2D") == 0)
	{
		switch (option)
		{
		case 'a':
			return "x-ordinate";
		case 'b':
			return "y-ordinate";
		case 'c':
			return "dist. fr origin";
		default:
			do
			{
				cout << endl
					 << "You have entered an invalid sort option. Please re-enter..."
					 << endl;
				option = displaySortMenu(filter, sort);
				option = to_lowercase(option);

			} while ((option != 'a') || (option != 'b') || (option != 'c'));
		}

		switch (option)
		{
		case 'a':
			return "x-ordinate";
		case 'b':
			return "y-ordinate";
		case 'c':
			return "dist. fr origin";
		}
	}
	else if (filter.find("Point3D") == 0)
	{
		switch (option)
		{
		case 'a':
			return "x-ordinate";
		case 'b':
			return "y-ordinate";
		case 'c':
			return "z-ordinate";
		case 'd':
			return "dist. fr origin";
		default:
			do
			{
				cout << endl
					 << "You have entered an invalid sort option. Please re-enter..."
					 << endl;
				option = displaySortMenu(filter, sort);
				option = to_lowercase(option);

			} while ((option != 'a') || (option != 'b') || (option != 'c') || (option != 'd'));
		}

		switch (option)
		{
		case 'a':
			return "x-ordinate";
		case 'b':
			return "y-ordinate";
		case 'c':
			return "z-ordinate";
		case 'd':
			return "dist. fr origin";
		}
	}
	else if ((filter.find("Line2D") == 0) || (filter.find("Line3D") == 0))
	{
		switch (option)
		{
		case 'a':
			return "Pt. 1";
		case 'b':
			return "Pt. 2";
		case 'c':
			return "Length";
		default:
			do
			{
				cout << endl
					 << "You have entered an invalid sort option. Please re-enter..."
					 << endl;
				option = displaySortMenu(filter, sort);
				option = to_lowercase(option);

			} while ((option != 'a') || (option != 'b') || (option != 'c'));
		}

		switch (option)
		{
		case 'a':
			return "Pt. 1";
		case 'b':
			return "Pt. 2";
		case 'c':
			return "Length";
		}
	}

	return sort;
}

char displayOrderMenu(string order)
{
	char choice;
	cout << endl
		 << "[ Specifying sorting order (current : " << order << ") ]"
		 << endl
		 << endl
		 << "\t a) \t ASC (Ascending order)" << endl
		 << "\t b) \t DSC (Descending order)" << endl
		 << endl
		 << endl
		 << "Please enter your criteria (a-b) : ";
	cin >> choice;

	return choice;
}

// check validity of menu option only a and b
string checkValidOrderOption(char option, string order)
{
	option = to_lowercase(option);

	switch (option)
	{
	case 'a':
		return "ASC";
	case 'b':
		return "DSC";
	default:
		do
		{
			cout << endl
				 << "You have entered an invalid order option. Please re-enter..."
				 << endl;
			option = displayOrderMenu(order);
			option = to_lowercase(option);

		} while ((option != 'a') || (option != 'b'));
	}

	switch (option)
	{
	case 'a':
		return "ASC";
	case 'b':
		return "DSC";
	}

	return order;
}

bool writeFileOK(fstream &afile, string filename)
{
	afile.open(filename, ios::out);

	if (!afile)
	{
		cout << filename << " open for writing failed" << endl;
		return false;
	}

	return true;
}

bool checkp2d(Point2D p2, vector<Point2D> p2d)
{
	for (int i = 0; i < p2d.size(); i++)
	{
		if (equals(p2, p2d[i]))
		{
			return true;
		}
	}

	return false;
}

bool checkp2d(Point2D p2a, Point2D p2b)
{
	if (equals(p2a, p2b))
	{
		return true;
	}

	return false;
}

bool checkp3d(Point3D p3, vector<Point3D> p3d)
{
	for (int i = 0; i < p3d.size(); i++)
	{
		if (equals(p3, p3d[i]))
		{
			return true;
		}
	}

	return false;
}

bool checkp3d(Point3D p3a, Point3D p3b)
{
	if (equals(p3a, p3b))
	{
		return true;
	}

	return false;
}

bool checkl2d(Line2D l2, vector<Line2D> l2d)
{
	for (int i = 0; i < l2d.size(); i++)
	{
		if (l2 == l2d[i])
		{
			return true;
		}
	}

	return false;
}

bool checkl3d(Line3D l3, vector<Line3D> l3d)
{
	for (int i = 0; i < l3d.size(); i++)
	{
		if (l3 == l3d[i])
		{
			return true;
		}
	}

	return false;
}
