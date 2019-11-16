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
#include <complex>
#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::pair;
using std::min;

#define DEBUG 0
#define TEST 0
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define sz(v)       ((int)((v).size()))
#define clr(v, d)     memset(v, d, sizeof(v))
#define repi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define repa(v)       repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)     repi(i, 0, sz(v))
#define lp(i, cnt)      repi(i, 0, cnt)
#define lpi(i, s, cnt)    repi(i, s, cnt)
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
#define pb          push_back
#define MP          make_pair

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef long double ld;

const double OO = 1e8;  //Small -> WRONG, Large -> OVERFLOW

const double PI = acos(-1.0);
const double EPS = (1e-8);


typedef complex<double> point;
#define X real()
#define Y imag()
#define vec(a,b)                ((b)-(a))
#define length(a)               (hypot((a).imag(), (a).real()))

int dcmp(double x, double y)
{
    return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
struct cmpX
{
    bool operator()(const point &a, const point &b)
    {
        if (dcmp(a.X, b.X) != 0)
            return dcmp(a.X, b.X) < 0;
        return dcmp(a.Y, b.Y) < 0;
    }
};

struct cmpY
{
    bool operator()(const point &a, const point &b)
    {
        if (dcmp(a.Y, b.Y) != 0)
            return dcmp(a.Y, b.Y) < 0;
        return dcmp(a.X, b.X) < 0;
    }
};

// A utility function to find the
// distance between two points
double dist(point p1, point p2)
{
    return sqrt( (p1.X - p2.X)*(p1.X - p2.X) +
                 (p1.Y - p2.Y)*(p1.Y - p2.Y)
               );
}

double closestPair1(vector<point> &eventPts)
{
    double d = OO;
    multiset<point, cmpY> activeWindow;
    sort(eventPts.begin(), eventPts.end(), cmpX());

    int left = 0;
    for (int right = 0; right < (int) eventPts.size(); ++right)
    {
        while (left < right && eventPts[right].X - eventPts[left].X > d)
            activeWindow.erase(activeWindow.find(eventPts[left++]));
        auto asIt = activeWindow.lower_bound(point(-OO, eventPts[right].Y - d));
        auto aeIt = activeWindow.upper_bound(point(-OO, eventPts[right].Y + d));
        for (; asIt != aeIt; asIt++)
            d = min(d, dist(eventPts[right] , *asIt));
        activeWindow.insert(eventPts[right]);
    }
    return d;
}

// A Brute Force method to return the
// smallest distance between two points
// in P[] of size n
float bruteForce(vector<point> &eventPts, int n)
{
    float min = FLT_MAX;
    //int n = right - left + 1;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(eventPts[i], eventPts[j]) < min)
                min = dist(eventPts[i], eventPts[j]);
    return min;
}

void test_solution()
{
    int n;

    /* initialize random seed: */
    srand (time(NULL));
    while(1)
    {
        n = rand() % 10 + 2;
        /* generate secret number between 1 and 10: */
        vector<int> x(n);
        vector<int> y(n);
        for (int i = 0; i < n; i++)
        {
            x[i] = rand() % 10 +1;
            y[i] = rand() % 10 +1;
        }


        vector<point> eventPts(n);

        for (int i = 0; i < n; ++i)
        {

            eventPts[i] = point(x[i], y[i]);
        }

        int brute = bruteForce(eventPts,n);
        int fast = closestPair1(eventPts);
        if(brute != fast)
        {
            cout << "n " << n << endl;
            cout <<" brute " << brute << " fast " << fast << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "xi " << x[i] << " yi" << y[i] << " eventPts[i].x " << eventPts[i].X << " eventPts[i].y " << eventPts[i].Y <<endl;
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

        vector<point> eventPts(n);

        for (int i = 0; i < n; ++i)
        {

            eventPts[i] = point(x[i], y[i]);
        }

        std::cout << std::fixed;
        std::cout << std::setprecision(9) << closestPair1(eventPts) << "\n";

    }
}
