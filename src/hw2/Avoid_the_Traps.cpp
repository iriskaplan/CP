
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string line;

	vector<vector<char> > arr;
    for (int i = 0; i < n; i++) {
        cin >> line;
        vector<char> tmp;
        for (int j = 0; j < n; j++){
          tmp.push_back(line[j]);
        }
        arr.push_back(tmp);
    }

	int mod = 1e9 + 7;
	vector<vector<int> > dp(n, vector<int>(n, 0));
	if (arr[0][0] != '*') {
		dp[0][0] = 1;
	}

    for (int i=1; i < n; i++) {
      if (arr[0][i] != '*') {
        dp[0][i] = dp[0][i-1];
      }
    }

	for (int i=1; i < n; i++) {
		if (arr[i][0] != '*') {
			dp[i][0] = dp[i-1][0];
		}
	}

    for (int i=1; i < n; i++) {
    	for(int j = 1; j < n; j++){
          if (arr[i][j] != '*') {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
          }
    	}
    }

	cout << dp[n-1][n-1] % mod << "\n";

    return 0;
}