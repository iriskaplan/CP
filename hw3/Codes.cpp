// Eliav, Liel & Iris

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio()                                                               \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);


int main() {
  fastio();

  int n = 1;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  ll gcd = 0;
  for (int i = 1; i < n; i++) {
    gcd = __gcd(gcd, abs(a[i] - a[i-1]));
  }
  for (ll k = 2; k*k <= gcd; k++) {
    if (gcd % k == 0) { 
      cout << k << " ";
      if (k*k == gcd) continue;
      cout << gcd / k << " ";
    }
  }
  cout << gcd << "\n";

  return 0;
}   
