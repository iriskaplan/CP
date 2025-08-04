// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int INF = 1e9;

#define fastio()                                                               \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);

void dijkstra (const vector<vpii> &adj, vi &dist, ll start) {
  int n = adj.size();

  dist = vi(n, INT_MAX);
  dist[start] = 0;
  priority_queue<pii, vector<pii>, greater<>> queue;

  queue.push({0, start});

  while (!queue.empty()) {
    auto d_u = queue.top(); queue.pop();
    int d = d_u.first;
    int u = d_u.second;

    if (d > dist[u]) continue;

    for (auto neighbor: adj[u]) {
      int v = neighbor.first, w = neighbor.second;
      if (v == 0) { continue; }
      if (dist[v] > w + dist[u]) {
        dist[v] = w + dist[u];
        queue.push({dist[v], v});
      }
    }
  }
}

int main() {
  fastio();
  int T;
  cin >> T;

  for (int l = 0; l < T; l ++) {
    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;

    vector<vpii> adj (2*n+1);
    vi dist (2*n+1);

    int a, b, w;
    for (int i = 0; i < m; i ++) {
      cin >> a >> b >> w;
      adj[a].emplace_back(b,w);
      adj[a+n].emplace_back(b+n,w);
    }

    for (int i = 0; i < k; i ++) {
      cin >> a >> b >> w;
      adj[a].emplace_back(b+n,w);
      adj[b].emplace_back(a+n,w);
    }

    dijkstra(adj, dist, s);
    if (dist[t + n] == INT_MAX && dist[t] == INT_MAX) {
      cout << "-1" << "\n";
    } else {
      cout << min(dist[t + n], dist[t]) << "\n";
    }
  }

  return 0;
}
