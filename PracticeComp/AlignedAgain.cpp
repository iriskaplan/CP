// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
  ll a1 = max(a, b);
  ll b1 = min(a, b);
  return b1 == 0 ? a1 : gcd(b1, a1 % b1);
}

int lcm(int a, int b) {
  return a * b / gcd (a, b);
}

int main() {
  int n;
  cin >> n;

  int y, c1, c2;
  int v = INT_MAX;
  for(int i = 0; i < n; i++) {
    cin >> y >> c1 >> c2;
    int c = lcm(c1, c2);
    v = min(v, y+c);
  }
  cout << v << "\n";
  return 0;
}