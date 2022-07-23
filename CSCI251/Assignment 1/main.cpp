#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void split(string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= str.length())
    {
        if (str[i] == seperator || i == str.length())
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;

            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

void displayCityMap(int xAxisLimit, int yAxisLimit, string cityLocationFilename)
{
    // TODO :: Build the grid row by row
    cout << "City Map: " << endl;

    cout << "  ";

    // Print top row
    for (int i = 0; i <= yAxisLimit + 2; i++)
    {
        cout << "# ";
    }

    cout << endl;

    for (int i = 1; i <= yAxisLimit + 2; i++)
    {
        int edge = yAxisLimit - i;

        // Print first 2 columns
        if (edge >= 0)
        {
            cout << edge;
            cout << " # ";
        }

        // Print bottom left corner
        if (edge == -1)
            cout << "  # ";

        // Indent for bottom row
        if (edge == -2)
            cout << "    ";

        for (int j = 0; j <= xAxisLimit + 2; j++)
        {
            // Print bottom margin row
            if (i == yAxisLimit + 1)
            {
                cout << "#";
            }

            // Print bottom row
            if (i == yAxisLimit + 2 && j <= xAxisLimit + 1)
            {
                cout << j;
                cout << " ";
            }
            else
            {
                if (j >= xAxisLimit - 1)
                    cout << " ";
                else if (j >= 0)
                    cout << " ";
                else if (j < 0)
                    cout << j;
            }
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

    file.open(cityLocationFilename);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            split(line, '-');
            cout << line << endl;
        }
        file.close();
    }
    else
        cout << "No such file can be found";

    string cloudCoverFilename = "assets/" + fileTextArray[3];
    string pressureFilename = "assets/" + fileTextArray[4];

    // cout << xAxisLimit << endl;
    // cout << yAxisLimit << endl;
    // cout << cityLocationFilename << endl;
    // cout << cloudCoverFilename << endl;
    // cout << pressureFilename << endl;

    // displayCityMap(xAxisLimit, yAxisLimit, cityLocationFilename);

    return 0;
}
