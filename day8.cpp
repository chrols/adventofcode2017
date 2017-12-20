#include <bits/stdc++.h>

using namespace std;

struct Instruction {
    string destinationRegister;
    bool increment;
    int value;
    string comparisonRegister;
    function<bool(int, int)> comparison;
    int comparisonValue;
};

Instruction readInstruction(string s) {
    Instruction i;
    istringstream iss(s);

    iss >> i.destinationRegister;

    string t;
    iss >> t;
    if (t == "inc") {
        i.increment = true;
    } else if (t == "dec") {
        i.increment = false;
    } else {
        throw - 1;
    }

    iss >> i.value;

    iss >> t;

    if (t != "if") throw - 1;

    iss >> i.comparisonRegister;

    iss >> t;

    if (t == "==") {
        i.comparison = equal_to<int>();
    } else if (t == ">=") {
        i.comparison = greater_equal<int>();
    } else if (t == "<=") {
        i.comparison = less_equal<int>();
    } else if (t == ">") {
        i.comparison = greater<int>();
    } else if (t == "<") {
        i.comparison = less<int>();
    } else if (t == "!=") {
        i.comparison = not_equal_to<int>();
    } else {
        throw - 1;
    }

    iss >> i.comparisonValue;

    return i;
}

int main() {
    vector<Instruction> instructions;
    map<string, int> reg;
    string t;

    while (getline(cin, t)) {
        instructions.push_back(readInstruction(t));
    }

    int largestEver = 0;

    for (auto &e : instructions) {
        if (e.comparison(reg[e.comparisonRegister], e.comparisonValue)) {
            if (e.increment) {
                reg[e.destinationRegister] += e.value;
            } else {
                reg[e.destinationRegister] -= e.value;
            }
        }

        largestEver = max(largestEver, reg[e.destinationRegister]);
    }

    int largest = 0;

    for (auto e : reg) {
        largest = max(largest, e.second);
    }

    cout << largest << endl;
    cout << largestEver << endl;
}
