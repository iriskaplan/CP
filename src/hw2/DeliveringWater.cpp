// Created by Iris Kaplan.

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

struct plant {
  ll x;
  ll m;

  plant(ll x, ll m) : x(x), m(m) {}

  bool operator<(const plant& other) const {
    return x < other.x;
  }
};

ll count_steps(vector<plant>& plants, ll k) {
  ll steps = 0;
  ll c = plants.size() - 1;

  while (c >= 0) {
    if (plants[c].m == 0) {
      c -= 1;
      continue;
    }

    ll trips = (plants[c].m + k - 1) / k;
    ll c_steps = plants[c].x;
    ll bucket = k * trips;

    while (c >= 0 && bucket > 0) {
      ll want = plants[c].m;
      ll give = min(bucket, want);
      plants[c].m -= give;
      bucket -= give;

      if (plants[c].m == 0) {
        c -= 1;
      } else {
        break;
      }
    }

    steps += 2 * c_steps * trips;
  }

  return steps;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  ll n, k;
  cin >> n >> k;

  vector<plant> negative, positive;

  for(int i = 0; i < n; i++) {
    ll x, m;
    cin >> x >> m;
    if (x > 0) {
      positive.emplace_back(x, m);
    } else {
      negative.emplace_back(-1*x, m);
    }
  }

  sort(positive.begin(), positive.end());
  sort(negative.begin(), negative.end());

  ll steps = count_steps(positive, k) + count_steps(negative, k);
  cout << steps << "\n";

  return 0;
}