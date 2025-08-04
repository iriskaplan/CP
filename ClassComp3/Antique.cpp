// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

struct road {
    ll distance;
    ll a;
    ll b;
};
typedef vector<road> vr;

struct tll {
    ll v;
    ll d;
    ll u;
};


void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

pll bf(ll n, ll start, const vector<tuple<ll, ll, ll>> & edges, const vll &valuables) {
    vector<pll> dist(n, {LLONG_MAX, 0});
    dist[start] = {0, valuables[start]};

    for (ll i = 0; i < n - 1; i++) {
        for (auto & [u, v, w] : edges) {
            if (dist[u].first != LLONG_MAX) {
                // If shorter path, just take it
                if (dist[v].first > dist[u].first + w) {
                    dist[v].first = dist[u].first + w;
                    dist[v].second = dist[u].second + valuables[v];
                // If same-distance path, update the number of valuables if better
                } else if (dist[v].first == dist[u].first + w) {
                    dist[v].second = max(dist[v].second, dist[u].second + valuables[v]);
                }
            }
        }
    }

    return dist[n - 1];
}

int main() {
    fastio();

    ll n;
    cin >> n;

    vll valuables(n);

    for (ll i = 0; i < n; i++) {
        cin >> valuables[i];
    }

    ll m;
    cin >> m;

    vector<tuple<ll ,ll, ll>> edges;
    for (ll i = 0; i < m; i++) {
        ll a, b, d;
        cin >> a >> b >> d;
        edges.emplace_back(a - 1, b - 1, d);
        edges.emplace_back(b - 1, a - 1, d);
    }

    pll res = bf(n, 0, edges, valuables);

    if (res.first == LLONG_MAX) {
        cout << "impossible" << '\n';
        return 0;
    }

    cout << res.first << ' ' << res.second << '\n';
    return 0;
}