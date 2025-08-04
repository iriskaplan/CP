// Created by Iris, Liel & Eliav.

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const ll MOD = 1LL * 1e9;

#define fastio()                                                               \
ios::sync_with_stdio(0);                                                     \
cin.tie(0);

struct light {
  ll x;
  ll y;
  ll i;
};

void dfs(
    ll v, const vvl &adj, vector<bool> &visited, vl& output
    ) {
  visited[v] = true;
  for (auto u: adj[v]) {
    if (!visited[u]) {
      dfs(u, adj, visited, output);
    }
  }
  output.push_back(v);
}

void scc(
    const vvl &adj, vector<bool> &visited, vvl &components
    ) {
  int n = adj.size();
  components.clear();

  vl order;
  visited.assign(n, false);

  for (ll i = 0; i < n; i++)
    if (!visited[i])
      dfs(i, adj, visited, order);

  vvl adj_rev(n);
  for (ll v = 0; v < n; v++)
    for (auto u : adj[v])
      adj_rev[u].push_back(v);

  visited.assign(n, false);
  reverse(order.begin(), order.end());

  vector<int> roots(n, 0);

  for (auto v : order)
    if (!visited[v]) {
      vl component;
      dfs(v, adj_rev, visited, component);
      components.push_back(component);
      int root = *min_element(begin(component), end(component));
      for (auto u : component)
        roots[u] = root;
    }
}

int main() {
  fastio();
  // odd places is column mode, even places is row mode
  // n+i is the negation of a state for i \in 2*l
  ll n, t, l;
  cin >> n >> t >> l;

  vector<light> lights(l);

  ll a, b;
  for (ll i = 0; i < l; i++) {
    cin >> a >> b;
    lights[i] = light{a, b, i};
  }

  vvl adj (4*l);
  for (ll j = 0; j < l; j++) {
    ll r = 2*j, c = 2*j +1;
    ll nr = 2*l + r, nc = 2*l + c;

    adj[r].push_back(nc);
    adj[c].push_back(nr);
    adj[nr].push_back(c);
    adj[nc].push_back(r);
  }

  for (ll j=0; j < l; j++) {
    for (ll k = j+1; k < l; k++) {
      if (lights[j].x == lights[k].x && abs(lights[j].y - lights[k].y) <= 2 * t) {
        adj[2*j].push_back(2*l + 2*k);
        adj[2*k].push_back(2*l + 2*j);
      }

      if (lights[j].y == lights[k].y && abs(lights[j].x - lights[k].x) <= 2 * t) {
        adj[2*j + 1].push_back(2*l + 2*k + 1);
        adj[2*k + 1].push_back(2*l + 2*j + 1);
      }
    }
  }

  vector<bool> visited(4*l);
  vvl components;
  scc(adj, visited, components);

  vl comp_idx(4*l);
  for (ll k = 0; k < components.size(); k++) {
    for (auto u : components[k]) {
      comp_idx[u] = k;
    }
  }

  bool can_be = true;
  for (ll i = 0; i < 2*l; i++){
    if (comp_idx[i] == comp_idx[2*l+i]) {
      can_be = false;
      break;
    }
  }

  if (can_be) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }

  return 0;
}
