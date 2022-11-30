#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    char sym;
    vector<Node *> children;

    Node(int val, char sym) : val(val), sym(sym) {}
};

void findBranches(Node *curr, int val, const string &word, vector<pair<int, string>> &branches) {
    if (curr->children.empty()) {
        branches.emplace_back(val, word);
        return;
    }

    for (auto child: curr->children) {
        findBranches(child, val + child->val, word + child->sym, branches);
    }
}

int sumVal(Node *u, Node *v) {
    int sum = 0;
    vector<pair<int, string>> uBranches, vBranches;

    findBranches(u, 0, "", uBranches);
    findBranches(v, 0, "", vBranches);

    for (int i = 0; i < uBranches.size(); i++) {
        for (int j = 0; j < vBranches.size(); j++) {
            if (uBranches[i].second == vBranches[i].second) {
                sum += uBranches[i].first + vBranches[i].first;
            }
        }
    }

    return sum;
}

int main() {
    Node *root = new Node(-1, ' ');

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

    cout << sumVal(n1, n2) << endl;
    cout << sumVal(nn1, nn2) << endl;

    return 0;
}
