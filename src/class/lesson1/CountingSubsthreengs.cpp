// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  string s;
  while(cin >> s) {
    s += "$";
    ll total_sub3 = 0;
    vector<ll> hist(3, 0);
    hist[0] = 1;
    int d_sum = 0;

    for (ll i =0; i < s.size(); i++){
      if(isdigit(s[i])) {
        d_sum += s[i];
        d_sum %= 3;
        hist[d_sum]++;
      } else {
        for (int j =0;j < 3; j++) {
          total_sub3 += hist[j]*(hist[j]-1)/2;
        }
        hist = vector <ll> (3, 0);
        hist[0] = 1;
        d_sum = 0;
      }
    }
    cout << total_sub3 << "\n";
  }
  return 0;
}
