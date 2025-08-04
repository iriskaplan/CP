// Created by Iris Kaplan.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef vector<ll> vl;

vector<vector<ll>> floyd_warshall(
  vector<vector<bool>> &adj,
  vector<vector<ll>> &weights
) {
  int n = adj.size();
  vector<vector<ll>> dist(n, vector<ll>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) dist[i][j] = 0;
      else if (adj[i][j])
        dist[i][j] = weights[i][j];
      else dist[i][j] = LLONG_MAX;
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dist[i][k] != LLONG_MAX &&
            dist[k][j] != LLONG_MAX) {
          dist[i][j] =
            min(dist[i][j],
              dist[i][k] + dist[k][j]);
            }
      }
    }
  }
  return dist;
}

int main() {
  ll n, m, q;
  cin >> n >> m >> q;

  vector<vector<bool>> adj(n, vector<bool>(n, 0));
  vector<vector<ll>> weights(n, vector<ll>(n, 0));
  ll a, b, c;
  for(ll i = 0; i < m; i++) {
    cin >> a >> b >> c;
    --a; --b; // convert to 0-based
    adj[a][b] = 1;
    adj[b][a] = 1;
    if (weights[a][b] == 0 || c < weights[a][b]) {
      weights[a][b] = c;
      weights[b][a] = c;
    }
  }

  vector<vector<ll>> dist = floyd_warshall(adj, weights);
  for(ll i = 0; i < q; i++) {
    cin >> a >> b;
    --a; --b; // convert to 0-based
    if (dist[a][b] == LLONG_MAX) {
      cout << -1 << "\n";
    } else {
      cout << dist[a][b] << "\n";
    }
  }
  return 0;
}