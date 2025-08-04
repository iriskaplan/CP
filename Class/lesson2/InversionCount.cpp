// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

typedef vector<ll> vl;

void merge(vl& a, ll left, ll mid, ll right) {
  ll i = left;
  ll j = mid+1;
  vl c;

  while (i <= mid && j <= right) {
      if (a[i] <= a[j]) {
        c.push_back(a[i]);
        i++;
      } else {
        c.push_back(a[j]);
        j++;
      }
    }
  while (i <= mid) {
    c.push_back(a[i]);
    i++;
  }
  while (j <= right) {
    c.push_back(a[j]);
    j++;
  }
  for (ll p = 0; p < c.size(); p++) {
    a[left+p] = c[p];
  }
}

void merge_sort(vl& a, ll left, ll right) {
  if (left < right) {
    ll mid = left + (right - left)/2;
    merge_sort(a, left, mid);
    merge_sort(a, mid+1, right);
    merge(a, left, mid, right);
  }
}

int main() {
  ll t, n;
  cin >> t;
  while (t > 0) {
    cin >> n;
    vl a(n);
    for (auto& x : a) cin >> x;
    // ll k = merge_sort(a, 0, n-1);
    // cout << k << "\n";
    t--;
  }
  return 0;
}
