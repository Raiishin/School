#ifndef A3_H
#define A3_H
#include "MyTemplates.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAX = 100; // size of vector objects

// describes a sample interaction between the main menu and ‘Input sensor data’ sub-menu
int displayMenuOptions(string, string, string);

// check validity of menu option only 1 to 5
int checkValidOption(int, string, string, string);

// Prompt user to enter a filename
// check file is valid
bool readFileOK(fstream &, string);

// convert string to all lowercase
char to_lowercase(char);

// doesnt work as it will include duplicate records
// get no of records in file
int getSizeOfRecords(fstream &);

char displayFilterMenu(string);

// check validity of menu option only a to d
string checkValidOption(char, string);

char displaySortMenu(string, string);

// check validity of menu option only a to c or a to d depending on type
string checkValidSortOption(char, string, string);

char displayOrderMenu(string);

// check validity of menu option only a and b
string checkValidOrderOption(char, string);

// Prompt user to enter a filename
// check file is valid
bool writeFileOK(fstream &, string);

// Check Point2D no duplication
bool checkp2d(Point2D, vector<Point2D>);

bool checkp2d(Point2D, Point2D);

// Check Point3D no duplication
bool checkp3d(Point3D, vector<Point3D>);

bool checkp3d(Point3D, Point3D);

// Check Line2D no duplication
bool checkl2d(Line2D, vector<Line2D>);

// Check Line3D no duplication
bool checkl3d(Line3D, vector<Line3D>);

#endif
