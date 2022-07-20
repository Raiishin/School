// Pseudocode
// > order list in asc O(n)
// > iterate through the ordered list O(n)
// > binary search to find if squared number exists O(log n)
//   > If true, push [number,squared number] into list

// Return list

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    list<int> numbers = {16, 9, 4, 7, 8, 3, 2, 3};
    numbers.sort();

    list<int> validNumberPairs;
    int counter = 0;
    for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
    {
        int squared = *it * *it;
        cout << squared;

        if (it != numbers.end())
        {
            validNumberPairs.push_back(*it, squared);
        }

        cout << "\n";
        ++counter;
    }

    // for (auto const &i : numbers)
    // {
    //     int squared = i * i;
    //     list<int>::iterator it = std::find(numbers.begin(), numbers.end(), squared);

    //     if (it != numbers.end())
    //     {
    //         cout << it;
    //     }
    // }

    return 0;
}