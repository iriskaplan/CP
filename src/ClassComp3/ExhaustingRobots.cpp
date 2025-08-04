// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

void fastio() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
}

int main() {
	fastio();

	ll t;
	cin >> t;

	while (t--) {
		ll l1, a1, l2, a2, lt, at;

		cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;

		ll num_solutions = 0;
		ll best_n = 0, best_m = 0;

		for (ll n = 1; n <= 10000; n++) {
			ll m = at - n * a1;

			if (m < 0 || m % a2)
				// break;

			if (n * l1 + m * l2 == lt) {
				best_n = n;
				best_m = m;

				num_solutions++;
			}
		}

		if (num_solutions != 1) {
			cout << '?' << '\n';
		} else {
			cout << best_n << ' ' << best_m << '\n';
		}
	}

	return 0;
}
