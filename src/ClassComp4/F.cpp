#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

void fastio() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}

ll gcd (ll a, ll b) {
  ll a1 = max(a, b);
  ll b1 = min(a, b);

  if (b1 == 0) return a1;
  return gcd (b1, a1 % b1);
}

int main() {
  ll c, d;

  cin >> c >> d;

  ll num_numbers = (d - c) + 1;

  vector<ll> numbers(num_numbers);
  vector<ll> fizz;
  vector<ll> buzz;
  // vector<ll> fizzbuzz;

  // read input. Fizz = -1, Buzz = -2, FizzBuzz = -3
  for (ll i = c; i <= d; i++) {
    string input;
    cin >> input;

    if (input == "Fizz") {
      numbers[i - c] = -1;
      fizz.push_back(i);
    } else if (input == "Buzz") {
      numbers[i - c] = -2;
      buzz.push_back(i);
    } else if (input == "FizzBuzz") {
      numbers[i - c] = -3;
      fizz.push_back(i);
      buzz.push_back(i);
    } else {
      numbers[i - c] = i;
    }
  }

  // todo: what if one of them is empty?
  ll fizz_gcd = fizz[0];
  ll buzz_gcd = buzz[0];
  // ll fizzbuzz_gcd = fizzbuzz[0];

  for (ll i = 0; i < fizz.size(); i++) {
    fizz_gcd = gcd(fizz_gcd, fizz[i]);
  }

  for (ll i = 0; i < buzz.size(); i++) {
    buzz_gcd = gcd(buzz_gcd, buzz[i]);
  }

  cout << fizz_gcd << ' ' << buzz_gcd << '\n';

  return 0;
}