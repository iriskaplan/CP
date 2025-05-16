// Created by Iris Kaplan.

#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;


int main() {
  ll n;
  int k;
  cin >> n >> k;

  vector<pair<ll, ll>> ranges;
  for (int i=0; i < k; i++) {
      ll a, b;
      cin >> a >> b;
      ranges.emplace_back(a, b);
  	}

    vector<ll> dp(k+1, 0);

  	sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {
      return a.second < b.second;
    });

    for(int j = 1; j <= k; j++) {
      ll s_j = ranges[j-1].first;
      ll len_j = ranges[j-1].second - ranges[j-1].first + 1;

      auto it = lower_bound(ranges.begin(), ranges.begin() + j, s_j, [](const pair<ll, ll> &a, const ll b) {
          return a.second < b;
      });

      dp[j] = max(dp[j-1], dp[int(it - ranges.begin())] + len_j);
    }

    cout << n - dp[k] << "\n";

  return 0;
}