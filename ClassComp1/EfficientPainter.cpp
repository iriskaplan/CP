// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<ll, ll> pll;

struct interval {
  ll s;
  ll e;
};

int main() {
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);

  ll n, k;
  cin >> n >> k;
  vector<pll> events;

  ll pos = 0;

  for (ll i = 0; i < n; i++) {
    ll step;
    string dir;
    cin >> step >> dir;

    ll c_s = pos, c_e = pos;
    if (dir == "R") {
      c_e += step;
    } else {
      c_e -= step;
    }

    events.push_back(make_pair(min(c_s, c_e), 1));
    events.push_back(make_pair(max(c_s, c_e), -1));
    pos = c_e;
  }

  sort(events.begin(), events.end(), [](const pll& a, const pll& b) {
  return a.first < b.first;
  });


  ll painted = 0;
  ll active_intervals = 0;
  ll start = 0ll, end = 0ll;
  for (int i = 0; i < events.size(); i++) {
    pll event = events[i];

    if (event.second == 1) {
      active_intervals += 1;
    } else if (event.second == -1) {
      active_intervals -= 1;
    }

    if (i < (events.size() - 1) && event.first != events[i+1].first) {
      start = event.first;
      end = events[i+1].first;
      if (active_intervals >= k) {
          painted += end - start;
      }
    }
  }

  cout << painted << "\n";
  return 0;
}