#include <bits/stdc++.h>

using namespace std;

int countEscapeSteps(vector<int> mem) {
    int pc = 0;
    int steps = 0;

    while (pc >= 0 && pc < mem.size()) {
        pc += mem[pc]++;
        steps++;
    }

    return steps;
}

int countEscapeStepsDecrement(vector<int> mem) {
    int pc = 0;
    int steps = 0;

    while (pc >= 0 && pc < mem.size()) {
        int jump = mem[pc];
        jump >= 3 ? mem[pc]-- : mem[pc]++;
        pc += jump;
        steps++;
    }

    return steps;
}

int main() {
    vector<int> mem;

    int t;
    while (cin >> t) mem.push_back(t);

    cout << "Escape in " << countEscapeSteps(mem) << " steps" << endl;
    cout << "Escape in " << countEscapeStepsDecrement(mem)
         << " steps with decrement" << endl;
}
