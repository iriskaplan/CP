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

struct q_c {
  int u;
  int v;
  int q;

  q_c(int u, int v, int q) : u(u), v(v), q(q) {}
};

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

int main(){
  fastio();
  int T;
  cin >> T;

  for (int l = 0; l < T; l ++) {
    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;

    vector<vpii> adj (n+1);
    vi dist (n+1);
    vector<q_c> q_adj;

    int a, b, w;
    for (int i = 0; i < m; i ++) {
      cin >> a >> b >> w;
      adj[a].emplace_back(b,w);
    }

    for (int i = 0; i < k; i ++) {
      cin >> a >> b >> w;
      q_c trip = q_c(a, b, w);
      q_adj.push_back(trip);
    }

    int min_cost = INT_MAX;
    for (int i = 0; i < k; i ++) {
      auto trp = q_adj[i];

      auto temp_adj = adj;

      auto &adj_u = temp_adj[trp.u];
      adj_u.erase(remove_if(adj_u.begin(), adj_u.end(),
        [&](const pii& p) {return p.first == trp.v;}), adj_u.end());

      auto &adj_v = temp_adj[trp.v];
      adj_v.erase(remove_if(adj_v.begin(), adj_v.end(),
        [&](const pii& p) {return p.first == trp.u;}), adj_v.end());

      temp_adj[trp.u].push_back({trp.v, trp.q});
      temp_adj[trp.v].push_back({trp.u, trp.q});
      dijkstra(temp_adj, dist, s);
      if (dist[t] < min_cost) {
        min_cost = dist[t];
      }
    }

    if (min_cost == INT_MAX) {
      cout << "-1" << "\n";
    } else {
      cout << min_cost << "\n";
    }
  }

  return 0;
}
