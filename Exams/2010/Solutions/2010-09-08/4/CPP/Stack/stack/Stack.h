#include "../node/Node.h"
#include "../exception/EmptyStackException.h"
#include <stdexcept>

template<typename T>
class Stack {
    Node<T> *head;

    int size;
public:
    Stack() {
        head = nullptr;
        size = 0;
    }

    Stack(Stack<T> &other) {
        head = other;
        size = other.get_size();
    }

    Node<T> *get_head() {
        return head;
    }

    int get_size() const {
        return size;
    }

    bool is_empty() const {
        return size == 0;
    }

    void push(T data) {
        if (!size) {
            head = new Node<T>(data);
        } else {
            Node<T> *temp = head;
            head = new Node<T>(data, temp);
        }

        ++size;
    }

    void pop() {
        if (size == 0) {
            return;
        }
        Node<T> *temp = head;
        head = head->get_next();

        delete temp;
        --size;
    }

    T peek() const {
        if (is_empty()) {
            throw EmptyStackException();
        }

        return head->get_data();
    }

    void clear() {
        while (!is_empty()) {
            pop();
        }
    }

    ~Stack() {
        clear();
    }
};
