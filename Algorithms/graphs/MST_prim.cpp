
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ff(i, a, b) for(int i = a; i <= b; i++)

struct Edge {
  ll w, t, s, id; // weight, target, source, edge idx
  bool operator<(const Edge& o) const { return w > o.w; } // min heap
};

using graph = vector<vector<array<ll,3>>>; // { t, w, idx }

vector<Edge> prim(ll n, const graph& g) {
  vector<bool> vis(n+1, false);
  priority_queue<Edge> pq;
  vector<Edge> mst;
  pq.push({0,0,-1,-1}); // start from 0

  while(!pq.empty() && mst.size() < n-1) {
    Edge e = pq.top(); pq.pop();
    if (vis[e.t]) continue;
    vis[e.t] = true;
    if (e.s != -1) mst.push_back(e); // skip fake edge
    for (auto [v, w, id] : g[e.t])
      if (!vis[v]) pq.push({w,v,e.t,id});
  }
  return mst;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  ll n, m;
  cin >> n >> m;
  graph g(n);
  ll a, b, c;
  ff(i, 0, m - 1) {
    cin >> a >> b >> c;
    g[a].push_back({b, c, i});
    g[b].push_back({a, c, i});
  }

  auto mst = prim(n, g);

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

