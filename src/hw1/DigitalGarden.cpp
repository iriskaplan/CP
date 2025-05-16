// Iris Kaplan (Burmistrov).

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    std::unordered_map<string, int> garden;

    string command;
    string value;
    int homos = 0;
    for (int i = 0; i < n; i ++) {
        cin >> command;
        cin >> value;

        if (command == "insert") {
            if (garden.find(value) == garden.end()){
              garden[value] = 1;
            } else {
                if (garden[value] == 1) {
                    homos += 1;
                }
                garden[value] += 1;
            }
        } else if (command == "delete") {
            if (garden.find(value) != garden.end()){
                garden[value] -= 1;
                if (garden[value] == 0) {
                    garden.erase(value);
                } else if (garden[value] == 1) {
                    homos -= 1;
                }
            }
        }
        bool homo = homos > 0;
        bool hetero = garden.size() > 1;

        if (homo and hetero) {
          cout << "both" << endl;
        } else if (homo) {
            cout << "homo" << endl;
        } else if (hetero) {
            cout << "hetero" << endl;
        } else {
            cout << "neither" << endl;
        }
    }

    return 0;
}