// Created by Iris Kaplan.


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Throne https://vjudge.net/problem/AtCoder-abc186_e
//const int INF = 1e9;

ll mod(ll a, ll b) {
  return ((a%b) + b) % b;
}

ll gcd(ll a, ll b) {
  ll a1 = max(a,b);
  ll b1 = min(a,b);
  return b1 == 0 ? a1 : gcd(b1, a1%b1);
}

ll extended_euclid(ll a, ll b, ll& x, ll& y) {
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {
    ll q = a / b;
    ll t=b; b = a%b; a=t;
    t=xx; xx = x - q*xx; x=t;
    t=yy; yy = y - q*yy; y=t;
  }
  return a;
}

int main () {
  int t;
  cin >> t;
  for (int p=0;p < t;p++) {
    ll n, s, k;
    cin >> n >> s >> k;

    ll b = n - s;
    ll g = gcd(k, n);

    if (b % g != 0) {
      cout << -1 << "\n";
    } else {
      ll xp, yp;
      g = extended_euclid(k, n, xp, yp);
      ll x = b * xp / g;
      cout << mod(x ,n/g) << "\n";
    }
  }

  return 0;
}