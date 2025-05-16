// Eliav, Liel & Iris

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define vi vector<int>

int is_binom_odd(int n, int k, vi &dp){
    return (dp[n] <= (dp[k] +dp[n-k]));
}

int main() {
    fastio();
    int n = 1;
    cin >> n;
    vi exp_of_2_in_factorial(n+1, 0);
    FOR(k, 1, n+1) exp_of_2_in_factorial[k] = k/2 + exp_of_2_in_factorial[k/2];
    ll res = 0;
    n--;
    FOR(k, 0, n+1){
        ll cur;
        cin >> cur;
        res ^= cur*is_binom_odd(n, k, exp_of_2_in_factorial);
    }
    cout << res;
    return 0;
}
