#include <bits/stdc++.h>

using namespace std;

void exchange(vector<char> &p, int a, int b) { swap(p[a], p[b]); }

void spin(vector<char> &p, int d) {
    rotate(p.begin(), p.begin() + (p.size() - d), p.end());
}

void partner(vector<char> &p, char a, char b) {
    auto ita = p.begin();
    auto itb = p.begin();
    ita = find(p.begin(), p.end(), a);
    itb = find(p.begin(), p.end(), b);
    swap(*ita, *itb);
}

void print(vector<char> &p) {
    for (auto e : p) {
        cout << e;
    }
    cout << endl;
}

int main() {
    vector<char> programs, copy;

    for (char c = 'a'; c <= 'p'; c++) {
        programs.push_back(c);
    }

    copy = programs;

    string input;
    cin >> input;
    istringstream iss(input);

    int goal = 1000000000;

    for (int i = 0; i < goal; i++) {
        char t;
        int d;
        int ia, ib;
        char ca, cb;

        while (iss >> t) {
            switch (t) {
            case 'x':  // Exchange
                iss >> ia;
                iss >> t;  // '/'
                iss >> ib;
                exchange(programs, ia, ib);
                break;
            case 's':  // Spin
                iss >> d;
                spin(programs, d);
                break;
            case 'p':  // Partner
                iss >> ca;
                iss >> t;  // '/'
                iss >> cb;
                partner(programs, ca, cb);
                break;
            default:
                cerr << t << endl;
                throw invalid_argument("Unexpected char at this time");
            }
            iss >> t;  // ,
        }
        iss.clear();
        iss.seekg(0);

        if (i == 0) {
            print(programs);
        }

        if (programs == copy) {
            i = goal - (goal % (i + 1)) - 1;
        }
    }

    print(programs);
}
