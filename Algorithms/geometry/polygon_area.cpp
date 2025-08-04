// Created by Iris Kaplan.

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i= a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> Matrix;

struct Point {
  ll x;
  ll y;

  Point(ll x, ll y) : x(x), y(y) {}
  Point() : x(0), y(0) {}
};

__int128 cross(const Point& a, const Point& b) {
  return (__int128)a.x * b.y - (__int128)a.y * b.x;
}

ll polygon_area(const vector<Point>& pts) {
  int n = pts.size();
  __int128 acc = 0;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    acc += cross(pts[i], pts[j]);
  }
  if (acc < 0) acc = -acc;
  return acc;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  ll x, y;
  vector<Point> points(n);

  for (int i = 0; i < n; i ++) {
    cin >> x >> y;
    points[i] = Point(x,y);
  }

  ll area = polygon_area(points);
  cout << area;
}
