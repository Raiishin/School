#include <iostream>
#include <array>
#include <vector>
using namespace std;

void binarySearch(vector<int> v, int To_Find)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (hi - lo > 1)
    {
        mid = (hi + lo) / 2;
        if (v[mid] < To_Find)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[lo] == To_Find)
    {
        cout << "Found"
             << " At Index " << lo << endl;
    }
    else if (v[hi] == To_Find)
    {
        cout << "Found"
             << " At Index " << hi << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}

int main()
{
    vector<int> v = {1, 3, 4, 5, 6, 10};
    int To_Find = 1;
    binarySearch(v, To_Find);
    To_Find = 6;
    binarySearch(v, To_Find);
    To_Find = 10;
    binarySearch(v, To_Find);
    return 0;
}
