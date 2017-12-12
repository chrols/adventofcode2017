#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    vector<int> neighbours;
    bool visited;
};

Node readNode(const string &s) {
    istringstream iss(s);
    Node node;
    iss >> node.id;

    char t;
    iss >> t;
    if (t != '<') exit(-1);
    iss >> t;
    if (t != '-') exit(-1);
    iss >> t;
    if (t != '>') exit(-1);

    int neighbour_id;

    while (iss >> neighbour_id) {
        node.neighbours.push_back(neighbour_id);
        iss >> t;
    }

    node.visited = false;
    return node;
}

void dfsVisitNodes(vector<Node> &nodes, int current_node) {
    if (nodes[current_node].visited) return;

    nodes[current_node].visited = true;

    for (auto e : nodes[current_node].neighbours) {
        dfsVisitNodes(nodes, e);
    }
}

int countVisitedPrograms(const vector<Node> &nodes) {
    return count_if(nodes.begin(), nodes.end(),
                    [](Node n) { return n.visited; });
}

int main() {
    int i;
    string s;

    vector<Node> nodes;

    while (getline(cin, s)) {
        nodes.push_back(readNode(s));
    }

    dfsVisitNodes(nodes, 0);

    cout << "First group contain: " << countVisitedPrograms(nodes)
         << " programs\n";

    int groups = 1;

    while (countVisitedPrograms(nodes) < nodes.size()) {
        groups++;
        auto first_unvisited_it = find_if(nodes.begin(), nodes.end(),
                                          [](Node n) { return !n.visited; });

        dfsVisitNodes(nodes, first_unvisited_it->id);
    }

    cout << "There exists: " << groups << " program groups\n";
}
