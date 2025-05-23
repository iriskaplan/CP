// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const ll MOD = 1000000000;

#define fastio()                                                               \
ios::sync_with_stdio(0);                                                     \
cin.tie(0);

void reachable_from(ll node, vvl &graph, vector<bool> &reachable) {
  stack<ll> stack;
  stack.push(node);
  reachable[node] = true;
  while (!stack.empty()) {
    ll u = stack.top(); stack.pop();
    reachable[u] = true;

    for (auto v : graph[u]) {
      if (!reachable[v]) {
        stack.push(v);
      }
    }
  }
}

void topological_sort_dfs(ll node, vector<bool> &visited, vector<bool> &explored,
  vector<ll> &topo_sorted, vvl &graph, bool &has_cycle, vector<bool> &from_s, vector<bool> &to_t) {
  visited[node] = true;
  explored[node] = true;
  for (auto neighbor: graph[node]) {
    if (!visited[neighbor]) {
      topological_sort_dfs(neighbor, visited, explored, topo_sorted, graph, has_cycle, from_s, to_t);
      if (has_cycle) return;
    } else if (explored[neighbor] && from_s[neighbor] && to_t[neighbor]) {
      has_cycle = true;
      return;
    }
  }

  explored[node] = false;
  topo_sorted.push_back(node);
}

int main() {
  fastio();

  ll n , m;
  cin >> n >> m;
  ll s = 1, t = 2;

  vvl adj (n+1);
  vvl rev_adj (n+1);

  ll a, b;
  for (ll i = 0; i < m; i ++) {
    cin >> a >> b;
	  adj[a].push_back(b);
	  rev_adj[b].push_back(a);
  }

  vector<ll> tp_sorted;
  bool has_cycle = false;
  vector<bool> from_s(n+1, false);
  vector<bool> to_t(n+1, false);
  vector<bool> visited (n+1, false);
  vector<bool> explored (n+1, false);

  reachable_from(s, adj, from_s);

  reachable_from(t, rev_adj, to_t);
  for (ll k=1; k <= n; k++) {
    if (!visited[k] && from_s[k] && to_t[k]) {
      topological_sort_dfs(k, visited, explored, tp_sorted, adj, has_cycle,
        from_s, to_t);
    }
  }
  if (has_cycle) {
    cout << "inf" << "\n";
    return 0;
  }

  vector<ll> paths (n+1, 0);
  paths[s] = 1;

  ll c;
  for (ll i = tp_sorted.size() - 1; i >=0 ; i--) {
    c = tp_sorted[i];
    for (const auto v: adj[c]) {
      paths[v] = (paths[v] + paths[c]) % MOD;
    }
  }

  cout << paths[t] % MOD << "\n";
  return 0;
}
