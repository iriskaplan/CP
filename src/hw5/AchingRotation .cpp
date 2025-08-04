#include <bits/stdc++.h>

using namespace std;
using ll = long long;

typedef pair<ll, ll> pll;

#define PI 3.141592653
#define RAD_TO_DEG (180 / PI)

void fastio() {
  ios::sync_with_stdio(0);
  cin.tie(0);
}

ll ccw (const pll &a, const pll &b, const pll &c) {
  return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

vector<pll> convex_hull(vector<pll> &children) {
  int leftmost_index = 0;

  for (int i = 1; i < children.size(); i++) {
    if (children[i].first < children[leftmost_index].first || (children[i].first == children[leftmost_index].first && children[i].second < children[leftmost_index].second))
      leftmost_index = i;
  }

  pll tmp = children[0];
  children[0] = children[leftmost_index];
  children[leftmost_index] = tmp;

  pll children0 = children[0];

  // Sort the points in increasing order of y/x - Increasing order of angle
  sort(children.begin() + 1, children.end(), [children0](const pll &a, const pll &b) {
    ll c = ccw(children0, a, b);

    if (c != 0)
      return c > 0;

    ll dist1 = (a.first - children0.first) * (a.first - children0.first) +
      (a.second - children0.second) * (a.second - children0.second);
    ll dist2 = (b.first - children0.first) * (b.first - children0.first) +
      (b.second - children0.second) * (b.second - children0.second);

    return dist1 < dist2;
  });

  // Do the whole convex hull logic - always make sure we keep a point that's on the edges of the convex polygon.
  vector<pll> S;
  S.push_back(children[0]);

  for (int i = 1; i < children.size(); i++) {
    if (S.size() < 2) {
      S.push_back(children[i]);
      continue;
    }

    pll c = children[i];

    while (S.size() >= 2) {
      pll b = S[S.size() - 1];
      pll a = S[S.size() - 2];

      if (ccw(a, b, c) < 0)
        S.pop_back();
      else
        break;
    }

    S.push_back(c);
  }

  return S;
}

double get_angle (const pll &a, const pll &b, const pll &c) {
  // Using A _ B = ||A|| _ ||B|| _ cos(_) from lecture
  // In this case, A = (b - a) and B = (b - c)

  double dist_ba = sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
  double dist_bc = sqrt(pow(b.first - c.first, 2) + pow(b.second - c.second, 2));
  ll dot_babc = (b.first - a.first) * (b.first - c.first) + (b.second - a.second) * (b.second - c.second);

  double cos_theta = dot_babc / (dist_ba * dist_bc);

  if (cos_theta > 1) {
    cos_theta = 1;
  } else if (cos_theta < -1) {
    cos_theta = -1;
  }

  double theta = acos(cos_theta);

  // Convert theta from radians to degrees
  return theta * RAD_TO_DEG;
}

int main(){
  fastio();

  short T;
  cin >> T;

  for (short t = 1; t <= T; t++) {
    ll n;
    cin >> n;

    vector<pll> children(n);

    for(int i = 0; i < n; i++)
      cin >> children[i].first >> children[i].second;

    // Remove dupes efficiently
    sort(children.begin(), children.end());
    children.erase(unique(children.begin(), children.end()), children.end());

    if (n < 3) {
      cout << "Case " << t << ": " << 0 << '\n';
      continue;
    }

    vector<pll> ch = convex_hull(children);

    // If we had duplicate children and the convex hull has at most 2 children
    if (ch.size() < 3) {
      cout << "Case " << t << ": " << 0 << '\n';
      continue;
    }

    // Since H is convex, the max angle is going to be minimum between every 3 consecutive neighbors...
    double angle = 180;

    // First case: ch.size() - 1, 0, 1
    pll a = ch[ch.size() - 1];
    pll b = ch[0];
    pll c = ch[1];
    angle = min(angle, get_angle(a, b, c));

    // Middle cases
    for (int i = 1; i < ch.size() - 1; i++) {
      a = ch[i - 1];
      b = ch[i];
      c = ch[i + 1];
      angle = min(angle, get_angle(a, b, c));
    }

    // Last case: ch.size() - 2, ch.size() - 1, 0
    a = ch[ch.size() - 2];
    b = ch[ch.size() - 1];
    c = ch[0];
    angle = min(angle, get_angle(a, b, c));

    cout << "Case " << t << ": " << fixed << setprecision(6) << angle << '\n';
  }

  return 0;
}