// Iris Kaplan (Burmistrov).

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_set>
#include <stack>
#include <algorithm>

using namespace std;


int center(int n) {
    if (n >= 65 && n <= 90) {
      return n-65;
    }
    return n-97;
}

string sort_word(string word) {
    struct
    {
        bool operator()(char a, char b) const {
          int asc_a = int(a);
          int asc_b = int(b);
          int c_a = center(a);
          int c_b = center(b);

          if (c_a < c_b) {
            return false;
          }
          if ( c_a > c_b) {
              return true;
          }
          return asc_a > asc_b;
        }
    }
    customMore;

    std::sort(word.begin(), word.end(), customMore);
    return word;
}

struct hash_pair {
    size_t operator()(const pair<string, string>& p) const {
        return hash<string>()(p.first) ^ hash<string>()(p.second);
    }
};

void dfs(const string& word){
    std::stack<pair<string, string>> s;
    s.emplace("", word);
    unordered_set<pair<string, string>, hash_pair> visited;

    while (!s.empty()) {
        auto cur = s.top();
        s.pop();

        if (cur.second.empty()) {
            cout << cur.first << endl;
        } else {
            for (int i = 0; i < cur.second.size(); i++) {
                string new_s = cur.first + cur.second[i];
                string left_w = cur.second;
                left_w.erase(i, 1);
                if (visited.find({new_s, left_w}) == visited.end()) {
                    s.emplace(new_s, left_w);
                    visited.insert({new_s, left_w});
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> words;
    string word;
    for (int i = 0; i < n; i++) {
        cin >> word;
        words.push_back(word);
    }

    for (int i = 0; i < n; i++) {
        const string& w = words[i];
        string sorted = sort_word(w);
        dfs(sorted);
    }
    return 0;
}