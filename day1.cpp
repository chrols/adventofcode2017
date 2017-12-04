#include <bits/stdc++.h>

using namespace std;

vector<int> convertToVector(const string &s) {
    vector<int> r;
    istringstream iss(s);

    char first, t1, t2;

    iss >> first;
    t1 = first;

    while (iss >> t2) {
        if (t1 == t2) {
            r.push_back(int(t2 - '0'));
        }
        t1 = t2;
    }

    if (t1 == first) {
        r.push_back(int(t2 - '0'));
    }

    return r;
}

vector<int> convertToVector2(const string &s) {
    vector<int> r;
    istringstream iss(s);

    char t;

    while (iss >> t) {
        r.push_back(int(t - '0'));
    }

    return r;
}

int answerFirst(const string &s) {
    auto vec = convertToVector(s);
    return accumulate(vec.begin(), vec.end(), 0);
}

int answerSecond(const string &s) {
    auto vec = convertToVector2(s);

    int sum = 0;
    int half = (s.size() / 2);

    for (int i = 0; i < s.size(); i++) {
        if (vec[i] == vec[(i + half) % s.size()]) {
            sum += vec[i];
        }
    }

    return sum;
}

int main(int argc, char **argv) {
    string s;
    getline(cin, s);

    cout << "Part 1: " << answerFirst(s) << endl;
    cout << "Part 2: " << answerSecond(s) << endl;
}
