// Problem: https://qoj.ac/problem/2969

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i= a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> Matrix;

ld choose2(ll c) {
  return ld(c * (c-1)) / 2.0;
}

ll dfs(vector<vl>& g, vector<bool>& vis, ll s) {
  ll c_sz = 0;
  stack<ll> st;
  st.push(s);
  vis[s] = true;
  while(!st.empty()) {
    ll cur = st.top(); st.pop();
    c_sz += 1;
    for (auto& u : g[cur]) {
      if (!vis[u]) {
        vis[u] = true;
        st.push(u);
      }
    }
  }

  return c_sz;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  vector<vl> g(n);
  vector<bool> vis(n, false);
  ll u, v;
  for (ll i = 0; i < m; i++) {
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  ld prob = 0;
  for (ll i =0; i < n; i++) {
    if (!vis[i]) {
      ll c = dfs(g, vis, i);
      prob += choose2(c);
    }
  }

  cout << setprecision(10) << prob / choose2(n) << "\n";
	return 0;
}
