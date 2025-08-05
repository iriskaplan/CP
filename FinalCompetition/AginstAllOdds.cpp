// Problem: https://qoj.ac/problem/8986

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i= a; i<(b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> Matrix;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int count = 0;
  int a;
  rep(i, 0, n) {
    cin >> a;
    if (a % 2 ==1) {
      count += 1;
    }
  }

  cout << count << "\n";
  return 0;
}


