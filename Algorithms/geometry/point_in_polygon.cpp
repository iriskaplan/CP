// Created by Iris Kaplan.

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()

using ll = long long;

struct Point {
    ll x, y;
    Point() : x(0), y(0) {}
    Point(ll x_, ll y_) : x(x_), y(y_) {}
};

inline __int128 cross(const Point& a, const Point& b) {
    return (__int128)a.x * b.y - (__int128)a.y * b.x;
}

inline __int128 orient(const Point& a, const Point& b, const Point& c) {
    // (b - a) x (c - a)
    return cross(Point{b.x - a.x, b.y - a.y}, Point{c.x - a.x, c.y - a.y});
}

bool on_segment(const Point& a, const Point& b, const Point& p) {
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
        && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

enum class Position { BOUNDARY, INSIDE, OUTSIDE };

Position point_in_polygon(const vector<Point>& poly, const Point& q) {
    int n = sz(poly);
    bool boundary = false;
    int crossings = 0;

    rep(i, 0, n) {
        int j = (i + 1) % n;
        const Point& A = poly[i];
        const Point& B = poly[j];

        // boundary: collinear and within segment
        if (orient(q, A, B) == 0 && on_segment(A, B, q)) {
            boundary = true;
            break;
        }

        // ray cast to the right: check if edge crosses horizontal line at q.y
        if ((A.y > q.y) != (B.y > q.y)) {
            // compute intersection x-coordinate
            long double x_int = A.x + (long double)(B.x - A.x) * (q.y - A.y) / (long double)(B.y - A.y);
            if (q.x < x_int) crossings++;
        }
    }


    if (boundary) return Position::BOUNDARY;
    if (crossings & 1) return Position::INSIDE;
    return Position::OUTSIDE;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<Point> poly(N);
    rep(i, 0, N) {
        cin >> poly[i].x >> poly[i].y;
    }

    rep(i, 0, M) {
        Point query;
        cin >> query.x >> query.y;
        point_in_polygon(poly, query);
    }
}