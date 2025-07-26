
 // Find A^k for some k
 #include <bits/stdc++.h>

 using namespace std;
 using ll = long long;

 const ll MOD = 998244353;
 typedef vector<vector<ll>> Matrix;

 Matrix mat_mult(
	const Matrix &A, const Matrix &B
) {
	ll N = A.size();
	ll M = B.size();
	ll K = B[0].size();

	Matrix C(N, vector<ll>(K, 0));

	for (ll i = 0; i < N; ++i) {
		for (ll k = 0; k < M; ++k) {
			ll a = A[i][k] % MOD;
			for (ll j = 0; j < K; ++j) {
				C[i][j] =
				  (C[i][j] + a * (B[k][j] % MOD)) % MOD;
			}
		}
	}

	return C;
}

Matrix mat_pow(Matrix A, ll power) {
 	int N = A.size();
 	Matrix res(N, vector<ll>(N, 0));
 	for (ll i = 0; i < N; ++i) { res[i][i] = 1; }

 	while (power > 0) {
 		if (power % 2)
 			res = mat_mult(res, A);
 		A = mat_mult(A, A);
 		power /= 2;
 	}

 	return res;
 }

int main () {
  ll n,k;
  cin >> n >> k;
  Matrix a (n, vector<ll> (n));

  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++) {
      cin >> a[i][j];
  	}
  }

  Matrix res = mat_pow(a, k);

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cout << res[i][j] << " ";
	}
  	cout << "\n";
  }
  return 0;
}
