#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

// incorrect: moving from 𝑛 to min{𝑛/3, 𝑛/2, 𝑛 − 1} is not safe.
vector<int> optimal_sequence(int n)
{
    std::vector<int> sequence;
    while (n >= 1)
    {
        sequence.push_back(n);
        if (n % 3 == 0)
        {
            n /= 3;
        }
        else if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = n - 1;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

vector<int> optimal_sequence_db(int xNum)
{
    std::vector<int> sequence;
    vector<int> minNumOperartions(xNum + 1, INT_MAX);

    minNumOperartions[0] = 0;

    for(int m = 1; m <= xNum; m++)
    {
        int lNumOperations = minNumOperartions[ m - 1] + 1;
        if(m % 2 == 0)
            lNumOperations = min(lNumOperations, minNumOperartions[ m / 2] + 1);
        if(m % 3 == 0)
            lNumOperations = min(lNumOperations, minNumOperartions[ m / 3] + 1);

        if(lNumOperations < minNumOperartions[m])
            minNumOperartions[m] = lNumOperations;
    }
    int n = xNum;
    while (n > 0)
    {
        sequence.push_back(n);
        if (minNumOperartions[n - 1] == minNumOperartions[n] - 1)
            n = n - 1;
        else if ((n % 2 == 0) && (minNumOperartions[n / 2] == minNumOperartions[n] - 1))
            n = n / 2;
        else if ((n % 3 == 0) && (minNumOperartions[n / 3] == minNumOperartions[n] - 1))
            n = n / 3;
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence_db(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        std::cout << sequence[i] << " ";
    }
}
