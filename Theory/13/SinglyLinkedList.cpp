#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node *next;

    Node(T data, Node *next = nullptr) : data(data), next(next) {}
};

template<typename T>
class SinglyLinkedList {
    Node<T> *head, *tail;
    int size{};

    void copy(const SinglyLinkedList &o) {
        Node<T> *traversal = o.head;

        while (traversal) {
            this->add_at_tail(traversal->data);
            traversal = traversal->next;
        }
    }

    void clear() {
        while (head != nullptr) {
            erase_at_head();
        }
    }

    Node<T> *reverse(Node<T> *n) {
        if (!n || !n->next) {
            return n;
        }

        Node<T> *rest = reverse(n->next);

        n->next->next = n;
        n->next = nullptr;

        return rest;
    }

public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size() {}

    SinglyLinkedList(const SinglyLinkedList &o) {
        copy(o);
    }

    SinglyLinkedList &operator=(const SinglyLinkedList &o) {
        clear();

        if (&o != this) {
            copy(o);
        }

        return *this;
    }

    ~SinglyLinkedList() {
        clear();
    }

    void add_at_head(T data) {
        Node<T> *n = new Node<T>(data);

        if (head == nullptr) {
            head = tail = n;
        } else {
            n->next = head;
            head = n;
        }

        ++size;
    }

    void add_at_tail(T data) {
        Node<T> *n = new Node<T>(data);

        if (head == nullptr) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }

        ++size;
    }

    bool erase_at_head() {
        if (head == nullptr) {
            return false;
        } else if (head == tail) {
            delete head;
            head = tail = nullptr;
            --size;
            return true;
        } else {
            Node<T> *n = head;
            head = head->next;
            delete n;
            --size;
            return true;
        }
    }

    void add_at_pos(T data, int pos) {
        Node<T> *n = new Node<T>(data);

        if (pos <= 1) {
            return add_at_head(data);
        } else if (pos > size) {
            add_at_tail(data);
        } else {
            Node<T> *traversal = head;

            for (int i = 0; i < pos - 2; ++i) {
                if (!traversal) {
                    return add_at_tail(data);
                }

                traversal = traversal->next;
            }

            n->next = traversal->next;
            traversal->next = n;
            ++size;
        }
    }

    void erase_at_pos(int pos) {
        if (size < 1) {
            return;
        } else if (pos <= 1) {
            erase_at_head();
        } else if (pos > size) {
            Node<T> *traversal = head;
            for (int i = 0; i < size - 2; ++i) {
                traversal = traversal->next;
            }
            Node<T> *toDel = traversal->next;
            traversal->next = nullptr;
            tail = traversal;
            --size;
            delete toDel;
        } else {
            Node<T> *traversal = head;

            for (int i = 0; i < pos - 2; ++i) {
                traversal = traversal->next;
            }

            Node<T> *toDel = traversal->next;
            traversal->next = toDel->next;
            delete toDel;
            --size;
        }
    }

    void reverse() {
        tail = head;
        Node<T> *rev = reverse(head);
        head = rev;
    }

    void merge(const SinglyLinkedList &o) {
        if (!o.head) {
            return;
        } else {
            SinglyLinkedList<T> *copy = new SinglyLinkedList(o);
            tail->next = copy->head;
            tail = copy->tail;
            size += copy->size;
        }
    }

    friend ostream &operator<<(ostream &os, const SinglyLinkedList &list) {
        Node<T> *traversal = list.head;

        if (traversal == nullptr) {
            os << "[empty list]" << endl;
            return os;
        } else {
            while (traversal != nullptr) {
                os << traversal->data << "->";
                traversal = traversal->next;
            }
            os << '\b' << '|' << endl;
            return os;
        }
    }
};


int main() {
    SinglyLinkedList<int> *l = new SinglyLinkedList<int>();

    int toAddAtHead[]{1, 2, 3, 4};
    for (int a: toAddAtHead) {
        l->add_at_head(a);
    }

    int toAddAtTail[]{2, 3, 4};
    for (int a: toAddAtTail) {
        l->add_at_tail(a);
    }

    assert(l->erase_at_head());

    int eraseAtPos[]{3, 3, 2, 100};
    for (int e: eraseAtPos) {
        l->erase_at_pos(e);
    }

    int posToAdd[]{1, 3, 5, 100};
    int elementToAdd[]{10, 11, 12, 13};

    const int SIZE = sizeof posToAdd / sizeof(int);
    for (int i = 0; i < SIZE; ++i) {
        l->add_at_pos(elementToAdd[i], posToAdd[i]);
    }

    SinglyLinkedList<int> *copy1 = new SinglyLinkedList<int>(*l); // copy constructor call
    SinglyLinkedList<int> *copy2 = new SinglyLinkedList<int>();
    *copy2 = *copy1; // assignment operator call

    copy2->add_at_pos(2, 2);
    cout << *copy1;
    cout << *copy2;

    copy2->reverse();
    copy2->merge(*copy2);
    copy2->merge(*copy1);

    cout << *copy2;

    return 0;
}
