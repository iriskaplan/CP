// Eliav, Liel & Iris

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> numbers(n);
    for (ll i = 0; i < n; i++)
        cin >> numbers[i];

    ll i = 0;
    ll j = 60;

    ll maxi;

    while (i < n && j >= 0) {
        maxi = i;
        ll maxval = numbers[i];

        for (ll k = i + 1; k < n; k++) {
            if ((numbers[k] & ((ll) 1 << j)) != 0 && numbers[k] > maxval) {
                maxi = k;
                maxval = numbers[k];
            }
        }

        if ((numbers[maxi] & ((ll) 1 << j)) == 0) {
            j--;
            continue;
        }

        // Swap logic
        ll tmp = numbers[i];
        numbers[i] = numbers[maxi];
        numbers[maxi] = tmp;

        for (ll u = 0; u < n; u++) {
            if ((numbers[u] & ((ll) 1 << j)) != 0 && u != i) {
                numbers[u] ^= numbers[i];
            }
        }

        i++;
        j--;
    }

    ll res = 0;

    for (auto & num : numbers) {
        res ^= num;
    }

    cout << res << endl;

    return 0;
}
