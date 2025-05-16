// Iris Kaplan (Burmistrov).

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> sort_words(vector<string> words) {
    const struct
    {
        bool operator()(const string &a, const string &b) const {
            return a + b < b + a;
        }
    }
    customLess;

    std::sort(words.begin(), words.end(), customLess);
    return words;
}


int main() {
    int n;
    cin >> n;

    vector<string> labels;
    string label;

    for (int i = 0; i < n; i ++) {
        cin >> label;
        labels.push_back(label);
    }

    vector<string> sorted_l = sort_words(labels);

    string lex_label;
    for (int i = 0; i < n; i ++) {
        lex_label += sorted_l[i];
    }

    cout << lex_label << endl;
    return 0;
}
