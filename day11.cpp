#include <bits/stdc++.h>

using namespace std;

struct Position {
    int x, y;
};

enum class Move { N, NW, NE, S, SW, SE };

Move string2move(string s) {
    s = s.substr(0, 2);
    if (s == "n") return Move::N;
    if (s == "nw") return Move::NW;
    if (s == "ne") return Move::NE;
    if (s == "s") return Move::S;
    if (s == "sw") return Move::SW;
    if (s == "se") return Move::SE;
    cerr << "Bad input: " << s << " Size: " << s.size() << endl;
    exit(-1);
}

Position walk(Position pos, Move move) {
    switch (move) {
    case Move::N:
        pos.y -= 2;
        break;
    case Move::NW:
        pos.x -= (pos.y % 2) ? 0 : 1;
        pos.y -= 1;
        break;
    case Move::NE:
        pos.x += (pos.y % 2) ? 1 : 0;
        pos.y -= 1;
        break;
    case Move::S:
        pos.y += 2;
        break;
    case Move::SW:
        pos.x -= (pos.y % 2) ? 0 : 1;
        pos.y += 1;
        break;
    case Move::SE:
        pos.x += (pos.y % 2) ? 1 : 0;
        pos.y += 1;
        break;
    }

    return pos;
}

int steps2origin(Position pos) {
    int steps = 0;

    while (pos.x) {
        steps++;
        Move dir;
        if (pos.x > 0 && pos.y > 0) {
            dir = Move::NW;
        } else if (pos.x > 0) {
            dir = Move::SW;
        } else if (pos.y > 0) {
            dir = Move::NE;
        } else {
            dir = Move::SE;
        }

        pos = walk(pos, dir);
    }

    while (pos.y) {
        steps++;
        if (pos.y == 1 || pos.y == -1) {
            return steps;
        }
        pos = walk(pos, (pos.y > 0) ? Move::N : Move::S);
    }

    return steps;
}

int main() {
    vector<Move> moves;
    string t;
    while (getline(cin, t, ',')) {
        moves.push_back(string2move(t));
    }

    Position pos{0, 0};
    int max_distance = 0;
    int steps = 0;

    for (auto e : moves) {
        steps++;
        pos = walk(pos, e);
        max_distance = max(max_distance, steps2origin(pos));
    }

    cout << "Moves: " << steps2origin(pos) << endl;
    cout << "Max distance: " << max_distance << endl;
}
