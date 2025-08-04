// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
  ll x;
  ll y;

  Point(ll x, ll y) : x(x), y(y) {}
};

ll ccw (const Point &a, const Point &b, const Point &c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}


int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll o = ccw(Point(a, b), Point(c, d), Point(e, f));
    if (o == 0) cout << "TOUCH\n";
    else if (o > 0) cout << "LEFT\n";
    else cout << "RIGHT\n";
  }
}


