// Created by Iris Kaplan.

// TA Solution
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct SegTree {
	int n;
	vector<int> seg;
	SegTree(int n) : n(n), seg(4 * n, INF) {}
	void update(int idx, int val, int node, int l, int r) {
		if (l == r) {
			seg[node] = val;
			return;
		}
		int mid = (l + r) >> 1;
		if (idx <= mid)
			update(idx, val, node << 1, l, mid);
		else
			update(idx, val, node << 1 | 1, mid + 1, r);
		seg[node] = min(seg[node << 1], seg[node << 1 | 1]);
	}
	void update(int idx, int val) {
		update(idx, val, 1, 1, n);
	}
	int query(int B, int Y, int node, int l, int r) const {
		if (r < B || seg[node] > Y)
			return -1;
		if (l == r)
			return l;
		int mid = (l + r) >> 1;
		int res = query(B, Y, node << 1, l, mid);
		if (res != -1)
			return res;
		return query(B, Y, node << 1 | 1, mid + 1, r);
	}
	int query(int B, int Y) const {
		return query(B, Y, 1, 1, n);
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, Q; cin >> N >> Q;
	SegTree seg(N);
	for (int q = 0; q < Q; q++) {
		char type;
		cin >> type;
		if (type == 'M') {
			int X, A;
			cin >> X >> A;
			seg.update(A, X);
		} else {
			int Y, B;
			cin >> Y >> B;
			cout << seg.query(B, Y) << '\n';
		}
	}
	return 0;
}
