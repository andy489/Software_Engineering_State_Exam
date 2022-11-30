#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    vector<Node *> children;

    explicit Node(int data) : data(data) {}
};

Node *construct_tree_recursive(const int K, const int *A, int curr, const int N) {
    Node *current = new Node{A[curr]};

    for (int i = 0; i < K && curr * K + i + 1 < N; i++) {
        Node *child = construct_tree_recursive(K, A, curr * K + i + 1, N);

        current->children.push_back(child);
    }

    return current;
}

Node *constructTree(const int K, const int *A, const int N) {
    return construct_tree_recursive(K, A, 0, N - 1);
}

int get_depth(Node *curr, int curr_depth) {
    int max_depth = curr_depth;

    for (Node *child: curr->children) {
        max_depth = max(max_depth, get_depth(child, curr_depth + 1));
    }
    
    return max_depth;
}

void display_tree_level_order_bfs(Node *root) {
    queue<Node *> Q;
    Q.push(root);

    int curr_lvl = 1;

    while (!Q.empty()) {
        cout << curr_lvl << ": ";
        int sz = (int) Q.size();

        while (sz--) {
            Node *curr = Q.front();
            Q.pop();
            for (Node *child: curr->children) {
                Q.push(child);
            }

            cout << curr->data << (sz ? ", " : "");
        }

        curr_lvl++;
        cout << endl;
    }
}

int main() {
    const int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int K = 3;
    const int N = sizeof A / sizeof(int);

    Node *root = constructTree(K, const_cast<int *>(A), N);

    // display_tree_level_order_bfs(root);

    int initial_depth = 1;
    cout << get_depth(root, initial_depth) << endl;

    return 0;
}
