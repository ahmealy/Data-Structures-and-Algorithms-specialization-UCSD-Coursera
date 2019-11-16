#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

int get_majority_element(vector<int> &a, int left, int right)
{
    if (left == right)
        return -1;
    if (left + 1 == right)
        return a[left];

    map<int, int> occurenceNum;
    int vecLen = a.size();
    for (int i = 0; i < vecLen; i++)
    {
        occurenceNum[a[i]]++;
    }

    for (int i = 0; i < vecLen; i++)
    {
        if (occurenceNum[a[i]] > (vecLen / 2))
            return a[i];
    }


    return -1;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cin >> a[i];
    }
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
