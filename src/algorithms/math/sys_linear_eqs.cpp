// Given a matrix A size n x m and vector b len n find
// x len m such that Ax = b. Solves over a finite field.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

typedef vector<int> vi;
typedef vector<vi> vvi;
const int MOD = 998244353;

int modinv(int a) {
  int res = 1, b = MOD - 2;
  while (b) {
    if (b & 1) res = 1LL * res * a % MOD;
    a = 1LL * a * a % MOD;
    b >>= 1;
  }
  return res;
}

// aug = [A | b], sol is a particular solution, basis is the nullspace basis
int gauss(vvi& aug, vi& sol, vvi& basis) {
  int n = aug.size(), m = aug[0].size() - 1, row = 0;
  vi where(m, -1);

  for (int col = 0; col < m && row < n; ++col) {
    int sel = -1;
    for (int i = row; i < n; ++i)
      if (aug[i][col]) { sel = i; break; }
    if (sel == -1) continue;

    swap(aug[sel], aug[row]);
    where[col] = row;

    int inv = modinv(aug[row][col]);
    for (int j = col; j <= m; ++j)
      aug[row][j] = 1LL * aug[row][j] * inv % MOD;

    for (int i = 0; i < n; ++i) if (i != row && aug[i][col]) {
      int factor = aug[i][col];
      for (int j = col; j <= m; ++j)
        aug[i][j] = (aug[i][j] - 1LL * factor * aug[row][j] % MOD + MOD) % MOD;
    }
    ++row;
  }

  for (int i = row; i < n; ++i)
    if (aug[i][m]) return -1;

  sol.assign(m, 0);
  for (int i = 0; i < m; ++i)
    if (where[i] != -1)
      sol[i] = aug[where[i]][m];

  basis.clear();
  for (int i = 0; i < m; ++i) if (where[i] == -1) {
    vi vec(m);
    vec[i] = 1;
    for (int j = 0; j < m; ++j)
      if (where[j] != -1)
        vec[j] = (MOD - aug[where[j]][i]) % MOD;
    basis.push_back(vec);
  }

  return (int) basis.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vvi A(N, vi(M));
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      cin >> A[i][j];

  vi b(N);
  for (int i = 0; i < N; ++i)
    cin >> b[i];
  
  vvi aug(N, vi(M + 1));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) aug[i][j] = A[i][j];
    aug[i][M] = b[i];
  }

  vi sol;
  vvi basis;
  int R = gauss(aug, sol, basis);

  if (R == -1) {
    cout << -1 << '\n';
    return 0;
  }

  cout << R << '\n';
  for (int i = 0; i < M; ++i)
    cout << sol[i] << " \n"[i == M - 1];

  for (int i = 0; i < (int)basis.size(); ++i) {
    for (int j = 0; j < M; ++j)
      cout << basis[i][j] << " \n"[j == M - 1];
  }

  return 0;
}