// Iris Kaplan (Burmistrov).

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long s = 0;
    vector<long long> temps;

    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        temps.push_back(stoi(tmp));
    }

    long long c_max, c_min;

    for (int i = 0; i < n; i++) {
        c_max = temps[i];
        c_min = temps[i];

        for (int j = i; j < n; j++) {
            c_max = max(c_max, temps[j]);
            c_min = min(c_min, temps[j]);
            s += c_max - c_min;
        }
    }

    cout << s << "\n";
    return 0;
}
