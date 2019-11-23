#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A)
{
    //write your code here
    int sum = 0;
    int i, j;
    int n = A.size();
    // Caculcate sun of all elements
    for (i = 0; i < n; i++)
    sum += A[i];

    if (sum == 0 || sum % 3 != 0)
        return 0;

    vector<vector<int>>  lPartition(sum / 3 + 1,vector<int>(n + 1));
    for (int i = 1; i <= sum / 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int diff = i - A[j - 1];
            if ((A[j - 1] == i) || (diff > 0 && lPartition[diff][j - 1] > 0))
            {
                lPartition[i][j] = (lPartition[i][j - 1] == 0) ? 1 : 2;
            }
            else
            {
                lPartition[i][j] = lPartition[i][j - 1];
            }
        }
    }

    if (lPartition[sum / 3][n] == 2)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i)
    {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}
