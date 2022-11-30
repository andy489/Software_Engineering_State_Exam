#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

struct Node {
    char c{};
    Node *children[3]{};

    explicit Node(char c) : c(c) {}
};

string readLast(Node *root) {
    if (root == nullptr) return "";

    queue<Node *> nodes;
    nodes.push(root);
    string levelString;

    while (!nodes.empty()) {
        int lvl_size = (int) nodes.size();
        levelString = "";

        for (int i = 0; i < lvl_size; ++i) {
            Node *current = nodes.front();
            nodes.pop();

            levelString += current->c;

            for (Node *&child: current->children) {
                if (child) nodes.push(child);
            }
        }
    }

    return levelString;
}

string serializeTree(Node *n) {
    if (n == nullptr) return "";

    string segment = "(";
    segment.push_back(n->c);
    segment.push_back(' ');

    for (Node *&child: n->children) {
        segment += (child ? serializeTree(child) : "* ");
    }

    segment += ") ";

    return segment;
}

void saveToFile(const string &to_save, const string &path) {
    ofstream file_stream(path,  std::ios_base::trunc);

    if (file_stream.is_open()) {
        file_stream << to_save;
        file_stream.close();
    }
}

void serialize(Node *root, const string &path) {
    saveToFile(serializeTree(root), path);
}

int main() {
    Node *root = new Node('b');
    Node *l1 = new Node('x');
    Node *m1 = new Node('y');
    root->children[0] = l1;
    root->children[1] = m1;

    Node *l2 = new Node('p');
    Node *m2 = new Node('q');
    Node *r2 = new Node('r');
    l1->children[0] = l2;
    l1->children[1] = m2;
    l1->children[2] = r2;

    Node *l3 = new Node('c');
    Node *r3 = new Node('a');
    r2->children[0] = l3;
    r2->children[2] = r3;

    Node *r4 = new Node('s');
    m1->children[2] = r4;

    Node *r5 = new Node('t');
    r4->children[1] = r5;

    cout << readLast(root) << endl;
    serialize(root, "file.txt");

    return 0;
}
