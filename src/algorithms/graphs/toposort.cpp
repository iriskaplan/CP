// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

vi topological_sort_bfs(vvi &graph){
	int n = graph.size();
	vi indegree(n, 0);
    vi topo_v;
	for (int i =0; i < n; i++){
		for (int neighbor: graph[i]) {
			indegree[neighbor]++;
		}
	}
	queue<int> q;
	for (int i = 0; i < n; i++){
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()){
		int cur = q.front();
		q.pop();
		if (cur == 0) continue;
        topo_v.push_back(cur);

		for(int neighbor : graph[cur]) {
			indegree[neighbor]--;
			if (indegree[neighbor] == 0) {
				q.push(neighbor);
			}
		}
	}

	return topo_v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;

	vvi adj (n+1);
	ll a, b;
	for (ll i = 0; i < m; i++) {
		cin >> a >> b ;
		adj[a].push_back(b);
	}

	vi ordered = topological_sort_bfs(adj);
    if (ordered.size() < n) {
      cout << "IMPOSSIBLE";
    } else {
      for (ll i=0; i < n; i++) {
      	cout << ordered[i] << " ";
      }
    }
	return 0;
}
