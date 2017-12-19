#include <bits/stdc++.h>

using namespace std;

using Square = map<int, map<int, int>>;

enum Direction { North, South, West, East };

struct Position {
    int x;
    int y;
};

Direction turnLeft(Direction d) {
    switch (d) {
    case North:
        return West;
    case South:
        return East;
    case West:
        return South;
    case East:
        return North;
    }
}

Position stepForward(Position p, Direction d) {
    switch (d) {
    case North:
        p.x++;
        break;
    case South:
        p.x--;
        break;
    case West:
        p.y--;
        break;
    case East:
        p.y++;
        break;
    }

    return p;
}

int manhattanDistanceToOrigin(Position p) { return (abs(p.x) + abs(p.y)); }

int solvePart1(int goal) {
    Square square;
    Position p{0, 0};
    int i = 1;
    Direction d = East;

    while (i < goal) {
        square[p.x][p.y] = i++;
        p = stepForward(p, d);

        Direction newD = turnLeft(d);
        Position np = stepForward(p, newD);
        if (!square[np.x][np.y]) {
            d = newD;
        }
    }

    return manhattanDistanceToOrigin(p);
}

int environmentSum(Position p, Square &s) {
    int sum = 0;
    sum += s[p.x - 1][p.y - 1];
    sum += s[p.x - 1][p.y];
    sum += s[p.x - 1][p.y + 1];
    sum += s[p.x][p.y - 1];
    sum += s[p.x][p.y + 1];
    sum += s[p.x + 1][p.y - 1];
    sum += s[p.x + 1][p.y];
    sum += s[p.x + 1][p.y + 1];

    if (!sum) sum = 1;
    return sum;
}

int solvePart2(int goal) {
    Square square;
    Position p{0, 0};
    Direction d = East;

    while (true) {
        int squareValue = environmentSum(p, square);
        if (squareValue > goal) return squareValue;
        square[p.x][p.y] = squareValue;
        p = stepForward(p, d);

        Direction newD = turnLeft(d);
        Position np = stepForward(p, newD);
        if (!square[np.x][np.y]) {
            d = newD;
        }
    }
}

int main() {
    int goal;
    cin >> goal;
    cout << solvePart1(goal) << endl;
    cout << solvePart2(goal) << endl;
}
