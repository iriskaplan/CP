// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
	ll x;
	ll y;

	Point(ll x, ll y) : x(x), y(y) {}
};

ll direction (const Point &a, const Point &b, const Point &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool on_segment(Point a, Point b, Point p) {
	return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
		   min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

bool segments_intersect(Point p1, Point p2, Point p3, Point p4) {
	ll d1 = direction(p3, p4, p1);
	ll d2 = direction(p3, p4, p2);
	ll d3 = direction(p1, p2, p3);
	ll d4 = direction(p1, p2, p4);

	if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
		((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
		return true;
		}
	if (d1 == 0 && on_segment(p3, p4, p1)) return true;
	if (d2 == 0 && on_segment(p3, p4, p2)) return true;
	if (d3 == 0 && on_segment(p1, p2, p3)) return true;
	if (d4 == 0 && on_segment(p1, p2, p4)) return true;

	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b, c, d, e, f, g, h;
		cin >> a >> b >> c >> d >> e >> f >> g >> h;
		ll o = segments_intersect(Point(a, b), Point(c, d),
			Point(e, f), Point(g,h));
		if (o == true) cout << "YES\n";
		else cout << "NO\n";
	}
}



