// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

void dijkstra(
    const vector<vpii> &adj, vi &dist, vi &prev, ll start
) {
	ll n = adj.size();
	prev = vi(n, -1);
	dist = vi(n, LLONG_MAX);
	dist[start] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> queue;
	queue.push({0, start});

	while (!queue.empty()) {
		pii d_u = queue.top(); queue.pop();
		int d = d_u.first;
		int u = d_u.second;

		if (d > dist[u]) continue;

		for (size_t i = 0; i < adj[u].size(); ++i) {
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				prev[v] = u;
				queue.push({dist[v], v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;
    cin >> n >> m;

    vector<vpii> adj (n+1);
    ll a, b, w;
    for (ll i = 0; i < m; i++) {
      cin >> a >> b >> w;
      adj[a].push_back(make_pair(b,w));
    }

    vi dist (n+1);
    vi prev (n+1);
    dijkstra(adj, dist, prev, 1);
    for (ll i=1; i <=n;i++) {
      cout << dist[i] << " ";
    }
	return 0;
}
