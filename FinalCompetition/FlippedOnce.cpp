// Problem: https://qoj.ac/problem/2418

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i= a; i<(b); ++i)
#define all(x) begin(x), end(x)

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;

  vector<ll> a(n);
  for (auto& x: a) cin >> x;
  ll l = 0, r;
  for (ll i = 1; i < n; i++) {
    if (a[i] > a[i-1]) {
      l = i;

    } else if (a[i] < a[i-1]) {
      break;
    }
  }

  r = l;
  while (r + 1 < n && a[r] >= a[r+1]) r++;

  reverse(a.begin() + l, a.begin() + r + 1);

  if (is_sorted(a.begin(), a.end())) {
    cout << l + 1 << " " << r + 1 << "\n";
  } else {
  cout << "impossible" << "\n";
  }
  return 0;
}
