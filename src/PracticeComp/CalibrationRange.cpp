// Created by Iris Kaplan.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int g;
  cin >> g;
  while (g--) {
    int n;
    cin >> n;
    int mind = INT_MAX, maxd = INT_MIN;

    vector<int> dev(n);
    for(auto &x : dev) {
      cin >> x;
      mind = min(mind, x);
      maxd = max(maxd, x);
    }
    cout << mind << " " << maxd << "\n";
  }
}