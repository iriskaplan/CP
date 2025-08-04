// Created by Iris Kaplan.

#include <bits/stdc++.h>

#define ff(i,a,b) for(ll i=a;i<=b;i++)

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
  ll a1 = max(a,b);
  ll b1 = min(a,b);
  return b1 == 0 ? a1 : gcd(b1, a1 % b1);
}


int main() {
  int n;
  cin >> n;
  vector<ll> nums(n,0ll);

  ll cnt1 = 0;
  ff(i,0,n-1) {
    cin >> nums[i];
    if (nums[i] == 1) cnt1 += 1;
  }
  ll min_len = LLONG_MAX;
  if (cnt1 > 0) {
    cout << n-cnt1 << "\n";
    return 0;
  }

  for (ll j = 0; j < n - 1; j++) {
    ll g = nums[j];
    for (ll k = j+1; k < n; k ++) {
      g = gcd(g, nums[k]);
      if (g == 1 && (k-j) < min_len) {
        min_len = k-j;
      }
    }
  }
  if (min_len < LLONG_MAX) {
    cout << (min_len) + (n-1) << "\n";
  } else {
    cout << -1 << "\n";
  }

  return 0;
}