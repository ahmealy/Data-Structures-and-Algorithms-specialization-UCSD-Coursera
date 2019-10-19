#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::multimap;

double get_optimal_value(long capacity, vector<long> weights, vector<long> values)
{
    double value = 0.0;

    // write your code here
    multimap<double, long, std::greater <double> > unitWtMap;

    for(long i = 0; i < weights.size(); i++)
    {
        unitWtMap.insert(std::make_pair((double)values[i]/(double)weights[i], i));
    }

    // begin() returns to the first value of map.
    multimap<double,long> :: iterator it;
    for (it=unitWtMap.begin() ; it!=unitWtMap.end() ; it++)
    {
        if(capacity == 0)   return value;

        if(weights[(*it).second] <= capacity)
        {
            capacity -= weights[(*it).second];
            value = value + (double)values[(*it).second];
        }
        else
        {
            value = value + (double)(*it).first * capacity;
            capacity = 0;
        }
    }
    return value;
}

int main()
{
    long n;
    long capacity;
    std::cin >> n >> capacity;
    vector<long> values(n);
    vector<long> weights(n);
    for (long i = 0; i < n; i++)
    {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
