// Created by Iris Kaplan.

// Find Nearest Smaller Values for every element in an array
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef vector<ll> vl;

int main() {
  ll n;
  cin >> n;
  vl a(n);
  vl o(n);
  for (ll & x : a) cin >> x;

  stack<ll> st;

  for(ll i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] >= a[i]) {
      st.pop();
    }

    if (st.empty()) {
      o[i] = 0;
    } else {
      o[i] = st.top() + 1;
    }
    st.push(i);
  }

  for (ll & x : o) cout << x << " ";
  return 0;
}
