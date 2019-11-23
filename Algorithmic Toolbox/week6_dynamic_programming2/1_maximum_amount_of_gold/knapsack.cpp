#include <iostream>
#include <vector>

using std::vector;
using std::max;

using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
    //write your code here
    int current_weight = 0;
    for (size_t i = 0; i < w.size(); ++i)
    {
        if (current_weight + w[i] <= W)
        {
            current_weight += w[i];
        }
    }
    return current_weight;
}

int optimal_weight_db(int W, const vector<int> &w)
{
    //write your code here
    int n = w.size();
    vector<vector<int>>  optWtKnapsack(n + 1,vector<int>(W + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)  optWtKnapsack[i][j] = 0;
            else if (w[i - 1] <= j)
            {
                optWtKnapsack[i][j] = max(optWtKnapsack[i - 1][j - w[i - 1]] + w[i - 1], optWtKnapsack[i-1][j]);
            }
            else    optWtKnapsack[i][j] = optWtKnapsack[i - 1][j];
        }
    }

    return optWtKnapsack[n][W];
}

int main()
{
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> w[i];
    }
    std::cout << optimal_weight_db(W, w) << '\n';
}
