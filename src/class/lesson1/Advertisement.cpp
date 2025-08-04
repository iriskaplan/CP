// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

struct firstGreater{
    bool operator()(const pll l, const pll r) const { return l.first < r.first; }
};

int main() {
  ll max_area = 0;
  ll n;
  cin >> n;

  priority_queue<pll, vpll, firstGreater> heights;
  ll h;
  for (ll i =0; i < n; i++) {
    cin >> h;
    if (heights.empty()) {
      heights.emplace(h, i);
    } else {
      ll lowest_j = n+1;
      while (!heights.empty() && heights.top().first > h) {
        max_area = max(max_area, heights.top().first * (i-heights.top().second));
        lowest_j = min(heights.top().second, lowest_j);
        heights.pop();
      }
      if (!heights.empty() && heights.top().first == h) {
        lowest_j = min(heights.top().second, lowest_j);
        heights.pop();
      }
      if (lowest_j != n+1) {
        heights.emplace(h, lowest_j);
      } else {
        heights.emplace(h, i);
      }
    }
  }

  while(!heights.empty()){
    pll c = heights.top(); heights.pop();
    max_area = max(max_area, c.first * (n-c.second));
  }

  cout << max_area << "\n";
  return 0;
}