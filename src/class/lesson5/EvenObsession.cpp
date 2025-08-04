// Created by Iris Kaplan.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using pll = pair<ll,ll>;
using vvpll = vector<vector<pll>>;
using vll = vector<ll>;


void dijkstra(const vvpll& adj, vll &dist, vll &prev) {
  dist[1] = 0;
  priority_queue<pll, vector<pll>, greater<pll>> queue;

  queue.push({0, 1});
  while (!queue.empty()) {
    auto w_t = queue.top(); queue.pop();
    ll d = w_t.first; // cur dist
    ll u = w_t.second; // cur node

    if (d > dist[u]) continue;

    for (auto nei : adj[u]) {
      ll v = nei.first;
      ll w = nei.second;
      if (v == 0) { continue; }
      if (dist[v] > w + dist[u]) {
        dist[v] = w + dist[u];
        prev[v] = u;
        queue.push({dist[v], v});
      }
    }
  }
}

int main() {
  ll c, v;
  ll u, w, t;

  while (cin >> c >> v) {
    vvpll adj(2*c+1);
    for (ll i = 0; i < v; i++) {
      cin >> u >> w >> t;
      // add 4 edges to each edge
      adj[u].emplace_back(w+c, t);
      adj[w+c].emplace_back(u, t);
      adj[u+c].emplace_back(w, t);
      adj[w].emplace_back(u+c, t);
    }

    vll prev = vll(2*c+1, -1);
    vll dist = vll(2*c+1, LLONG_MAX);
    dijkstra(adj, dist, prev);

    cout << (dist[c] < LLONG_MAX ? dist[c] : -1) << "\n";
  }

  return 0;
}
