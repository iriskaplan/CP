#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
	ll x;
	ll y;
};

int main() {
	int n;
	cin >> n;
	vector<Point> points(n);
	for (int i = 0; i < n; i++) { cin >> points[i].x >> points[i].y; }

	auto cmp = [](const Point &a, const Point &b) {
		return atan2l(a.y, a.x) < atan2l(b.y, b.x);
	};
	sort(points.begin(), points.end(), cmp);

	for (int i = 0; i < n; i++) { cout << points[i].x << " " << points[i].y << "\n"; }
}