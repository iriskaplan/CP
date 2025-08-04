// Created by Iris Kaplan.

#include <bits/stdc++.h>

#define ff(i, a, b) for (ll i = (a); i <= (b); i++)

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MAX_SIZE = 1e6;

ll coefs[MAX_SIZE + 1];
ll inv[MAX_SIZE + 1];

using namespace std;

ll binpow(ll a, ll b) {
  ll res =1;
  while (b>0) {
    if (b&1) {
      res = (res * a) % MOD;
    }
    a = (a*a) % MOD;
    b >>= 1;
  }
  return res % MOD;
}

int main() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> a_b_s (n, make_pair(0,0));
  ll max_val = 0;
  ff(i, 0, n-1) {
    cin >> a_b_s[i].first >> a_b_s[i].second;
    max_val = max(max_val, max(a_b_s[i].first, a_b_s[i].second));
  }

  coefs[0] = 1;
  ff(i, 1, max_val) {
    coefs[i] = (i * coefs[i-1]) % MOD;
  }

  ll a,b;
  ff(i, 0, n-1) {
    a = a_b_s[i].first; b = a_b_s[i].second;
    ll num = coefs[a];
    cout << (num * binpow(coefs[b], MOD - 2) % MOD * binpow(coefs[a-b], MOD - 2)%MOD) % MOD << "\n";
  }

  return 0;
}
