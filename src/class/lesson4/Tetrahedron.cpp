// Created by Iris Kaplan.

#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const ll MOD = 1000000007;

#define ff(i, a, b) for (int i = (a); i <= (b); i++)

typedef vector<vector<ll>> Matrix;

Matrix mat_mult(const Matrix& a,const Matrix& b) {
  Matrix c(4, vector<ll> (4,0));
  ff(i, 0, 3) {
    ff(j, 0, 3) {
      ff(k, 0, 3) {
        c[i][j] += (a[i][k] % MOD) * (b[k][j] % MOD);
      }
      c[i][j] %= MOD;
    }
  }
  return c;
}

Matrix mat_exp(Matrix a, ll pow) {
  Matrix res(4, vector<ll> (4,0));
  ff(i, 0, 3) {
    res[i][i]=1;
  }
  while(pow > 0) {
    if (pow%2)
      res = mat_mult(res,a);
    a = mat_mult(a,a);
    pow /= 2;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  if (n==1) {
    cout << 0 << "\n";
    return 0;
  }

  Matrix adj (4, vector<ll>(4,0));

  ff(i, 0, 3) {
    ff(j, 0, 3) {
      if (i!=j) adj[i][j] = 1;
    }
  }
  Matrix exped = mat_exp(adj, n);
  cout << exped[0][0] % MOD << "\n";

  return 0;
}