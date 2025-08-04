// Created by Iris Kaplan.

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll MOD = 998244353;

ll mod_inv(ll v) {
  ll pow = MOD - 2;
  ll res = 1;
  while (pow > 0) {
    if (pow & 1)
      res = (res * v) % MOD;
    v = (v * v) % MOD;
    pow >>= 1;
  }
  return res;
}

int main () {
  ll t, n;
  cin >> t;

  for (ll i = 0; i < t;i++) {
    cin >> n;
    vector<int> arr (n, 0);
    ll ones = 0;
    for (ll j = 0; j < n;j++) {
      cin >> arr[j];
      if (arr[j] == 1){
        ones += 1;
      }
    }

    ll mis_ones = 0;
    for (ll j = 0; j < (n-ones); j++) {
      if (arr[j] == 1) {
        mis_ones += 1;
      }
    }

    ll common_mult = 1;
    ll j_sum = 0;
    ll num = (n * (n-1)) % MOD;
    for (ll j = 0; j < mis_ones; j++) {
      ll j_squared = (j+1) * (j+1) % MOD;
      common_mult = common_mult *  j_squared % MOD;
      j_sum = (j_sum + mod_inv(j_squared)) % MOD;
    }
    j_sum %= MOD;
    common_mult %= MOD;
    ll den =  2 * common_mult % MOD;

    ll sum_num = j_sum * common_mult % MOD;
    num =(num *  sum_num) % MOD;

    cout <<  num * mod_inv(den) % MOD << "\n";
  }

  return 0;
}
