#include <bits/stdc++.h>

using namespace std;

int readGarbage(istream &input) {
    char c;

    int removed = 0;

    while (input >> c) {
        switch (c) {
        case '!':
            input >> c;
            break;
        case '>':
            return removed;
        default:
            removed++;
            break;
        }
    }
}

pair<int,int> read(istream &input)
{
    int score = 0;
    int depth = 0;
    int removed = 0;
    char c;

    while (input >> c) {
        switch (c) {
        case '{':
            depth++;
            break;
        case '<':
            removed += readGarbage(input);
            break;
        case '}':
            score += depth;
            depth--;
            break;
        case ',':
            break;
        default:
            cerr << "Unexpected char: " << c << endl;
            throw -1;
        }
    }

    return {score, removed};
}

int main() {
    auto res = read(cin);
    cout << res.first << endl;
    cout << res.second << endl;
}
