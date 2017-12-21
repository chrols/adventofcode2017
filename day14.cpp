#include <bits/stdc++.h>

using namespace std;

/// From day 10

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

    oss << setfill('0') << hex;

    for (auto e : denseHash) {
        oss << setw(2) << e;
    }

    return oss.str();
}

// Begin day 14

using HashMatrix = vector<vector<bool>>;

int hexValue(char c) {
    switch (c) {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'a':
        return 10;
    case 'b':
        return 11;
    case 'c':
        return 12;
    case 'd':
        return 13;
    case 'e':
        return 14;
    case 'f':
        return 15;
    }

    throw invalid_argument("Invalid char passed");
}

vector<bool> createHashVector(const string &s) {
    auto hash = knotHash(s);

    vector<bool> r;

    for (auto e : hash) {
        int v = hexValue(e);
        for (int j = 3; j >= 0; j--) {
            r.push_back(v & (1 << j));
        }
    }

    return r;
}

HashMatrix createHashMatrix(const string &s) {
    HashMatrix m;
    for (int i = 0; i < 128; i++) {
        string row(s);
        row.append("-");
        row.append(to_string(i));
        m.push_back(createHashVector(row));
    }

    return m;
}

int countSquares(const HashMatrix &m) {
    int sum = 0;

    for (auto r : m) {
        sum += count_if(r.begin(), r.end(), [](int i) { return (i == 1); });
    }

    return sum;
}

void removeGroup(HashMatrix &m, int x, int y) {
    if (!m[y][x]) return;
    m[y][x] = false;
    if (y > 0) removeGroup(m, x, y - 1);
    if (y < 127) removeGroup(m, x, y + 1);
    if (x > 0) removeGroup(m, x - 1, y);
    if (x < 127) removeGroup(m, x + 1, y);
}

int countGroups(HashMatrix m) {
    int count = 0;

    for (int y = 0; y < 128; y++) {
        for (int x = 0; x < 128; x++) {
            if (m[y][x]) {
                count++;
                removeGroup(m, x, y);
            }
        }
    }
    return count;
}

int main() {
    string t;
    cin >> t;
    HashMatrix m = createHashMatrix(t);

    cout << countSquares(m) << endl;
    cout << countGroups(m) << endl;
}
