// Created by Iris Kaplan.

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ll n;
  cin >> n;
  ll steps = 0;
  while (n > 0) {
    int max_d = 0;
    for (ll j = 1; j <= ceil(log2(n)); j++) {
      int d = ((n % ll(pow(10,j))) - (n % ll(pow(10,j-1)))) / pow(10,j-1);
      max_d = max(d, max_d);
    }
     n -= max_d;
    steps += 1;
  }
  cout << steps << "\n";
  return 0;
}
