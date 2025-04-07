// Iris Kaplan (Burmistrov).

#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int n1;
    int n2;

    for (int i = 0; i < n; i++) {
        cin >> n1;
        cin >> n2;
        if (n1 < n2) {
            cout << "<" << "\n";
        } else if (n1 > n2) {
            cout << ">" << "\n";
        } else {
            cout << "=" << "\n";
        }
    }

    return 0;
}
