// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

int main() {
  ll t, n;
  cin >> t;

  for (ll i = 0; i < t; i++) {
    cin >> n;
    vpll ranges(n);
    ll l, r;
    for (ll j = 0; j < n; j++) {
      cin >> l >> r;
      ranges[j] = make_pair(l, r);
    }

    sort(ranges.begin(), ranges.end(), [](const pll &a, const pll &b){
      return a.first < b.first;
    });

    bool is_possible = true;
    ll idx = 0;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for(ll j = 0; j < n; j++) {
      ll pos = max(last+1, ranges[j].first);
      if (pos > ranges[j].second) {
        is_possible = false;
        break;
      }

      last = pos;
    }
    cout << (is_possible ? "Yes" : "No") << "\n";
  }
  return 0;
}