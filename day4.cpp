#include <bits/stdc++.h>

using namespace std;

bool valid(const string &s, bool with_anagram = false) {
    set<string> pass;
    istringstream iss(s);
    string word;

    while (iss >> word) {
        if (with_anagram) {
            sort(word.begin(), word.end());
        }

        if (pass.count(word)) {
            return false;
        } else {
            pass.insert(word);
        }
    }

    return true;
}

int main(int argc, char **argv) {
    ifstream input("input04.txt");

    string s;

    int valid_passes = 0;
    int anagram_valid_passes = 0;

    while (getline(input, s)) {
        if (valid(s)) valid_passes++;
        if (valid(s, true)) anagram_valid_passes++;
    }

    cout << valid_passes << endl;
    cout << anagram_valid_passes << endl;
}
