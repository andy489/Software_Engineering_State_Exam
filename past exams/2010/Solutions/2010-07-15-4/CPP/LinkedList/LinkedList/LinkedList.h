#include "../node/Node.h"

#include <iostream>

template<typename T>
class Linked_List {
    Node<T> *head;
    Node<T> *tail;

    int size;
public:
    Linked_List() {
        head = tail = nullptr;
    }

    int get_size() {
        return size;
    }

    Node<T> *get_head() {
        return head;
    }

    Node<T> *get_tail() {
        return tail;
    }

    void add_at_tail(T data) {
        Node<T> *n = new Node<T>(data, nullptr);

        if (!head) {
            head = tail = n;
        } else {
            tail->set_next(n);
            tail = n;
        }

        size++;
    }

    int countConsecutiveEqualElements() {
        Node<T> *traversal = head;

        int cnt = 0;
        bool flagFirstMatch = false;

        while (traversal && traversal->get_next()) {
            Node<T> *prev = traversal;
            traversal = traversal->get_next();

            if (prev->get_data() == traversal->get_data()) {
                if (!flagFirstMatch) {
                    cnt++;
                    flagFirstMatch = true;
                }
                cnt++;
            } else {
                flagFirstMatch = false;
            }
        }

        if (cnt == 0 && size != 0) {
            return 1;
        }

        return cnt;
    }

    friend std::ostream &operator<<(std::ostream &out, const Linked_List<T> &ll) {
        if (ll.size == 0) {
            out << "Empty list" << std::endl;
            return out;
        }

        Node<T> *traversal = ll.head;

        while (traversal != nullptr) {
            out << traversal->get_data() << "->";
            traversal = traversal->get_next();
        }

        out << '\b';

        out << "|" << std::endl;

        return out;
    }
};