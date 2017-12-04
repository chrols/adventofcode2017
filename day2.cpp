#include <bits/stdc++.h>

using namespace std;

using Row = vector<int>;

Row str2row(const string &s) {
    Row r;
    istringstream iss(s);
    int t;
    while (iss >> t) {
        r.push_back(t);
    }

    return r;
}

int minMaxDiff(const Row &r) {
    int min = INT_MAX;
    int max = INT_MIN;

    for (auto &e : r) {
        min = std::min(min, e);
        max = std::max(max, e);
    }

    return (max - min);
}

int checksum(const vector<Row> &t) {
    int sum = 0;

    for (auto &e : t) {
        sum += minMaxDiff(e);
    }

    return sum;
}

int evenDivision(const Row &r) {
    for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r.size(); j++) {
            if (i == j) continue;

            if (r[i] % r[j] == 0) {
                return (r[i] / r[j]);
            }
        }
    }

    cerr << "Should not be reached" << endl;
    exit(-1);
}

int sumDivision(const vector<Row> &t) {
    int sum = 0;

    for (auto &e : t) {
        sum += evenDivision(e);
    }

    return sum;
}

int main(int argc, char **argv) {
    Row r1 = str2row("5 1 9 5");
    Row r2 = str2row("7 5 3");
    Row r3 = str2row("2 4 6 8");

    cout << minMaxDiff(r1) << ":";
    cout << minMaxDiff(r2) << ":";
    cout << minMaxDiff(r3) << ":";

    vector<Row> t;
    t.push_back(r1);
    t.push_back(r2);
    t.push_back(r3);

    cout << "\n" << checksum(t) << "\n";

    ifstream in("input-day2");

    string s;
    t.clear();

    while (getline(in, s)) {
        t.push_back(str2row(s));
    }

    cout << checksum(t) << "\n";

    cout << evenDivision(str2row("5 9 2 8")) << endl;
    cout << evenDivision(str2row("9 4 7 3")) << endl;
    cout << evenDivision(str2row("3 8 6 5")) << endl;

    cout << sumDivision(t) << endl;
}
