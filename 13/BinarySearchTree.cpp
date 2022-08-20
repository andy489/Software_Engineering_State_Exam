#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node *left, *right;

    explicit Node(T data, Node *l = nullptr, Node *r = nullptr) : data(data), left(l), right(r) {};
};

template<typename T>
class BST {
    Node<T> *r;
    int size{};

    Node<T> *copy(Node<T> *o) {
        if (o) {
            return new Node<T>(o->data, copy(o->left), copy(o->right));
        }

        return nullptr;
    }

    void clear(Node<T> *n) {
        if (!n) {
            return;
        }

        clear(n->left);
        clear(n->right);

        delete n;
    }

    Node<T> *get_max(Node<T> *n) {
        while (n && n->right) {
            n = n->right;
        }

        return n;
    }

    void insert_util(Node<T> *&n, T key) {
        if (!n) {
            return void(n = new Node<T>(key));
        }

        insert_util(n->data < key ? n->right : n->left, key);
    }

    bool erase_util(Node<T> *&n, const T key) {
        if (!n) {
            return false;
        } else if (n->data < key) {
            return erase_util(n->right, key);
        } else if (key < n->data) {
            return erase_util(n->left, key);
        } else {
            if (!n->left) {
                n = n->right;
            } else if (!n->right) {
                n = n->left;
            } else {
                Node<T> *toDel = get_max(n->left);
                n->data = toDel->data;
                erase_util(n->left, toDel->data);
            }

            return true;
        }
    }

    const Node<T> *find_util(Node<T> *n, const T &key) const {
        if (!n) {
            return nullptr;
        }

        if (n->data == key) {
            return n;
        }

        return n->data < key ? find_util(n->right, key) : find_util(n->left, key);
    }

    static void inorder(Node<T> *n, ostream &os) {
        if (!n) {
            return;
        }

        inorder(n->left, os);
        os << n->data << ", ";
        inorder(n->right, os);
    }

public:
    BST() : r(nullptr) {}

    BST(const BST &o) : r(copy(o.r)), size(o.size){}

    BST &operator=(const BST &o) {
        clear(r);

        if (&o != this) {
            copy(o.r);
        }
        size = o.size;
        return *this;
    }

    ~BST() {
        clear(r);
    }

    int get_size() {
        return size;
    }

    void insert(T key) {
        insert_util(r, key);
        size++;
    }

    bool erase(const T key) {
        bool res = erase_util(r, key);

        if (res) {
            size--;
        }

        return res;
    }

    const Node<T> *find(const T &key) const {
        return find_util(r, key);
    }

    friend ostream &operator<<(ostream &os, const BST &t) {
        inorder(t.r, os);
        os << "\b\b" << endl;
        return os;
    }
};

int main() {
    BST<int> *t = new BST<int>();

    int toInsert[]{10, 6, 15, 15, 8, 2, 13, 18, 14, 9};
    const int size1 = sizeof toInsert / sizeof(int);

    for (int i: toInsert) {
        t->insert(i);
    }

    assert(t->get_size() == size1);

    cout << *t;

    BST<int> *t_copy1 = new BST<int>(*t);
    t_copy1->insert(7);

    int toErase[]{9, 8, 6, 15, 15};
    const int size2 = sizeof toErase / sizeof(int);
    for (int e: toErase) {
        assert(t_copy1->erase(e) == true);
    }

    cout << *t_copy1;

    assert(t_copy1->get_size() == size1 - size2 + 1);

    for (int e: toErase) {
        assert(t_copy1->erase(e) == false);
    }

    cout << *t_copy1;

    const Node<int> *found = t->find(6);

    assert(found->left->data == 2);
    assert(found->right->data == 8);

    found = t->find(11);

    assert(found == nullptr);

    BST<int> *t_copy2 = new BST<int>();
    *t_copy2 = *t_copy1;

    cout << *t_copy2;
    assert(t_copy2->get_size() == t_copy1->get_size());

    return 0;
}