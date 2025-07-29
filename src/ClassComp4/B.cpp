// Created by Iris Kaplan.
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, long double>> pll;
typedef vector<vector<ll>> graph;


void topo_sort(ll node, vector<bool>& vis, stack<ll>& s, graph& g) {
	vis[node] = true;

	for (ll nei: g[node]) {
		if (!vis[nei]) {
			topo_sort(nei, vis, s, g);
		}
	}
	s.push(node);
}

int main() {
	ll n, m;
	cin >> n >> m;
	vector<double> probs(n+1, 0);
	probs[1] = 1;
	graph g(n+1);

	ll u, v;
	for(ll i =0; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
	}
	stack<ll> vert;
	vector<bool> vis(n+1, false);
	topo_sort(1, vis, vert, g);

	while(!vert.empty()) {
		ll cur = vert.top(); vert.pop();
		if (cur == 0) continue;

		ll d = g[cur].size();
		for (ll u: g[cur]) {
			probs[u] += (probs[cur]/ (double) d);
		}
	}

	for (ll i = 1; i <= n; i++) {
		if (g[i].size() == 0) {
			cout << setprecision(10) << probs[i] << "\n";
		}
	}
	return 0;
}