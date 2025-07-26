// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<vector<pll>> vvpll;

void dijkstra(const vvpll &adj, vll& dist, ll start) {
    ll n = adj.size(); // 2n+1
    dist = vll(n, LLONG_MAX);
    dist[start] = 0;

    priority_queue<pll, vector<pll>, greater<>> queue;
    queue.push({0, start});

    while(!queue.empty()) {
        auto d_u = queue.top(); queue.pop();
        ll d = d_u.first;
        ll u = d_u.second;

        if (d > dist[u]) continue;

        for (auto nei: adj[u]) {
            ll v = nei.first, w=nei.second;
            if (v==0) continue;
            if(dist[v]>w+dist[u]){
                dist[v]=w+dist[u];
                queue.push({dist[v], v});
            }
        }
    }
}

int main() {
    ll n, m, k, a, b;
    // 1,..,n regular vertices, n+1,...,2n where I have gift
    cin >> n >> m >> k >> a >> b;
    ll u,v;
    vvpll adj (2*n+1);

    for(ll i = 0; i < k; i++) {
        cin >> u;
        adj[u].emplace_back(u+n, 0);
    }

    for(ll i = 0; i < m; i++) {
        cin >> u >> v;
        // add 2 way og graph
        adj[u].emplace_back(v, 1);
        adj[v].emplace_back(u, 1);

        // add 2 way after g graph
        adj[u+n].emplace_back(v+n, 1);
        adj[v+n].emplace_back(u+n, 1);
    }

    // do dijkstra to find the shortest path between a and n+b
    vll dist (2*n+1);
    dijkstra(adj, dist, a);
    cout << dist[b+n] << "\n";
    return 0;
}