
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
typedef vector<ll> vll;

ll f (vll& h, vll& c, ll x) {
  ll cost = 0;
  for(ll i=0; i < h.size(); i++) {
    cost += abs(h[i]- x) * c[i];
  }
  return cost;
}

ll ternary_search_cost(vll& h, vll& c) {
  ll l = 0, r = 10000;
  while (r - l > 3) {
    ll m1 = l + (r - l) / 3;
    ll m2 = r - (r - l) / 3;
    ll f1 = f(h, c, m1);
    ll f2 = f(h, c, m2);
    if (f1 < f2)
      r = m2;
    else
      l = m1;
  }
  ll min_c = LLONG_MAX;
  ll le = min(l,r);
  ll re = max(l,r);
  for(ll i = le; i <= re; i++){
    min_c = min(min_c, f(h,c,i));
  }
  return min_c; // min f(x) in [l, r]
}

int main() {
  ll j, k, t, n;
  cin >> t;
  for(k =0; k < t; k++) {
    cin >> n;
    vll h (n,0);
    vll c (n,0);
    for(j=0; j < n; j++) {
      cin >> h[j];
    }
    for(j=0; j < n; j++) {
      cin >> c[j];
    }
    cout << ternary_search_cost(h,c) << "\n";
  }
  return 0;
}