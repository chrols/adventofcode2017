#include <bits/stdc++.h>

using namespace std;

struct Scanner {
    int layer, range, position, delta;
};

void moveScanners(vector<Scanner> &firewall) {
    for (auto &e : firewall) {
        if (e.delta == 1 && e.position == e.range - 1) {
            e.delta = -1;
        } else if (e.delta == -1 && e.position == 0) {
            e.delta = 1;
        }

        e.position += e.delta;
    }
}

int severity(vector<Scanner> firewall) {
    int max_layer = firewall[firewall.size() - 1].layer;
    int severity = 0;

    for (int pos = 0; pos <= max_layer; pos++) {
        for (auto &e : firewall) {
            if (e.layer == pos && e.position == 0) {
                severity += (e.layer * e.range);
            }
        }
        moveScanners(firewall);
    }

    return severity;
}

bool detected(vector<Scanner> firewall) {
    int max_layer = firewall[firewall.size() - 1].layer;

    for (int pos = 0; pos <= max_layer; pos++) {
        for (auto &e : firewall) {
            if (e.layer == pos && e.position == 0) {
                return true;
            }
        }
        moveScanners(firewall);
    }

    return false;
}

int main() {
    int layer, range;
    char sep;

    vector<Scanner> firewall;

    while (cin >> layer >> sep >> range) {
        Scanner scanner;
        scanner.layer = layer;
        scanner.range = range;
        scanner.position = 0;
        scanner.delta = 1;
        firewall.push_back(scanner);
    }

    cout << "Severity: " << severity(firewall) << "\n";

    int delay = 0;

    while (detected(firewall)) {
        delay++;
        moveScanners(firewall);
    }

    cout << "Required delay: " << delay << "\n";
}
