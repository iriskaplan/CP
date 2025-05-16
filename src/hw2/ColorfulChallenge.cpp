// Created by Iris Kaplan.

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

void backtrack(vector<int>& v_c, const unordered_map<int, vector<int>>& adjecent, int visiting, ll& best_color_size,
               vector<int>& best_colored_nodes) {
  if (visiting >= v_c.size()) {
  	if (count(v_c.begin(), v_c.end(), 1) > best_color_size) {
  		best_colored_nodes = v_c;
  		best_color_size = count(v_c.begin(), v_c.end(), 1);
  	}
    return;
  }

  bool can_color = true;
  for(auto i : adjecent.at(visiting)) {
	if (v_c[i] == 1) {
		can_color = false;
	      break;
	    }
  }

  if(can_color) {
    v_c[visiting] = 1;
    backtrack(v_c, adjecent, visiting+1, best_color_size, best_colored_nodes);
  }
	v_c[visiting] = 0;
	backtrack(v_c, adjecent, visiting+1, best_color_size, best_colored_nodes);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int n, k;
        cin >> n >> k;

    	unordered_map<int, vector<int>> adjecent;
    	for (int w = 0; w <= n; w++) {
    		adjecent[w] = vector<int>();
    	}

        int u, v;
        for (int j = 0; j < k; j++) {
          cin >> u >> v;
          adjecent[u].push_back(v);
          adjecent[v].push_back(u);
        }

        vector<int> v_c (n+1, 2);
        ll best_size = 0;
    	vector<int> best_colored (n+1, 2);

    	backtrack(v_c, adjecent, 1, best_size, best_colored);

        cout << best_size << "\n";
    	bool first = true;
        for (int i1 = 1; i1 <= n; i1++){
          if (best_colored[i1] == 1) {
          	if (!first) cout << " ";
            cout << i1;
          	first = false;
          }
        }
        cout << "\n";
    }

    return 0;
}
