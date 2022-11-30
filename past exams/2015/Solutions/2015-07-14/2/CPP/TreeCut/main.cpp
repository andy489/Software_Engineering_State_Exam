#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    vector<Node *> children;

    explicit Node(int data) : data(data) {};

    friend ostream &operator<<(ostream &os, const Node &n) {
        os << n.data;
        return os;
    }
};

class Tree {
    Node *root;

    void clear(Node *n) {
        if (n) {
            for (Node *child: n->children) {
                clear(child);
            }

            delete n;
            n = nullptr;
        }
    }

    void dfs(Node *n) {
        if (n) {
            for (Node *child: n->children) { dfs(child); }
            cout << *n << ' ';
        }
    }

    bool member(Node *n, int x) {
        if (!n) { return false; }
        if (n->data == x) { return true; }

        bool isMemberInChildren = false;

        for (Node *child: n->children) { isMemberInChildren = isMemberInChildren || member(child, x); }

        return isMemberInChildren;
    }

    bool filterOdd(Node *n) {
        if (!n) { return false; }

        if (n->data & 1) {
            clear(n);
            return true;
        }

        for (int i = 0; i < n->children.size();) {
            if (filterOdd(n->children[i])) {
                n->children.erase(n->children.begin() + i);
            } else { i++; }
        }

        return false;
    }

public:

    Tree() {
        root = nullptr;
    }

    explicit Tree(Node *root) : root(root) {}

    ~Tree() {
        clear(root);
    }

    void print() {
        cout << "DFS Tree: ";
        dfs(root);
        cout << endl;
    }

    bool member(int x) {
        return member(root, x);
    }

    void filterOdd() {
        filterOdd(root);
    }

};


int main() {
    Node *root = new Node(8);
    Node *left = new Node(2);
    Node *right = new Node(3);
    Node *first = new Node(4);
    Node *second = new Node(5);
    Node *third = new Node(6);

    right->children.push_back(first);
    right->children.push_back(second);
    right->children.push_back(third);

    root->children.push_back(left);
    root->children.push_back(right);

    Tree *t = new Tree(root);
    t->print();

    int search1 = 1, search2 = 2;

    cout << "Member " << search1 << " is " << (t->member(search1) ? "" : "NOT") << " present" << endl;
    cout << "Member " << search2 << " is " << (t->member(search2) ? "" : "NOT") << " present" << endl;

    t->filterOdd();

    t->print();

    return 0;
}
