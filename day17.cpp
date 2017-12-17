#include <bits/stdc++.h>

using namespace std;

int performSpinlock(int steps, int numValues, int target) {
    list<int> buffer;

    auto position = buffer.begin();

    for (int n = 0; n <= numValues; n++) {
        for (int i = 0; i < steps; i++) {
            position++;
            if (position == buffer.end()) {
                position = buffer.begin();
            }
        }
        position++;
        buffer.insert(position, n);
        position--;
    }

    position = find(buffer.begin(), buffer.end(), target);
    position++;
    if (position == buffer.end()) position = buffer.begin();

    return *position;
}

int main() {
    cout << performSpinlock(356, 2017, 2017) << endl;
    cout << performSpinlock(356, 50000000, 0) << endl;
}
