// Eliav, Liel & Iris

#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

typedef long long ll;

using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  ll n;
  cin >> n;
  vector<ll> p;
  ll v;
  p.push_back(0);
  for(ll i = 0; i < n; i++){
    cin >> v;
    p.push_back(v);
  }

  vector<vector<ll>> cycles;

  vector<bool> visited(n+1, false);
  visited[0] = true;
  visited[1] = true;
  stack<pair<ll, vector<ll>>> queue;
  queue.emplace(1, vector<ll>{1});
  auto not_visited = find(visited.begin(), visited.end(), false);

  while(!queue.empty() || not_visited != visited.end()) {
    ll i = 0;
    vector<ll> cyc;
    if(!queue.empty()) {
      i = queue.top().first;
      cyc = queue.top().second;
      queue.pop();
    } else {
      for(ll k = 0; k <= n; k ++) {
        if (!visited[k]) {
          i=k;
          cyc.push_back(k);
          break;
        }
      }
    }

    visited[i] = true;
    if (p[i] != i && !visited[p[i]]) {
      cyc.push_back(p[i]);
      queue.emplace(p[i], cyc);
      visited[p[i]] = true;
    } else {
      cyc.push_back(p[i]);
      cycles.push_back(cyc);
     }

    not_visited = find(visited.begin(), visited.end(), false);
  }

  cout << cycles.size()<< "\n";

  for (const auto& cyc: cycles) {
    for (auto c : cyc){
      cout << c << " ";
    }
    cout << "\n";
  }

  return 0;
}