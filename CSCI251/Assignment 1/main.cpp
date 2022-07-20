#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void displayCityMap(int xAxisLimit, int yAxisLimit, string cityLocationFilename)
{
    // TODO :: Build the grid row by row
    cout << "City Map: " << endl;

    for (int i = 0; i <= yAxisLimit; i++)
    {

        for (int j = 0; j <= xAxisLimit; j++)
        {
            if (j > 0)
                cout << "# ";
            if (i == yAxisLimit)
                cout << j;
        }

        cout << endl;
    }
}

int main()
{
    string filename = "";
    string line = "";
    vector<string> fileTextArray;

    fstream file;

    cout << "Please enter config filename : ";
    filename = "assets/config.txt";
    // cin >> filename;

    file.open(filename);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line.length() != 0 && line.find("//"))
                fileTextArray.push_back(line);
        }
        file.close();
    }
    else
        cout << "No such file can be found";

    int xAxisLimit = fileTextArray[0].back() - '0';
    int yAxisLimit = fileTextArray[1].back() - '0';

    string cityLocationFilename = "assets/" + fileTextArray[2];
    string cloudCoverFilename = "assets/" + fileTextArray[3];
    string pressureFilename = "assets/" + fileTextArray[4];

    // cout << xAxisLimit << endl;
    // cout << yAxisLimit << endl;
    // cout << cityLocationFilename << endl;
    // cout << cloudCoverFilename << endl;
    // cout << pressureFilename << endl;

    displayCityMap(xAxisLimit, yAxisLimit, cityLocationFilename);

    return 0;
}
