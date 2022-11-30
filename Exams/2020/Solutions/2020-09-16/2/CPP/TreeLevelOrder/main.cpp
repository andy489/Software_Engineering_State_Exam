#include <iostream>
#include <list>

using namespace std;

struct Node {
    char text;
    Node *left, *right;

    explicit Node(char text, Node *l = nullptr, Node *r = nullptr) : text(text), left(l), right(r) {}
};

class Tree {
    Node *root;

    void clear(Node *node) {
        if (!node) {
            return;
        }

        clear(node->left);
        clear(node->right);

        delete node;
    }

public:
    explicit Tree(Node *root) : root(root) {}

    Node *getRoot() {
        return root;
    }

    ~Tree() {
        clear(root);
    }

};

list<list<char>> bfs(Node *u) {
    list<list<char>> res;
    list<char> line;

    list<Node *> q;
    q.push_back(u);

    while (!q.empty()) {

        int sz = (int) q.size();

        while (sz--) {
            Node *curr = q.front();
            q.pop_front();
            if (curr) {
                line.push_back(curr->text);
                q.push_back(curr->left);
                q.push_back(curr->right);
            } else {
                line.push_back(' ');
            }
        }

        res.emplace_back(line);
        line.clear();
    }

    return res;
}

int main() {
    Node *n1 = new Node('!'), *n2 = new Node('s'), *n3 = new Node('m'), *n4 = new Node('e'),
            *n5 = new Node('l'), *n6 = new Node('b'), *n7 = new Node('o'), *n8 = new Node('r'),
            *n9 = new Node('p'), *n10 = new Node('g', nullptr, n1), *n11 = new Node('n', n2),
            *n12 = new Node('i'), *n13 = new Node('v'), *n14 = new Node('l', n4, n3),
            *n15 = new Node('o', n6, n5), *n16 = new Node('s', n8, n7),
            *n17 = new Node('t', nullptr, n9), *n18 = new Node('a', n11, n10),
            *n19 = new Node('d', n13, n12), *n20 = new Node('o', n15, n14),
            *n21 = new Node('o', nullptr, n16), *n22 = new Node('g', n18, n17),
            *n23 = new Node('m', n20, n19), *n24 = new Node('a', n22, n21),
            *n25 = new Node('I', n24, n23);

    Tree *T = new Tree(n25);

    list<list<char>> res = bfs(T->getRoot());

    for (const list<char> &l: res) {
        for (const char c: l) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}