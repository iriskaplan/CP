// Iris Kaplan (Burmistrov).

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Point {
  public:
      int x;
      int y;

      Point(int x_v, int y_v): x(x_v), y(y_v) {}
};

bool sort_by_x(const Point a, const Point b) {
  return a.x < b.x;
}

bool sort_by_y(const Point a, const Point b) {
    return a.y < b.y;
}

long long best_area(const vector<Point> &ordered_points, const int n) {
    long long best_area = 0;

    int min_x = INT_MAX;
    int max_x = INT_MIN;
    int min_y = INT_MAX;
    int max_y = INT_MIN;

    // area l to r
    vector<long long> area_ltr;
    for (int i = 0; i < n; i++) {
        min_x = min(min_x, ordered_points[i].x);
        max_x = max(max_x, ordered_points[i].x);
        min_y = min(min_y, ordered_points[i].y);
        max_y = max(max_y, ordered_points[i].y);
        area_ltr.push_back((max_x - min_x) * (max_y - min_y));
    }

    // area r to l
    vector<long long> area_rtl;
    min_x = INT_MAX;
    max_x = INT_MIN;
    min_y = INT_MAX;
    max_y = INT_MIN;
    for (int i = n-1; i >= 0; i--) {
        min_x = min(min_x, ordered_points[i].x);
        max_x = max(max_x, ordered_points[i].x);
        min_y = min(min_y, ordered_points[i].y);
        max_y = max(max_y, ordered_points[i].y);
        area_rtl.push_back((max_x - min_x) * (max_y - min_y));
    }

    long long no_split_area = area_ltr[n-1];

    reverse(area_rtl.begin(), area_rtl.end());

    for (int i = 0; i < n-1; i++) {
        best_area = max(best_area, no_split_area - (area_ltr[i] + area_rtl[i+1]));
    }
    return best_area;
}

int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    int n;
    cin >> n;

    vector<Point> points;
    int p1, p2;

    for (int i = 0; i < n; i ++) {
        cin >> p1 >> p2;
        points.emplace_back(p1, p2);
    }

    vector<Point> points_by_x = points;
    sort(points_by_x.begin(), points_by_x.end(), sort_by_x);
    long long best_x = best_area(points_by_x, n);

    vector<Point> points_by_y = points;
    sort(points_by_y.begin(), points_by_y.end(), sort_by_y);
    long long best_y = best_area(points_by_y, n);
    cout << max(best_x, best_y) << "\n";
    return 0;
}
