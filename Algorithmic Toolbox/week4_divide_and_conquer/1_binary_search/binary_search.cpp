#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
int binarySearch(const vector<int> &a, int left, int right, int x);
int binary_search(const vector<int> &a, int x)
{
    int left = 0, right = (int)a.size();
    //write your code here
    return binarySearch(a, left, right-1, x);
}

int binarySearch(const vector<int> &a, int left, int right, int x)
{
    if(left <= right)
    {
        int lMiddle = left + (right - left)/2;
        if(a[lMiddle] == x)
            return lMiddle;


        if(x < a[lMiddle])
            return binarySearch(a, left, lMiddle-1, x);
        else
            return binarySearch(a, lMiddle + 1, right, x);

    }
    return -1;
}
int linear_search(const vector<int> &a, int x)
{
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }
    for (int i = 0; i < m; ++i)
    {
        //replace with the call to binary_search when implemented
        std::cout << binary_search(a, b[i]) << ' ';
    }
}
