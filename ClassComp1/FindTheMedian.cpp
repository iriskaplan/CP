// Created by Iris Kaplan.
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll values_smaller_then(ll v, ll n) {
  ll count = 0;
  for (ll i = 1; i <= n; i++) {
    count += min(n, v / i);
  }
  return count;
}

int main() {
  ll n;
  cin >> n;

  ll low = 1, high = n * n, mid;
  // search the smallest value between 1 and n^2 such that f(x) >= (n^2+1)/2 and x is mult of n
  while (low < high){
    mid = (low + high) / 2 ;
    if (values_smaller_then(mid, n) >= (n*n + 1)/2) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  cout << high << "\n";
  return 0;
}