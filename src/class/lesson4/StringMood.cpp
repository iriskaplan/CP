// Created by Iris Kaplan.

#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using Matrix = vector<vector<ll>>;
const ll MOD = 1000000007;

Matrix mat_mult(const Matrix &A, const Matrix &B) {
  int N = A.size();
  Matrix C(N, vector<ll>(N, 0));
  FOR(i, 0, N) {
    FOR(j, 0, N) {
      FOR(k, 0, N) {
        C[i][j] += ((A[i][k] % MOD) * (B[k][j] % MOD)) % MOD;
      }
      C[i][j] %= MOD;
    }
  }
  return C;
}

Matrix fast_matrix_exponentiation(Matrix A, ll power) {
  int N = A.size();
  Matrix res(N, vector<ll>(N, 0));
  FOR(i, 0, N) { res[i][i] = 1; }

  while (power > 0) {
    if (power % 2)
      res = mat_mult(res, A);
    A = mat_mult(A, A);
    power /= 2;
  }

  return res;
}

int main() {
  ll n;
  cin >> n;

  Matrix p(2, vector<ll>(2, 0));
  p[0][0] = 19;
  p[0][1] = 7;
  p[1][0] = 6;
  p[1][1] = 20;

  // calculate p^n in logarithmic time using fast exp
  Matrix p_n = fast_matrix_exponentiation(p, n);

  cout << p_n[0][0] << "\n";
  return 0;
}


