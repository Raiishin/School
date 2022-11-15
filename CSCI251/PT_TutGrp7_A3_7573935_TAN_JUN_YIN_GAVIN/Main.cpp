#include "A3.h"

int main()
{
	int choice;
	int size = 0; // size of records
	fstream afile;
	fstream outfile;
	bool ok = false; // checking for file opening ok
	string filename;
	string aline;
	char space;
	char comma;
	char openbracket;
	char closebracket;
	vector<Point2D> p2d;
	vector<Point3D> p3d;
	vector<Line2D> l2d;
	vector<Line3D> l3d;
	static int i = 0;
	static string filterC = "Point2D";
	static string sortC = "x-ordinate";
	static string sortO = "ASC";

	do
	{
		// return valid option after displaying main menu to user
		choice = checkValidOption(displayMenuOptions(filterC, sortC, sortO), filterC, sortC, sortO);

		switch (choice)
		{
		case 1:
			do
			{
				cout << endl;
				cout << "[ 1. Read in and process a configuration file ]"
					 << endl
					 << endl
					 << "Please enter config filename : ";
				cin >> filename;
				ok = readFileOK(afile, filename); // check ifstream ok for reading filename
			} while (ok == false);

			while (afile.good())
			{
				// process to read each line of filename
				getline(afile, aline);

				for (char &c : aline)
				{
					c = to_lowercase(c);
				}
				// Extracting data that are point2d
				// Will be true if "point2d" is a substring of aline
				// static const size_t npos = -1;
				if (aline.find("point2d") != string::npos)
				{
					int pos = aline.find(","); // find position of comma
					aline = aline.substr(pos); // to extract string from comma onwards
					comma = aline[0];		   // extracting comma from 0 index
					space = aline[1];		   // extracting space from 1 index
					pos = aline.find("[");
					aline = aline.substr(pos + 1); // getting the point values after "["

					pos = aline.find(comma);			// finding position of comma from current aline
					string strX = aline.substr(0, pos); // extracting x value till hits comma
					int x = 1000;
					if ((stoi(strX) > -1000) && (stoi(strX) < x))
					{
						x = stoi(strX); // if x value is valid else value remains 1000
					}

					pos = aline.find(space);	// finding position of space from current aline
					int pos2 = aline.find("]"); // finding position of close square bracket
					string strY = aline.substr(pos + 1, pos2);
					int y = 1000;
					if ((stoi(strY) > -1000) && (stoi(strY) < y))
					{
						y = stoi(strY); // if y value is valid else value remains 1000
					}

					Point2D p2 = Point2D(x, y);

					if (checkp2d(p2, p2d) == false)
					{
						p2d.push_back(p2); // once values x and y are stored can push back into vector
						i++;
					}
				}
				else if (aline.find("point3d") != string::npos)
				{
					int pos = aline.find(","); // find position of comma
					aline = aline.substr(pos); // to extract string from comma onwards
					comma = aline[0];		   // extracting comma from 0 index
					space = aline[1];		   // extracting space from 1 index
					pos = aline.find("[");
					aline = aline.substr(pos + 1); // getting the point values after "["

					pos = aline.find(comma);			// finding position of comma from current aline
					string strX = aline.substr(0, pos); // extracting x value till hits comma
					int x = 1000;
					if ((stoi(strX) > -1000) && (stoi(strX) < x))
					{
						x = stoi(strX); // if x value is valid else value remains 1000
					}

					int pos2 = aline.find("]"); // finding position of close square bracket
					pos = aline.find(space);
					aline = aline.substr(pos + 1, pos2);

					pos2 = aline.find(comma);
					string strY = aline.substr(0, pos2); // extracting y value till hits comma from after space
					int y = 1000;
					if ((stoi(strY) > -1000) && (stoi(strY) < y))
					{
						y = stoi(strY); // if y value is valid else value remains 1000
					}

					pos = aline.find(space); // finding position of space from current aline
					pos2 = aline.find("]");
					string strZ = aline.substr(pos + 1, pos2);
					int z = 1000;
					if ((stoi(strZ) > -1000) && (stoi(strZ) < z))
					{
						z = stoi(strZ); // if y value is valid else value remains 1000
					}

					Point3D p3 = Point3D(x, y, z);

					if (checkp3d(p3, p3d) == false)
					{
						p3d.push_back(p3); // once values x and y are stored can push back into vector
						i++;
					}
				}
				else if (aline.find("line2d") != string::npos)
				{
					// getting pt1 of line2d
					int pos = aline.find(","); // find position of comma
					aline = aline.substr(pos); // to extract string from comma onwards
					comma = aline[0];		   // extracting comma from 0 index
					space = aline[1];		   // extracting space from 1 index
					openbracket = aline[2];
					pos = aline.find(openbracket);
					aline = aline.substr(pos + 1); // getting the point values after "["

					pos = aline.find(comma);			// finding position of comma from current aline
					string strX = aline.substr(0, pos); // extracting x value till hits comma
					int x = 1000;
					if ((stoi(strX) > -1000) && (stoi(strX) < x))
					{
						x = stoi(strX); // if x value is valid else value remains 1000
					}

					pos = aline.find(space);	   // finding position of space from current aline
					aline = aline.substr(pos + 1); // extract values after space

					int pos2 = aline.find("]"); // finding position of close square bracket
					string strY = aline.substr(0, pos2);
					int y = 1000;
					if ((stoi(strY) > -1000) && (stoi(strY) < y))
					{
						y = stoi(strY); // if y value is valid else value remains 1000
					}

					Point2D p2a = Point2D(x, y);

					// getting pt2 of line2d
					aline = aline.substr(pos2);
					closebracket = aline[0];

					pos = aline.find(openbracket);
					aline = aline.substr(pos + 1);
					pos2 = aline.find(comma);

					strX = aline.substr(0, pos2);
					x = 1000;
					if ((stoi(strX) > -1000) && (stoi(strX) < x))
					{
						x = stoi(strX); // if x value is valid else value remains 1000
					}

					pos = aline.find(space);
					pos2 = aline.find(closebracket);

					strY = aline.substr(pos + 1, pos2);
					y = 1000;
					if ((stoi(strY) > -1000) && (stoi(strY) < y))
					{
						y = stoi(strY); // if y value is valid else value remains 1000
					}

					Point2D p2b = Point2D(x, y);
					Line2D l2 = Line2D(p2a, p2b);

					// make sure both points are not the same
					if (checkp2d(p2a, p2b) == false)
					{
						if (checkl2d(l2, l2d) == false)
						{
							l2d.push_back(l2);
							i++;
						}
					}
				}
				else if (aline.find("line3d") != string::npos)
				{
					// getting pt1 of line3d
					int pos = aline.find(","); // find position of comma
					aline = aline.substr(pos); // to extract string from comma onwards
					comma = aline[0];		   // extracting comma from 0 index
					space = aline[1];		   // extracting space from 1 index
					openbracket = aline[2];
					pos = aline.find(openbracket);
					aline = aline.substr(pos + 1); // getting the point values after "["

					pos = aline.find(comma);			// finding position of comma from current aline
					string strX = aline.substr(0, pos); // extracting x value till hits comma
					int x = 1000;
					if ((stoi(strX) > -1000) && (stoi(strX) < x))
					{
						x = stoi(strX); // if x value is valid else value remains 1000;
					}

					pos = aline.find(space);
					aline = aline.substr(pos + 1);

					int pos2 = aline.find(comma);
					string strY = aline.substr(0, pos2); // extracting y value till hits comma from after space
					int y = 1000;
					if ((stoi(strY) > -1000) && (stoi(strY) < y))
					{
						y = stoi(strY); // if y value is valid else value remains 1000
					}

					pos = aline.find(space); // finding position of space from current aline
					aline = aline.substr(pos + 1);
					pos2 = aline.find("]");
					string strZ = aline.substr(0, pos2);
					int z = 1000;
					if ((stoi(strZ) > -1000) && (stoi(strZ) < z))
					{
						z = stoi(strZ); // if y value is valid else value remains 1000
					}

					Point3D p3a = Point3D(x, y, z);

					// getting pt2 of line3d
					aline = aline.substr(pos2);
					closebracket = aline[0];

					pos = aline.find(openbracket);
					aline = aline.substr(pos + 1);

					pos2 = aline.find(comma);
					strX = aline.substr(0, pos2); // extracting x value till hits comma
					x = 1000;
					if ((stoi(strX) > -1000) && (stoi(strX) < x))
					{
						x = stoi(strX); // if x value is valid else value remains 1000
					}

					pos = aline.find(space);
					aline = aline.substr(pos + 1);

					pos2 = aline.find(comma);
					strY = aline.substr(0, pos2); // extracting y value till hits comma from after space
					y = 1000;
					if ((stoi(strY) > -1000) && (stoi(strY) < y))
					{
						y = stoi(strY); // if y value is valid else value remains 1000
					}

					pos = aline.find(space);
					pos2 = aline.find(closebracket);
					strZ = aline.substr(pos + 1, pos2);
					z = 1000;
					if ((stoi(strZ) > -1000) && (stoi(strZ) < z))
					{
						z = stoi(strZ); // if y value is valid else value remains 1000
					}

					Point3D p3b = Point3D(x, y, z);
					Line3D l3 = Line3D(p3a, p3b);

					// make sure both points are not the same
					if (checkp3d(p3a, p3b) == false)
					{
						if (checkl3d(l3, l3d) == false)
						{
							l3d.push_back(l3);
							i++;
						}
					}
				}
			}
			afile.close();

			if (readFileOK(afile, filename))
			{
				size = getSizeOfRecords(afile);
				afile.close();
			}

			cout << endl
				 << "There are " << size << " records in the file with " << endl
				 << size - i << " duplicated records but only " << endl
				 << i
				 << " record(s) read in successfully!"
				 << endl
				 << endl;

			cout << "Going back to main menu..."
				 << endl;
			break;
		case 2:
			filterC = checkValidOption(displayFilterMenu(filterC), filterC);
			cout << "Filter criteria successfully set to '" << filterC << "'!" << endl;
			if ((filterC.find("Point2D") == 0) || (filterC.find("Point3D") == 0))
			{
				sortC = "x-ordinate";
			}
			else
			{
				sortC = "Pt. 1";
			}
			break;
		case 3:
			sortC = checkValidSortOption(displaySortMenu(filterC, sortC), filterC, sortC);
			cout << "Sorting criteria successfully set to '" << sortC << "'!" << endl;
			break;
		case 4:
			sortO = checkValidOrderOption(displayOrderMenu(sortO), sortO);
			cout << "Sorting order successfully set to '" << sortO << "'!" << endl;
			break;
		case 5:
			cout << endl
				 << "[ 5. View data ... ]" << endl
				 << " filtering criteria : " << filterC << endl
				 << " sorting criteria : " << sortC << endl
				 << " sorting order : " << sortO << endl
				 << endl;

			if (size == 0)
			{
				cout << "There is no data to view!" << endl
					 << "\t Please enter option 1 to read in data..."
					 << endl
					 << endl;
			}
			else
			{
				if (filterC.find("Point2D") == 0)
				{
					cout << setfill(' ') << setw(5) << "X"
						 << setfill(' ') << setw(6) << "Y"
						 << setfill(' ') << setw(10) << "    Quadrant"
						 << setfill(' ') << right << setw(19) << "Dist. Fr Origin"
						 << endl
						 << setfill('-') << setw(42) << "-" << endl;

					for (int i = 0; i < p2d.size(); i++)
					{
						p2d[i].setSort(sortC);
					}

					if (sortO == "ASC")
					{
						sort(p2d.begin(), p2d.end(), smallerThan<Point2D>);
					}
					else if (sortO == "DSC")
					{
						sort(p2d.begin(), p2d.end(), greaterThan<Point2D>);
					}

					vector<Point2D>::iterator p2IT;
					for (p2IT = p2d.begin(); p2IT != p2d.end(); p2IT++)
					{
						cout << *p2IT << endl;
					}
				}
				else if (filterC.find("Point3D") == 0)
				{
					cout << setfill(' ') << setw(5) << "X"
						 << setfill(' ') << setw(6) << "Y"
						 << setfill(' ') << setw(6) << "Z"
						 << setfill(' ') << setw(10) << "    Quadrant"
						 << setfill(' ') << right << setw(19) << "Dist. Fr Origin"
						 << endl
						 << setfill('-') << setw(48) << "-" << endl;

					for (int i = 0; i < p3d.size(); i++)
					{
						p3d[i].setSort(sortC);
					}

					if (sortO == "ASC")
					{
						sort(p3d.begin(), p3d.end(), smallerThan<Point3D>);
					}
					else if (sortO == "DSC")
					{
						sort(p3d.begin(), p3d.end(), greaterThan<Point3D>);
					}

					vector<Point3D>::iterator p3IT;
					for (p3IT = p3d.begin(); p3IT != p3d.end(); p3IT++)
					{
						cout << *p3IT << endl;
					}
				}
				else if (filterC.find("Line2D") == 0)
				{
					cout << setfill(' ') << setw(5) << "P1-X"
						 << setfill(' ') << setw(6) << "P1-Y"
						 << setfill(' ') << setw(9) << "P2-X" // including 3 spaces in between + 1 for [
						 << setfill(' ') << setw(6) << "P2-Y"
						 << setfill(' ') << right << setw(10) << "Length"
						 << endl
						 << setfill('-') << setw(37) << "-" << endl;

					for (int i = 0; i < l2d.size(); i++)
					{
						l2d[i].setSort(sortC);
					}

					if (sortO == "ASC")
					{
						sort(l2d.begin(), l2d.end(), smallerThan<Line2D>);
					}
					else if (sortO == "DSC")
					{
						sort(l2d.begin(), l2d.end(), greaterThan<Line2D>);
					}

					vector<Line2D>::iterator l2IT;
					for (l2IT = l2d.begin(); l2IT != l2d.end(); l2IT++)
					{
						cout << *l2IT << endl;
					}
				}
				else if (filterC.find("Line3D") == 0)
				{
					cout << setfill(' ') << setw(5) << "P1-X"
						 << setfill(' ') << setw(6) << "P1-Y"
						 << setfill(' ') << setw(6) << "P1-Z"
						 << setfill(' ') << setw(9) << "P2-X" // including 3 spaces in between + 1 for [
						 << setfill(' ') << setw(6) << "P2-Y"
						 << setfill(' ') << setw(6) << "P2-Z"
						 << setfill(' ') << right << setw(10) << "Length"
						 << endl
						 << setfill('-') << setw(50) << "-" << endl;

					for (int i = 0; i < l3d.size(); i++)
					{
						l3d[i].setSort(sortC);
					}

					if (sortO == "ASC")
					{
						sort(l3d.begin(), l3d.end(), smallerThan<Line3D>);
					}
					else if (sortO == "DSC")
					{
						sort(l3d.begin(), l3d.end(), greaterThan<Line3D>);
					}

					vector<Line3D>::iterator l3IT;
					for (l3IT = l3d.begin(); l3IT != l3d.end(); l3IT++)
					{
						cout << *l3IT << endl;
					}
				}
			}
			break;
		case 6:
			if (size == 0)
			{
				cout << "There is no data to store!" << endl
					 << "\t Please enter option 1 to read in data..."
					 << endl
					 << endl;
			}
			else
			{
				ok = false;
				do
				{
					cout << endl;
					cout << "[ 6. Store Data ]"
						 << endl
						 << endl
						 << "Please enter filename : ";
					cin >> filename;
					ok = writeFileOK(outfile, filename); // check ofstream ok for writing filename
				} while (ok == false);

				cout << "Begin the creation of " << filename << " file..." << endl;

				if (filterC.find("Point2D") == 0)
				{
					outfile << setfill(' ') << setw(5) << "X"
							<< setfill(' ') << setw(6) << "Y"
							<< setfill(' ') << right << setw(19) << "Dist. Fr Origin"
							<< endl
							<< setfill('-') << setw(30) << "-" << endl;

					for (int i = 0; i < p2d.size(); i++)
					{
						p2d[i].setSort(sortC);
					}

					if (sortO == "ASC")
					{
						sort(p2d.begin(), p2d.end(), smallerThan<Point2D>);
					}
					else if (sortO == "DSC")
					{
						sort(p2d.begin(), p2d.end(), greaterThan<Point2D>);
					}

					vector<Point2D>::iterator p2IT;
					for (p2IT = p2d.begin(); p2IT != p2d.end(); p2IT++)
					{
						outfile << *p2IT << endl;
					}
				}
				else if (filterC.find("Point3D") == 0)
				{
					outfile << setfill(' ') << setw(5) << "X"
							<< setfill(' ') << setw(6) << "Y"
							<< setfill(' ') << setw(6) << "Z"
							<< setfill(' ') << right << setw(19) << "Dist. Fr Origin"
							<< endl
							<< setfill('-') << setw(30) << "-" << endl;

					for (int i = 0; i < p3d.size(); i++)
					{
						p3d[i].setSort(sortC);
					}

					if (sortO == "ASC")
					{
						sort(p3d.begin(), p3d.end(), smallerThan<Point3D>);
					}
					else if (sortO == "DSC")
					{
						sort(p3d.begin(), p3d.end(), greaterThan<Point3D>);
					}

					vector<Point3D>::iterator p3IT;
					for (p3IT = p3d.begin(); p3IT != p3d.end(); p3IT++)
					{
						outfile << *p3IT << endl;
					}
				}
				else if (filterC.find("Line2D") == 0)
				{
					outfile << setfill(' ') << setw(5) << "P1-X"
							<< setfill(' ') << setw(6) << "P1-Y"
							<< setfill(' ') << setw(9) << "P2-X" // including 3 spaces in between + 1 for [
							<< setfill(' ') << setw(6) << "P2-Y"
							<< setfill(' ') << right << setw(10) << "Length"
							<< endl
							<< setfill('-') << setw(37) << "-" << endl;

					for (int i = 0; i < l2d.size(); i++)
					{
						l2d[i].setSort(sortC);
					}

					if (sortO == "ASC")
					{
						sort(l2d.begin(), l2d.end(), smallerThan<Line2D>);
					}
					else if (sortO == "DSC")
					{
						sort(l2d.begin(), l2d.end(), greaterThan<Line2D>);
					}

					vector<Line2D>::iterator l2IT;
					for (l2IT = l2d.begin(); l2IT != l2d.end(); l2IT++)
					{
						outfile << *l2IT << endl;
					}
				}
				else if (filterC.find("Line3D") == 0)
				{
					outfile << setfill(' ') << setw(5) << "P1-X"
							<< setfill(' ') << setw(6) << "P1-Y"
							<< setfill(' ') << setw(6) << "P1-Z"
							<< setfill(' ') << setw(9) << "P2-X" // including 3 spaces in between + 1 for [
							<< setfill(' ') << setw(6) << "P2-Y"
							<< setfill(' ') << setw(6) << "P2-Z"
							<< setfill(' ') << right << setw(10) << "Length"
							<< endl
							<< setfill('-') << setw(50) << "-" << endl;

					for (int i = 0; i < l3d.size(); i++)
					{
						l3d[i].setSort(sortC);
					}

					if (sortO == "ASC")
					{
						sort(l3d.begin(), l3d.end(), smallerThan<Line3D>);
					}
					else if (sortO == "DSC")
					{
						sort(l3d.begin(), l3d.end(), greaterThan<Line3D>);
					}

					vector<Line3D>::iterator l3IT;
					for (l3IT = l3d.begin(); l3IT != l3d.end(); l3IT++)
					{
						outfile << *l3IT << endl;
					}
				}

				outfile.close();
				cout << "Output file successfully generated" << endl;
			}
			break;
		case 7:
			cout << "Thank you for using Point & Line 2D & 3D coordinate system!" << endl;
		}

	} while (choice != 7);

	return 0;
}
