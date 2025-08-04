// Created by Iris, Liel & Eliav.
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

typedef pair<ll, ll> pll;

void fastio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

ll direction (const pll &a, const pll &b, const pll &c) {
  return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

vector<pll> convex_hull(vector<pll> &points) {
  int leftmost_index = 0;

  for (int i = 1; i < points.size(); i++) {
    if (points[i].first < points[leftmost_index].first || (points[i].first == points[leftmost_index].first
      && points[i].second < points[leftmost_index].second))
      leftmost_index = i;
  }

  pll tmp = points[0];
  points[0] = points[leftmost_index];
  points[leftmost_index] = tmp;

  pll p0 = points[0];

  sort(points.begin() + 1, points.end(), [p0](const pll &a, const pll &b) {
    ll c = direction(p0, a, b);

    if (c != 0)
      return c > 0;

    ll dist1 = (a.first - p0.first) * (a.first - p0.first) +
      (a.second - p0.second) * (a.second - p0.second);
    ll dist2 = (b.first - p0.first) * (b.first - p0.first) +
      (b.second - p0.second) * (b.second - p0.second);

    return dist1 < dist2;
  });

  vector<pll> S;
  S.push_back(points[0]);

  for (int i = 1; i < points.size(); i++) {
    if (S.size() < 2) {
      S.push_back(points[i]);
      continue;
    }

    pll c = points[i];

    while (S.size() >= 2) {
      pll b = S[S.size() - 1];
      pll a = S[S.size() - 2];

      if (direction(a, b, c) < 0)
        S.pop_back();
      else
        break;
    }

    S.push_back(c);
  }

  return S;
}

bool on_segment(pll p1, pll p2, pll p3) {
  return min(p1.first, p2.first) <= p3.first && p3.first <= max(p1.first, p2.first) &&
         min(p1.second, p2.second) <= p3.second && p3.second <= max(p1.second, p2.second);
}

// segment intersect algorithm from cormen
bool segments_intersect(pll p1, pll p2, pll p3, pll p4) {
  ll d1 = direction(p3, p4, p1);
  ll d2 = direction(p3, p4, p2);
  ll d3 = direction(p1, p2, p3);
  ll d4 = direction(p1, p2, p4);

  if (d1 * d2 < 0 && d3 * d4 < 0) {
    return true;
  } if (d1 == 0 && on_segment(p3, p4, p1)) {
    return true;
  } if (d2 == 0 && on_segment(p3, p4, p2)) {
    return true;
  } if (d3 == 0 && on_segment(p1, p2, p3)) {
    return true;
  } if (d4 == 0 && on_segment(p1, p2, p4)) {
    return true;
  }
  return false;
}

// ray casting
bool point_in_polygon(pll p, const vector<pll> &conv_h) {
  ll cnt = 0;
  for (ll i = 0; i < conv_h.size(); i++) {
    pll p1 = conv_h [i], p2 = conv_h[(i+1)% conv_h.size()];
    if (p1.second > p2.second) swap(p1, p2);
    if (p.second > p1.second && p.second <= p2.second && direction(p1, p2, p) > 0) {
      cnt ++;
    }
  }
  return cnt % 2 == 1;
}

bool polygons_separable(const vector<pll> &conv_a, const vector<pll> &conv_b) {
  ll n = conv_a.size(), m = conv_b.size();
  // check if any 2 edges intersect
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      pll p1 = conv_a[i], p2 = conv_a[(i+1)%n];
      pll p3 = conv_b[j], p4 = conv_b[(j+1)%m];
      if (segments_intersect(p1, p2, p3, p4)) {
        return false;
      }
    }
  }
  if (point_in_polygon(conv_a[0], conv_b) || point_in_polygon(conv_b[0], conv_a)) return false;
  return true;
}

int main() {
  fastio();

  ll n, m;
  while (cin >> n >> m) {
    if (n== 0 && m == 0) {
      break;
    }

    ll a,b;
    vector<pll> a_points(n);

    for(ll i = 0; i < n ; i++){
      cin >> a >> b;
      a_points[i] = make_pair(a,b);
    }

    vector<pll> b_points(m);

    for(ll i = 0; i < m; i++){
      cin >> a >> b;
      b_points[i] = make_pair(a,b);
    }

    vector<pll> conv_a = convex_hull(a_points);
    vector<pll> conv_b = convex_hull(b_points);

    bool is_possible = false;
    if (polygons_separable(conv_a, conv_b)) {
      is_possible = true;
    }

    cout << (is_possible ? "YES" : "NO") << "\n";
  }

  return 0;
}
