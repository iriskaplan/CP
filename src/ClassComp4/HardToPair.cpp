#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n;
    cin >> n;
    bool is_pos = false;

    // 0 - left, 1 - right, 2 - any
    unordered_map<string, array<int, 3>> shoes;
    for(int i = 0; i < n; i++) {
      string s, t;
      int k;
      cin >> s >> t >> k;
      ll idx = 0;
      if (t == "right") {
        idx = 1;
      } else if (t =="any") {
        idx=2;
      }
      shoes[s][idx] = k;
      is_pos |= ((shoes[s][0] > 0 && shoes[s][1]) || (shoes[s][2] > 1));
    }

    if (is_pos) {
     int m = 0;
     for(auto& k_v: shoes) {
       string style = k_v.first;
       auto counts = k_v.second;
      	m += max(max(counts[0], counts[1]), min(1, counts[2]));
      }
      cout << m +1;
    } else {
      cout << "impossible";
    }
   	return 0;
}