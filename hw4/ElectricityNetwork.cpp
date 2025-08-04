// Created by Iris, Liel & Eliav.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const ll MOD = 1LL * 1e9;

#define fastio()                                                               \
ios::sync_with_stdio(0);                                                     \
cin.tie(0);

void reachable_from(ll node, vvl &graph, vector<bool> &reachable) {
	stack<ll> stack;
	stack.push(node);
	reachable[node] = true;
	while (!stack.empty()) {
		ll u = stack.top();
		stack.pop();

		for (auto v: graph[u]) {
			if (!reachable[v]) {
				reachable[v] = true;
				stack.push(v);
			}
		}
	}
}

bool topological_sort_bfs(vvl &graph, vector<ll> &topo_sorted, vector<bool> &relevant, ll r_count) {
	ll n = graph.size() - 1;

	vl indegree(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		if (relevant[i]) {
			for (ll neighbor: graph[i]) {
				if (relevant[neighbor]) {
					indegree[neighbor]++;
				}
			}
		}
	}
	queue<ll> q;
	for (ll i = 1; i <= n; i++) {
		if (relevant[i] && indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		ll c = q.front();
		q.pop();
		if (relevant[c]) {
			topo_sorted.push_back(c);
		}

		for (ll neighbor: graph[c]) {
			if (relevant[neighbor]) {
				indegree[neighbor]--;
			}
			if (relevant[neighbor] && indegree[neighbor] == 0) {
				q.push(neighbor);
			}
		}
	}
	return !(r_count == topo_sorted.size());
}

int count_digit(ull n) {
	if (n == 0) return 1;
	return floor(log10(n) + 1);
}

int main() {
	fastio();

	ll n, m;
	cin >> n >> m;

	ll s = 1, t = 2;

	vvl adj(n + 1, vl(0));
	vvl rev_adj(n + 1, vl(0));

	ll a, b;
	for (ll i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		rev_adj[b].push_back(a);
	}

	vector<ll> tp_sorted;
	vector<bool> from_s(2*n, false);
	vector<bool> to_t(2*n, false);
	vector<bool> relevant(2*n, false);
	ll relevant_count = 0;
	reachable_from(s, adj, from_s);
	reachable_from(t, rev_adj, to_t);

	for (ll k = 1; k <= n; k++) {
		if (from_s[k] && to_t[k]) {
			relevant[k] = true;
			relevant_count += 1;
		}
	}

	bool has_cycle = topological_sort_bfs(adj, tp_sorted, relevant, relevant_count);
	if (has_cycle) {
		cout << "inf" << "\n";
	} else {
		vector<ull> paths(2*n, 0);
		paths[s] = 1;
		bool should_pad = false;

		for (ll c : tp_sorted) {
			for (const auto v: adj[c]) {
				paths[v] += paths[c];
				if (paths[v] >= MOD) {
					should_pad = true;
					paths[v] %= MOD;
				}
			}
		}

		if (should_pad) {
			int digits = count_digit(paths[t] % MOD);
			for (int u = 0; u < (9-digits); u++) {
				cout << "0";
			}
		}
		cout << paths[t] << "\n";
	}
	return 0;
}
