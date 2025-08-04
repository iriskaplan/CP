// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
  int T;
  cin >> T;
  for (int k=1; k<=T; k++) {
    int n;
    cin >> n;
    double exp = 0;
    vector<double> prob (n,0);
    prob[0]=1;
    vector<int> gold (n,0);
    for (int i = 0; i < n;i++) {
      cin >> gold[i];
    }
    for (int i = 0; i < n;i++){
      exp += gold[i] * prob[i];
      // for the amount of next steps t = min(6, N-i) add to each index prob[i]/t
      int t = min(6, n - i -1);
      for (int j=0; j< t; j++) {
        prob[i+j+1] += prob[i] / t;
      }
    }
    cout << "Case " << k << ": " << fixed << setprecision(6) << exp << "\n";
  }

  return 0;
}
