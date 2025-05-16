// Eliav, Liel & Iris

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using ll = long long;
#define pii pair<int, int>


#define gcd __gcd
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl

#define fastio()                                                               \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

ll BFS(int i, int j, vector<vector<bool>> &visited, vector<string> &grid) {
  if (visited[i][j])
    return 0;
  visited[i][j] = true;

  if (grid[i][j] != '#') {
    return 0;
  }
  queue<pii> q;
  q.push({i, j});
  ll cc_size = 1;
  while (!q.empty()) {
    int cur_i = q.front().first, cur_j = q.front().second;
    q.pop();
    // dbg2(cur_i, cur_j);
    FOR(dir, 0, 4) {
      int new_i = cur_i + dx[dir], new_j = cur_j + dy[dir];
      if (new_i >= 0 && new_j >= 0 && new_i < grid.size() &&
          new_j < grid[0].size() && !visited[new_i][new_j] &&
          grid[new_i][new_j] == '#') {
        visited[new_i][new_j] = true;
        q.push({new_i, new_j});
        cc_size++;
      }
    }
  }
  return cc_size;
}

string solve() {
  ll m, n;
  cin >> m >> n;
  vector<string> grid(m);
  FOR(i, 0, m) cin >> grid[i];
  vector<vector<bool>> visited(m, vector<bool>(n, false));

  ll total = 0;
  FOR(i, 0, m) {
    FOR(j, 0, n) {
      ll cc_size = BFS(i, j, visited, grid);
      total += cc_size * cc_size;
    }
  }
  if (total % (m * n) == 0)
    return to_string(total / (m * n));
  ll div = gcd(total, m * n);
  return to_string(total / div) + " / " + to_string((m * n) / div);
}

int main() {
  fastio();
  int t = 1;
  cin >> t;
  FOR(i, 0, t) { cout << solve() << ((i == (t - 1)) ? "" : "\n"); }
  return 0;
}
