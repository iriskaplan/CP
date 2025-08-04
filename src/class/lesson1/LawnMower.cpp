// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX 1001
const double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int nx, ny, i;
  double w;
  double x[MAX], y[MAX];

  while (cin >> nx >> ny >> w) {
    if ((nx == 0) && (ny == 0) && (abs(w) < EPS))
      break;

    for (i=0; i < nx; i++)
      cin >> x[i];
    for (i=0; i < ny; i++)
      cin >> y[i];

    sort(x, x + nx);
    sort(y, y + ny);
    bool flag = true;

    if ((x[0] > w/2) || (x[nx-1] < 75 - w/2) ||
        ((y[0] > w/2) || (y[ny-1] < 100 - w/2))) {
      flag = false;
    }
    if (flag) {
      for (i=0; i < nx-1; i++) {
        if (x[i+1] - x[i] > w){
          flag = false;
        }
      }

      for (i=0; i < ny-1; i++) {
        if (y[i+1] - y[i] > w){
          flag = false;
        }
      }
    }
    cout << (flag ? "YES" : "NO") << "\n";
  }

  return 0;
 }