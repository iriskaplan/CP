#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<vi> transpose(const vector<vi>& adj) {
   int n = adj.size();
   vector<vi> transp(n);
   for(int i = 0; i < n; i++) {
      for(auto& x : adj[i]) {
         transp[x].push_back(i);
      }
   }
   return transp;
}

void dfs1(const vector<vi>& adj, int u, vector<bool>& vis, stack<int>& order) {
   vis[u] = true;
   for (int nei : adj[u]) {
      if (!vis[nei]) dfs1(adj, nei, vis, order);
   }
   order.push(u);
}

void dfs2(const vector<vi>& adj_t, int u, vector<bool>& vis, vector<int>& component) {
   vis[u] = true;
   component.push_back(u);
   for (int nei : adj_t[u]) {
      if (!vis[nei]) dfs2(adj_t, nei, vis, component);
   }
}

vector<vi> scc(vector<vi>& adj) {
   int n = adj.size();
   vector<bool> vis(n, false);
   stack<int> order;

   for (int i = 0; i < n; i++) {
      if (!vis[i]) dfs1(adj, i, vis, order);
   }

   vector<vi> result;
   vector<vi> adj_t = transpose(adj);
   fill(vis.begin(), vis.end(), false);

   while (!order.empty()) {
      int u = order.top(); order.pop();
      if (!vis[u]) {
         vector<int> component;
         dfs2(adj_t, u, vis, component);
         result.push_back(component);
      }
   }

   return result;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, m;
   cin >> n >> m;
   vector<vi> adj(n);
   for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
   }

   vector<vi> components = scc(adj);
   cout << components.size() << "\n";
   for (int i = 0; i < components.size(); i++) {
      cout << components[i].size();
      for (int v : components[i]) {
         cout << " " << v;
      }
      cout << "\n";
   }

   return 0;
}