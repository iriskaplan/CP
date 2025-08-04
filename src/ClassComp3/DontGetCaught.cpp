// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
typedef vector<ll> vl;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  ll n;
  cin >> n;
  vl fr(n);
  vl en(n);
  for(auto& x : fr) cin >> x;
  for(auto& x : en) cin >> x;

  // 0 - eng, 1 - fr from fr, 2 - fr from en
  vector<vl> dp (n, vl(3,0));

  dp[0][0] = en[0];
  dp[0][1] = fr[0];
  dp[0][2] = fr[0];

  for (ll i = 1; i < n; i++) {
    dp[i][0] = en[i] + max(max(dp[i-1][1], dp[i-1][2]), dp[i-1][0]);
    dp[i][1] = fr[i] + dp[i-1][0];
    dp[i][2] = fr[i] + dp[i-1][1];
  }
  cout << max(max(dp[n-1][1], dp[n-1][2]), dp[n-1][0]) << "\n";
  return 0;
}