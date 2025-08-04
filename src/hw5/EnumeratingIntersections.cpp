#include <bits/stdc++.h>

using namespace std;
using ll = long long;

typedef pair<ll, ll> pll;

void fastio() {
	ios::sync_with_stdio(0);
	cin.tie(0);
}

enum event_type {
	HORIZONTAL_START,
	HORIZONTAL_END,
	VERTICAL
  };

struct event {
	ll x1, y1, y2;
	event_type type;
};

int main() {
	ll n;
	cin >> n;

	vector<event> events;

	ll x1, x2, y1, y2;

	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		if (y1 == y2) {
			events.push_back({ x1, y1, y2, HORIZONTAL_START });
			events.push_back({ x2, y1, y2, HORIZONTAL_END });
		} else if (x1 == x2) {
			events.push_back({ x1, y1, y2, VERTICAL });
		}
	}

	// Sort events by x coordinate
	sort(events.begin(), events.end(), [](auto &a, auto &b) {
	  if (a.x1 != b.x1)
	  	return a.x1 < b.x1;

		ll a_score = a.type == HORIZONTAL_START ? 1 : a.type == VERTICAL ? 2 : 3;
		ll b_score = b.type == HORIZONTAL_START ? 1 : b.type == VERTICAL ? 2 : 3;

		return a_score < b_score;
	  });

	vector<ll> horizontal_lines;

	ll intersections = 0;

	for (auto &event : events) {
		if (event.type == HORIZONTAL_START) {
			auto pos = lower_bound(horizontal_lines.begin(), horizontal_lines.end(), event.y1);
			horizontal_lines.insert(pos, event.y1);
		} else if (event.type == HORIZONTAL_END) {
			auto pos = lower_bound(horizontal_lines.begin(), horizontal_lines.end(), event.y1);

			if (pos != horizontal_lines.end())
				horizontal_lines.erase(pos);
		} else if (event.type == VERTICAL) {
			auto lower = lower_bound(horizontal_lines.begin(), horizontal_lines.end(), event.y1);
			auto upper = upper_bound(horizontal_lines.begin(), horizontal_lines.end(), event.y2);

			if (lower <= upper)
				intersections += (upper - lower);
		}
	}

	cout << intersections << '\n';
	return 0;
}