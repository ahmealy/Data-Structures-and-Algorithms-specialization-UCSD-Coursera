#include <iostream>
#include <vector>

using std::vector;
using std::max;

int lcs2(vector<int> &a, vector<int> &b)
{
    //write your code here
    int m = a.size();
    int n = b.size();
    vector<vector<int>> LCS(m + 1,vector<int>(n + 1));
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = 0;

            else if (a[i - 1] == b[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;

            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    return LCS[m][n];
}

int main()
{
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}
