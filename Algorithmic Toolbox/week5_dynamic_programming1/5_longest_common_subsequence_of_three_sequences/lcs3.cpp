#include <iostream>
#include <vector>

using std::vector;
using std::max;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int m = a.size();
    int n = b.size();
    int o = c.size();
    //write your code here
    vector<vector<vector<int>>> LCM3(m + 1,vector<vector<int>>(n + 1,vector<int>(o + 1)));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= o; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    LCM3[i][j][k] = 0;
                    continue;
                }
                else if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
                {
                    LCM3[i][j][k] = LCM3[i - 1][j - 1][k - 1] + 1;
                    continue;
                }
                else
                {
                    LCM3[i][j][k] =
                        max( max(LCM3[i - 1][j][k], LCM3[i][j - 1][k]),
                             LCM3[i][j][k - 1]);
                }
            }

        }
    }
    return LCM3[m][n][o];
}

int main()
{
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++)
    {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++)
    {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++)
    {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}

