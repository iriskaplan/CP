// Created by Iris Kaplan.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<vector<ll>> Matrix;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
const ll MOD = 998244353;

Matrix mat_mult(
	const Matrix &A, const Matrix &B
  ) {
	ll N = A.size();
	ll M  = B.size();
	ll K = B[0].size();
	Matrix C(N, vector<ll>(K, 0));
	FOR(i, 0, N-1) {
		FOR(j, 0, K-1) {
			FOR(k, 0, M-1) {
				C[i][j] +=
				 ((A[i][k] % MOD)*(B[k][j] % MOD))%MOD;
			}
			C[i][j] %= MOD;
		}
	}
	return C;
}

int main() {
  ll n,m,k;
  cin >> n >> m >> k;
  Matrix a(n, vector<ll>(m));
  Matrix b(m, vector<ll>(k));

  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (ll i = 0; i < m; i++) {
    for (ll j = 0; j < k; j++) {
      cin >> b[i][j];
    }
  }

  Matrix c = mat_mult(a,b);
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < k; j++) {
      cout << c[i][j] << " ";
    }
  	cout << "\n";
  }
  return 0;
}