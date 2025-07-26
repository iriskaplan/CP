// Created by Iris Kaplan.

#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector(n,0));

  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  ll alt_row_max=0, alt_col_max=0;
  for(int i = 0; i < n; i++) {
    array<ll, 2> total = {0,0};
    for (int j = 0; j < n; j++) {
      total[j%2] += grid[i][j];
    }
    alt_row_max += max(total[0], total[1]);
  }

  for(int i = 0; i < n; i++) {
    array<ll, 2> total = {0,0};
    for (int j = 0; j < n; j++) {
      total[j%2] += grid[j][i];
    }
    alt_col_max += max(total[0], total[1]);
  }

  cout << max(alt_row_max, alt_col_max) << "\n";
  return 0;
}