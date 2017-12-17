#include <bits/stdc++.h>

using u64 = uint64_t;

using namespace std;

u64 nextA(u64 n) { return ((n * 16807) % 2147483647); }

u64 nextB(u64 n) { return ((n * 48271) % 2147483647); }

int main() {
    u64 start_a = 65;
    u64 start_b = 8921;

    cin >> start_a;
    cin >> start_b;

    u64 a = start_a;
    u64 b = start_b;

    int matching = 0;

    for (int i = 0; i < 40000000; i++) {
        a = nextA(a);
        b = nextB(b);

        if ((a & 0xFFFF) == (b & 0xFFFF)) matching++;
    }

    cout << "Matching: " << matching << endl;

    a = start_a;
    b = start_b;

    matching = 0;

    for (int i = 0; i < 5000000; i++) {
        do {
            a = nextA(a);
        } while (a % 4 != 0);

        do {
            b = nextB(b);
        } while (b % 8 != 0);

        if ((a & 0xFFFF) == (b & 0xFFFF)) matching++;
    }

    cout << "Matching: " << matching << endl;
}
