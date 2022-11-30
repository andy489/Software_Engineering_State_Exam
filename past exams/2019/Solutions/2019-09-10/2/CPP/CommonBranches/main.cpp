#include <iostream>
#include <vector>

using namespace std;

struct Node {
    unsigned int value;
    char label;
    vector<Node *> children;

    Node(unsigned int value, char label) : value(value), label(label) {}
};

void findBranches(Node *curr, unsigned int val, const string &word, vector<pair<unsigned int, string>> &branches) {
    if (curr->children.empty()) {
        branches.emplace_back(val, word);
        return;
    }

    for (auto child: curr->children) {
        findBranches(child, val + child->value, word + child->label, branches);
    }
}

void CommonBranches(Node *u, Node *v, unsigned int k) {
    vector<pair<unsigned int, string>> uBranches, vBranches;

    findBranches(u, 0, "", uBranches);
    findBranches(v, 0, "", vBranches);

    for (int i = 0; i < uBranches.size(); i++) {
        for (int j = 0; j < vBranches.size(); j++) {
            if (uBranches[i].first + vBranches[i].first == k && uBranches[i].second == vBranches[i].second) {
                cout << uBranches[i].second << endl;
            }
        }
    }
}

int main() {
    Node *root = new Node(0, ' ');

    Node *n1 = new Node(1, 'a');
    Node *n2 = new Node(2, 'a');

    Node *nn1 = new Node(2, 'b');
    Node *nn2 = new Node(1, 'b');

    Node *nnn1 = new Node(3, 'c');
    Node *nnn2 = new Node(3, 'c');

    nn1->children.push_back(nnn1);
    nn2->children.push_back(nnn2);

    n1->children.push_back(nn1);
    n2->children.push_back(nn2);

    root->children.push_back(n1);
    root->children.push_back(n2);

    CommonBranches(n1, n2, 9);

    return 0;
}
