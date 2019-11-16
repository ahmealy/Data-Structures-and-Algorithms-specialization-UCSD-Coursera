#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <float.h>
#include<time.h>
#include <cassert>

using std::vector;
using std::string;
using std::pair;
using std::min;

#define DEBUG 0
#define TEST 0
using namespace std;
// Needed to sort array of points
// according to X coordinate
int compareX(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.first < j.first;
}

// Needed to sort array of points according to Y coordinate
int compareY(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

// A utility function to find the
// distance between two points
float dist(std::pair<int, int> p1, std::pair<int, int> p2)
{
    return sqrt( (p1.first - p2.first)*(p1.first - p2.first) +
                 (p1.second - p2.second)*(p1.second - p2.second)
               );
}

// A Brute Force method to return the
// smallest distance between two points
// in P[] of size n
float bruteForce(vector<std::pair<int, int>> points, int left, int right)
{
    float min = (left == right) ? (dist(points[left], points[right])) : FLT_MAX;
    //int n = right - left + 1;
    for (int i = left; i <= right; ++i)
        for (int j = i+1; j <= right; ++j)
            if (dist(points[i], points[j]) < min)
                min = dist(points[i], points[j]);
    return min;
}

// A utility function to find
// minimum of two float values
float min(float x, float y)
{
    return (x < y)? x : y;
}


// A utility function to find the
// distance beween the closest points of
// strip of given size. All points in
// strip[] are sorted accordint to
// y coordinate. They all have an upper
// bound on minimum distance as d.
// Note that this method seems to be
// a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(vector<std::pair<int, int>> strip, float d)
{
    float min = d; // Initialize the minimum distance as d
    if(DEBUG)
        cout << "size " << strip.size() << " d min "  << d<< endl;
    sort(strip.begin(), strip.end(), compareY);
     if(DEBUG)
     {
         cout << "strip " << endl;
         for (int i = 0; i < strip.size(); ++i)
         {
              cout << "strip i " << strip[i].first << " " << strip[i].second << endl;
         }
     }
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < strip.size(); ++i)
        for (int j = i+1; j < strip.size() && (strip[j].second - strip[i].second) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

// A recursive function to find the
// smallest distance. The array P contains
// all points sorted according to x coordinate
float closestUtil(vector<std::pair<int, int>> points, int left, int right)
{
    if(DEBUG)
        cout << "left " << left << "right " << right  << endl;
    // If there are 2 or 3 points, then use brute force
    int n = right - left + 1;
    if (n <= 3)
        return bruteForce(points, left, right);

    // Find the middle point
    int mid = (left+right)/2;
    pair<int, int> midPoint = points[mid];

    // Consider the vertical line passing
    // through the middle point calculate
    // the smallest distance dl on left
    // of middle point and dr on right side
    float dl = closestUtil(points, left, mid);
    if(DEBUG)
        cout << "dl " << dl << endl;
    float dr = closestUtil(points, mid + 1, right);
    if(DEBUG)
        cout << "dr " << dr << endl;
    // Find the smaller of two distances
    float d = min(dl, dr);
    if(DEBUG) cout << "d " << d  << "mid " << mid << endl;
    // Build an array strip[] that contains
    // points close (closer than d)
    // to the line passing through the middle point
    std::vector<std::pair<int, int>> strip;
    //strip.reserve(n);
    //int j = 0;
    for (int i = left; i <= right; i++)
    {
        if (abs(points[i].first - midPoint.first) < d)
        {
            strip.push_back(points[i]);
        }
    }

    // Find the closest points in strip.
    // Return the minimum of d and closest
    // distance is strip[]
    return min(d, stripClosest(strip, d) );
}

double minimal_distance(vector<std::pair<int, int>> points)
{
    //write your code here
    sort(points.begin(), points.end(), compareX);
    // Use recursive function closestUtil()
    // to find the smallest distance
    return closestUtil(points, 0, points.size()-1);
}

void test_solution()
{
    int n;

    /* initialize random seed: */
    srand (time(NULL));
    while(1)
    {
        std::vector<std::pair<int, int>> points;
        /* generate secret number between 1 and 10: */
        n = rand() % 10 + 1;
        vector<int> x(n);
        vector<int> y(n);
        for (int i = 0; i < n; i++)
        {
            x[i] = rand() % 100 +1;
            y[i] = rand() % 100 +1;
        }


        /*points.reserve(x.size());
        std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(points),
                       [](int a, int b)
        {
            return std::make_pair(a, b);
        });*/
        for (int i = 0; i < n; i++)
        {
            points.push_back(std::make_pair(x[i], y[i]));
        }
        int brute = bruteForce(points,0,points.size()-1);
        int fast = minimal_distance(points);
        if(brute != fast)
        {
            cout << "n " << n << endl;
            cout <<" brute " << brute << " fast " << fast << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "xi " << x[i] << " yi" << y[i] << " points[i].first " << points[i].first << " points[i].second " << points[i].second <<endl;
            }
        }
        assert(brute == fast);
    }

}

int main()
{
    if(TEST)
        test_solution();
    else
    {
        size_t n;
        std::cin >> n;
        vector<int> x(n);
        vector<int> y(n);
        for (size_t i = 0; i < n; i++)
        {
            std::cin >> x[i] >> y[i];
        }

        std::vector<std::pair<int, int>> points;
        //points.reserve(x.size());
        /*std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(points),
                       [](int a, int b)
        {
            return std::make_pair(a, b);
        });*/
        for (int i = 0; i < n; i++)
        {
            points.push_back(std::make_pair(x[i], y[i]));
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(9) << minimal_distance(points) << "\n";

    }
}
