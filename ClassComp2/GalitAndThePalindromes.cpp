// Created by Iris Kaplan.

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
typedef vector<ll> vll;


int main() {
	ll n;
	cin >> n;
	vll a (n);
	for(ll& x: a) cin >> x;
	ll i = 0, j = n-1;
	int steps = 0;
	while(i < j) {
		if(a[i] < a[j]) {
			a[i+1] += a[i];
			steps += 1;
			i++;
		} else if (a[i] > a[j]) {
			a[j-1] += a[j];
			steps+=1;
			j--;
		} else {
			i++;
			j--;
		}
	}

	cout << steps << "\n";
	return 0;
}