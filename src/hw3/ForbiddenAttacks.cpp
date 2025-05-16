// Eliav, Liel & Iris

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio()                                                               \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

#define KING_MASK 7
#define N_COLS 10

using Matrix = vector<vector<ll>>;
const ll MOD = 1LL << 32;
vector<pair<int, int>> V;

ll mat_sum(const Matrix &mat) {
  ll res = 0;
  for (const auto &row : mat) {
    for (auto a : row) {
      res += a % MOD;
    }
  }
  return res % MOD;
}

Matrix mat_mult(const Matrix &A, const Matrix &B) {
  int N = A.size();
  Matrix C(N, vector<ll>(N, 0));
  FOR(i, 0, N) {
    FOR(j, 0, N) {
      FOR(k, 0, N) { C[i][j] += ((A[i][k] % MOD) * (B[k][j] % MOD)) % MOD; }
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

Matrix construct_adj_mat() {
  int N = V.size();
  Matrix A(N, vector<ll>(N, 0));
  FOR(i, 0, N) {
    FOR(j, 0, N) { A[i][j] = ((V[i].second & V[j].first) == 0) ? 1 : 0; }
  }
  return A;
}

void construct_legal_nodes() {
  FOR(i, 1, N_COLS + 1) {
    FOR(j, 1, i) {
      if (abs(i - j) <= 1)
        continue;
      int v = 1 << i | 1 << j;
      int v_mask = KING_MASK << (i - 1) | KING_MASK << (j - 1);

      V.push_back({v, v_mask});
    }
  }
}

void solve(ll n) {
  Matrix A = construct_adj_mat();
  A = fast_matrix_exponentiation(A, n - 1);
  ll res = (n > 1) ? mat_sum(A) : V.size();
  cout << res;
}

int main() {
  fastio();
  int t;
  ll n;
  cin >> t;
  construct_legal_nodes();
  FOR(i, 1, t+1){
    cin >> n;
    cout << "Case " << i << ": ";
    solve(n);
    if (i < t) cout << "\n";
  }
  return 0;
}
