// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct dent {
  ll i; // seniority
  ll a; // arrive time
  ll t; // scan time

  dent(): i(0), a(0), t(0) {}
  dent(ll i, ll a, ll t): i(i), a(a), t(t) {}
};

int main() {
  // freopen("convention2.in", "r", stdin);
  // freopen("convention2.out", "w", stdout);

  ll i, n, a, t;
  cin >> n;

  vector<dent> dents(n);
  for (i = 0; i < n; i++) {
    cin >> a >> t;
    dents[i] = dent(i, a, t);
  }

  sort(dents.begin(), dents.end(),
    [](const dent& a, const dent& b) {
    if (a.a == b.a) {
      return a.i < b.i;
    }
    return a.a < b.a;
  });

  struct Senior {
    bool operator()(const dent& a, const dent& b) const {
      return a.i > b.i;
    }
  } ;

  ll c_time = 0;
  ll max_wait = 0;
  priority_queue<dent, vector<dent>, Senior> nextdent;
  ll visited = 0;

  while (visited < n || !nextdent.empty()) {
    dent cur_doc;
    if (nextdent.empty()) {
      cur_doc = dents[visited];
      visited += 1;
    } else {
      cur_doc = nextdent.top(); nextdent.pop();
    }
    // cout << cur_doc.i << "\n";
    max_wait = max(max_wait, max(0ll, c_time - cur_doc.a));
    cout << "wait time of " <<cur_doc.i<< " is " << c_time - cur_doc.a << "\n";
    c_time = max(c_time, cur_doc.a);
    c_time += cur_doc.t;
    ll j = visited;
    while (j < n && dents[j].a <= c_time) { // <= ?
      nextdent.push(dents[j]);
      j += 1;
    }
    visited = j;
  }

  cout << max_wait << "\n";
  return 0;
}
