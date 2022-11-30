#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

template<typename T>
struct Node {
    T data;
    vector<Node *> children;

    explicit Node(T data) : data(data) {}
};

template<typename T>
class Tree {
    Node<T> *root;
    int size{};

    void clear(Node<T> *n) {

        for (int i = 0; i < n->children.size(); i++) {
            clear(n->children[i]);
        }

        delete n;
    }

    static void dfs(Node<T> *n, ostream &os) {
        if (n) {
            os << n->data << ", ";
            if (n->children.empty()) {
                return;
            }

            const int SIZE = n->children.size();

            for (int i = 0; i < SIZE; ++i) {
                dfs(n->children[i], os);
            }
        }
    }

    static ostream &bfs(Node<T> *n, ostream &os) {
        queue<Node<T> *> Q;
        Q.push(n);

        int lvl = 0;
        while (!Q.empty()) {
            int curr_size = Q.size();
            if (lvl != 0) {
                os << endl;
            }
            os << "lvl-" << lvl << ": ";
            while (curr_size--) {
                Node<T> *curr_n = Q.front();
                Q.pop();

                os << curr_n->data << ", ";

                for (int i = 0; i < curr_n->children.size(); ++i) {
                    Q.push(curr_n->children[i]);
                }
            }
            lvl++;
        }
        os << "\b\b" << endl;
        return os;
    }

public:

    Tree() : root(nullptr) {}

    Tree(const Tree &o) : root(copy(o->getRoot())), size(o->getSize()) {}

    ~Tree() {
        clear(root);
        size = 0;
    }

    Node<T> *getRoot() {
        return root;
    }

    void buildTree(map<Node<T> *, Node<T> *> &childParentMap) {
        auto it = childParentMap.begin();
        auto end = childParentMap.end();

        while (it != end) {
            auto child = it->first;
            auto parent = it->second;
            it++;
            size++;

            if (parent == nullptr) {
                root = child;
                continue;
            }

            parent->children.push_back(child);
        }
    }

    friend ostream &operator<<(ostream &os, const Tree &t) {
        //dfs(t.root, os);
        // os << "\b\b" << endl;
        return bfs(t.root, os);
    }
};

int main() {
    map<Node<int> *, Node<int> *> childParentMap;

    vector<Node<int> *> nodes{
            new Node<int>(0),
            new Node<int>(1),
            new Node<int>(2),
            new Node<int>(3),
            new Node<int>(4),
            new Node<int>(5),
            new Node<int>(6),
            new Node<int>(7),
            new Node<int>(8),
            new Node<int>(9),
            new Node<int>(10),
            new Node<int>(11),
            new Node<int>(12),
    };

    /*
     *               3
     *            /  |  \
     *           2   4   10
     *          / \    / | \ \
     *         7   8  0  5  6 9
     *                 / | \
     *                1 11 12
     */

    childParentMap[nodes[0]] = nodes[10];
    childParentMap[nodes[1]] = nodes[0];
    childParentMap[nodes[2]] = nodes[3];
    childParentMap[nodes[3]] = nullptr;
    childParentMap[nodes[4]] = nodes[3];
    childParentMap[nodes[5]] = nodes[10];
    childParentMap[nodes[6]] = nodes[10];
    childParentMap[nodes[7]] = nodes[2];
    childParentMap[nodes[8]] = nodes[2];
    childParentMap[nodes[9]] = nodes[10];
    childParentMap[nodes[10]] = nodes[3];
    childParentMap[nodes[11]] = nodes[0];
    childParentMap[nodes[12]] = nodes[0];

    Tree<int> tree;
    tree.buildTree(childParentMap);

    cout << tree;

    return 0;
}