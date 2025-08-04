// Created by Iris Kaplan.
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


void backtrack(ll n, stack<ll>& in, queue<ll>& out, ll sab, ll gef, string& order, vector<string>& valids) {
  // base case - no more ppl in line, my string is ready!
  if (in.empty() && order.size() == n) {
    // cout << order << "\n";
    valids.push_back(order);
  }

  if (in.empty()) {
    return;
  }
  // is in empty
  ll next = in.top(); in.pop();
  if (out.front() == -1*sab) {
    ll outed = out.front() ; out.pop();
    order += "S";
    backtrack(n, in, out, next, gef, order,valids);
    order = order.substr(0, order.size()-1);
    out.push(outed);
    in.push(next);
  }
  if (out.front() == -1*gef) {
    ll outed = out.front() ; out.pop();
    order += "G";
    backtrack(n, in, out, sab, next, order, valids);
    order = order.substr(0, order.size()-1);
    out.push(outed);
    in.push(next);
  }
  if (sab == 0) {
    order += "S";
    backtrack(n,in, out, next, gef, order, valids);
    order = order.substr(0, order.size()-1);
    in.push(next);
  }
  if (gef == 0) {
      order += "G";
      backtrack(n,in, out, sab, next, order, valids);
      order = order.substr(0, order.size()-1);
      in.push(next);
  }
}



int main() {
  ll n;
  cin >> n;
  stack<ll> in;
  queue<ll> out;
  vector<string> valids;
  ll a;
  for (ll i = 0; i < 2*n; i++) {
    cin >> a;
    if (a > 0)
      in.push(a);
    else
      out.push(a);
  }

  string line = "";
  backtrack(n, in, out, 0, 0, line, valids);
  for (auto s: valids) {
    cout << s << "\n";
  }
  cout << "*" << "\n";
  return 0;
}