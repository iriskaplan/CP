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

// use bellman-ford instead of dijkstra
bool detect_neg_cycle(const int n, const int s,
  const vector<tuple<int, int, int>>& edges) {
  vi dist(n, INT_MAX);
  dist[s] = 0;

  for (int i=0; i < n - 1; i++) {
    for (auto &[u, v, w] : edges) {
      if (dist[u] != INT_MAX) {
        dist[v] = min(dist[v], dist[u] + w);
      }
    }
  }

  for (auto &[u, v, w] : edges) {
    if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
      return true;
    }
  }

  return false;
}

int main() {
  fastio();
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, r, p;
    cin >> n >> r >> p;

    int a, b, e, c;
    vector<tuple<int, int, int>> edges;
    for (int j = 0; j < r; j ++) {
      cin >> a >> b >> e >> c;
      edges.emplace_back(a, b, p*c - e);
    }

    bool did_print = false;
    for (int k = 0; k < n; k++) {
    if (detect_neg_cycle(n, k, edges)) {
      cout << "Case " << i+1 << ": YES" << "\n";
      did_print = true;
      break;
      }
    }
    if (!did_print) {
      cout << "Case " << i+1 << ": NO" << "\n";
    }
  }

  return 0;
}
