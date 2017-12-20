#include <bits/stdc++.h>

using namespace std;

set<vector<int>> myset;

void redistribute(vector<int> &mem) {
    auto it = max_element(mem.begin(), mem.end());
    int redist = *it;
    *it = 0;
    while (redist) {
        it++;
        if (it == mem.end()) it = mem.begin();
        (*it)++;
        redist--;
    }
}

int main() {
    vector<int> a;

    int t;

    while (cin >> t) {
        a.push_back(t);
    }

    int i = 0;

    while (myset.find(a) == myset.end()) {
        i++;
        myset.insert(a);
        redistribute(a);
    }

    cout << i << endl;

    vector<int> target = a;
    i = 1;
    redistribute(a);

    while (a != target) {
        redistribute(a);
        i++;
    }

    cout << i << endl;
}
