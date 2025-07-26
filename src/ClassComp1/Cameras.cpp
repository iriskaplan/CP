// Created by Iris Kaplan.

#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll n, k, r;
  cin >> n >> k >> r;
  vector<bool> cams (n, false);
  ll added = 0;
  ll i, j;
  for (i = 0; i < k; i++) {
      cin >> j;
      cams[j-1] = true;
  }

  ll cam_num = 0;
  for (i = 0; i <= (n-r); i++) {
    if (i == 0) {
      for (ll m = 0; m < r; m++) {
        if (cams[i+m] == true) {
          cam_num += 1;
        }
      }
    } else {
      if (cams[i-1]) {
        cam_num -= 1;
      }
      if (cams[i + r - 1]) {
        cam_num += 1;
      }
    }

    if (cam_num < 2) {
      j = i + r - 1;
      while (cam_num < 2 && j >= i) {
        if (cams[j] == false) {
          cam_num += 1;
          cams[j] = true;
          added += 1;
        }
        j -= 1;
      }
    }
  }

  cout << added << "\n";
  return 0;
}