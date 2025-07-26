// Created by Iris Kaplan.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  string digits;
  getline(cin, digits);

  bool has_zero = false;
  ll num_sum = 0;
  for(auto& c: digits) {
    int d = c - '0';
    if (d== 0) has_zero=true;
    num_sum += d;
  }

  if (!has_zero || (num_sum % 3 != 0)) {
    cout << -1 << "\n";
  } else {
    sort(digits.begin(), digits.end(), greater<char>());
    cout << digits << "\n";
  }

  return 0;
}
