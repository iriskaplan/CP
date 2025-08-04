using namespace std;

// Check if local run or submission
#ifdef local
    const bool dbg = true;
#else
    const bool dbg = false;
#endif

// Super-include of all STL
#include <bits/stdc++.h>

// Use int64 to avoid overflow
#define int int64_t

// Debug tools
#define val(x) #x << " = " << (x)
#define bug(x) cout << val(x) << endl;
#define dout if(dbg) cout

// Code simplification
#define def(x) int x; cin >> x
#define cases def(t); while (t--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)

// using keywords helps shorten code
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vii = vector<ii>;
using vvii = vector<vector<ii>>;
using vs = vector<string>;

// IO
#define tct template<class T>
#define tcab template<class A, class B>
tcab ostream &operator<<(ostream &os, pair<A, B> p) { return os << '{' << p.first << ',' << p.second << '}'; }
tcab istream& operator>>(istream& is, pair<A,B>& p) { return is >> p.first >> p.second; }
tct istream& operator>>(istream& is, vector<T>& v) { for(auto& x : v) is >> x; return is; }
tct ostream& operator<<(ostream& os, vector<T>& v) { for(auto& x : v) os << x; return os; }

int32_t main()
{
    if (dbg) freopen("in.txt", "r", stdin);
    else cin.tie(0)->sync_with_stdio(0);

    return 0;
}
