// Problem: https://qoj.ac/problem/5126

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i= a; i<(b); ++i)
#define all(x) begin(x), end(x)

typedef long long ll;
typedef long double ld;

struct P {
  ll x;
  ll y;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<P> v(n);
  for(ll i = 0; i < n; i++) cin >> v[i].x >> v[i].y;

  ld max_ang = 0;
  ld max_slope = -numeric_limits<ld>::infinity();

  for(ll i = 1; i < v.size(); i++) {
    ll dy = v[i].y;
    ll dx = v[i].x - v[0].x;
    ld slope = (ld) dy / (ld) dx;
    if (slope > max_slope) {
      ld ang = atan2(dy, dx) * (180.0 / M_PI);
      max_ang = max(ang, max_ang);
      max_slope = slope;
    }
  }

  max_slope = -numeric_limits<ld>::infinity();
  for(size_t i = v.size() - 1; i > 0; i--) {
    ll dy = v[i].y;
    ll dx = v[n-1].x - v[i].x;
    ld slope = (ld) dy / (ld) dx;
    if (slope > max_slope) {
      ld ang = atan2(dy, dx) * (180.0 / M_PI);
      max_ang = max(ang, max_ang);
      max_slope = slope;
    }
  }

  cout << setprecision(10) << max_ang << "\n";
  return 0;
}