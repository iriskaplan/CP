// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class UnionFind {
  vector<int> par;
  vector<int> size;

  public:
  UnionFind(int n): par(n), size(n,1) {
    for (int i = 0; i < n; i++) par[i] = i;
  }

  int find(int u) {
    if (par[u] != u)
      par[u] = find(par[u]);
    return par[u];
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;

    if(size[u] <= size[v]) {
      size[v] += size[u];
      par[u] = v;
    } else {
      size[u] += size[v];
      par[v] = u;
    }
    return true;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  int t, u, v;
  for (int i = 0; i < q; i++) {
    cin >> t >> u >> v;
    if (t == 0) {
      uf.unite(u, v);
    } else {
      cout << ((uf.find(u) == uf.find(v)) ? 1 : 0) << "\n";
    }
  }
}