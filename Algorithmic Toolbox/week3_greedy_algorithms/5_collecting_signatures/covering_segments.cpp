#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment
{
    int start, end;
};

bool SegmentCompare(const Segment &xFirst, const Segment &xSecond)
{
    return xFirst.end < xSecond.end;
}

vector<int> optimal_points(vector<Segment> &segments)
{
    vector<int> points;
    //write your code here
    std::sort(segments.begin(), segments.end(), SegmentCompare);
    int point = -1;
    for (Segment segment : segments) {
        if (!(point >= segment.start && point <= segment.end)) {
            point = segment.end;
            points.push_back(point);
        }
    }
    return points;
}

int main()
{
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i)
    {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i)
    {
        std::cout << points[i] << " ";
    }
}
