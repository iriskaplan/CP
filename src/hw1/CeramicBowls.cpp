// Iris Kaplan (Burmistrov).

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<unordered_map<string, int>> bowls_m;
    string bowl;

    for (int i = 0; i < n; i ++) {
        cin >> bowl;
        bool did_add = false;
        for (auto& bowls: bowls_m) {
            if (bowls.find(bowl) == bowls.end() && !did_add) {
                bowls[bowl] = 1;
                did_add = true;
            }
        }

        if (!did_add) {
            unordered_map<string, int> b;
            b[bowl] = 1;
            bowls_m.push_back(b);
        }
    }

    cout << bowls_m.size() << endl;
    return 0;
}