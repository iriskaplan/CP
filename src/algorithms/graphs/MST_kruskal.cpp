// Created by Iris Kaplan.

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ff(i, a, b) for(int i = a; i <= b; i++)

class UnionFind {
private:
	vector<ll> par;
	vector<ll> size;

public:
	explicit UnionFind(ll n) : par(n), size(n, 1) {
		for (ll i = 0; i < n; ++i) par[i] = i;
	}

	ll find(ll u) {
		if (par[u] != u)
			par[u] = find(par[u]);
		return par[u];
	}

	// Returns true if merged, false if in same component
	bool merge(ll u, ll v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;

		if (size[u] <= size[v]) {
			size[v] += size[u];
			par[u] = v;
		} else {
			size[u] += size[v];
			par[v] = u;
		}
		return true;
	}
};

using graph = vector<vector<array<ll,3>>>; // { t, w, idx }

struct Edge {
	ll w, t, s, id; // weight, target, source, edge idx
	bool operator<(const Edge& o) const { return w < o.w; } // min heap
};

vector<Edge> kruskal(ll n, vector<Edge>& edges) {
  sort(edges.begin(), edges.end());
  UnionFind uf(n);
  vector<Edge> mst;
  mst.reserve(n-1);

  for(Edge& e: edges) {
    if (uf.merge(e.s, e.t)) {
      mst.push_back(e);
      if (mst.size() == n-1)
        break;
    }
  }
  return mst;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n, m;
	cin >> n >> m;
	vector<Edge> edges(m);
	ll a, b, c;
	ff(i, 0, m - 1) {
		cin >> a >> b >> c;
		edges.push_back({c, a, b, i});
	}

	auto mst = kruskal(n, edges);

	ll tree_sum = 0;
	for(auto& e: mst) {
		tree_sum += e.w;
	}

	cout << tree_sum << "\n";
	for(auto& e: mst) {
		cout << e.id << " ";
	}

	return 0;
}
