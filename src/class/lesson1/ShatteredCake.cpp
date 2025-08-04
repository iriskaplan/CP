// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll w, n;

  while (cin >> w >> n) {
    ll area = 0;
    ll w_i, l_i;
    for (ll i = 0; i < n; i++) {
      cin >> w_i >> l_i;
      area += w_i*l_i;
    }
    cout << (area / w) << "\n";
  }
  return 0;
}