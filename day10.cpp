#include <bits/stdc++.h>

using namespace std;

const int kListSize = 256;

vector<int> createKnotHash(int rounds, vector<int> &length) {
    vector<int> list;

    for (int i = 0; i < kListSize; i++) {
        list.push_back(i);
    }

    int pos = 0;
    int skipSize = 0;

    for (int i = 0; i < rounds; i++) {
        for (auto &l : length) {
            for (int j = 0; j < l / 2; j++) {
                swap(list[(pos + j) % kListSize],
                     list[(pos + l - j - 1) % kListSize]);
            }
            pos = (pos + l + skipSize) % kListSize;
            skipSize++;
        }
    }

    return list;
}

string knotHash(string s) {
    vector<int> length;
    length.insert(length.end(), s.begin(), s.end());

    vector<int> suffix{17, 31, 73, 47, 23};
    length.insert(length.end(), suffix.begin(), suffix.end());

    auto sparseHash = createKnotHash(64, length);

    vector<int> denseHash(16, 0);

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            denseHash[i] ^= sparseHash[i * 16 + j];
        }
    }

    ostringstream oss;

    oss << hex;

    for (auto e : denseHash) {
        oss << e;
    }

    return oss.str();
}

int solvePart1(string s) {
    istringstream iss(s);
    vector<int> length;
    string t;

    while (getline(iss, t, ',')) {
        length.push_back(stoi(t));
    }

    auto list = createKnotHash(1, length);
    return (list[0] * list[1]);
}

int main() {
    vector<int> length;

    string t;
    cin >> t;

    cout << solvePart1(t) << endl;
    cout << knotHash(t) << endl;
}
