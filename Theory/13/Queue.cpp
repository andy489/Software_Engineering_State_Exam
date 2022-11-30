#include <iostream>

using namespace std;

struct EmptyQueueException : public exception {
    const char *what() const noexcept override {
        return "Queue is empty!";
    }
};

template<typename T>
struct Node {
    T data;
    Node<T> *next;

    Node(T data, Node<T> *next = nullptr) : data(data), next(next) {}
};

template<typename T>
class Queue {
    Node<T> *head, *tail;
    int size{};

    void clear() {
        while (!is_empty()) {
            dequeue();
        }
    }

    void copy(const Queue &o) {
        Node<T> *traversal = o.head;

        while (traversal) {
            enqueue(traversal->data);
            traversal = traversal->next;
        }
    }

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    Queue(const Queue &o) {
        copy(o);
    }

    Queue &operator=(const Queue &o) {
        clear();

        if (&o != this) {
            copy(o);
        }

        return *this;
    }

    ~Queue() {
        clear();
    };

    int get_size() {
        return size;
    }

    bool is_empty() {
        return head == nullptr;
    }

    void enqueue(T data) {
        Node<T> *n = new Node<T>(data);

        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }

        ++size;
    }

    bool dequeue() {
        if (is_empty()) {
            return false;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T> *toDel = head;
            head = head->next;
            delete toDel;
        }

        --size;
        return true;
    }

    T front() {
        if (is_empty()) {
            throw EmptyQueueException();
        }

        return head->data;
    }

};

int main() {
    Queue<int> *Q = new Queue<int>();

    int toEnqueue[]{1, 2, 3, 4};
    const int size = sizeof toEnqueue / sizeof(int);

    for (int e: toEnqueue) {
        Q->enqueue(e);
    }

    Queue<int> *Q_copy1 = new Queue<int>(*Q);    // copy constructor
    Queue<int> *Q_copy2 = new Queue<int>();
    *Q_copy2 = *Q_copy1;                        // assignment operator

    for (int i = size; i >= 1; --i) {
        assert(Q->front() == size - i + 1);
        assert(Q->get_size() == i);
        assert(Q->dequeue());
    }

    int i = 0;
    while (!Q_copy1->is_empty()) {
        assert(Q_copy1->front() == toEnqueue[i++]);
        Q_copy1->dequeue();
    }

    i = 0;
    while (!Q_copy2->is_empty()) {
        assert(Q_copy2->front() == toEnqueue[i++]);
        Q_copy2->dequeue();
    }

    assert(Q_copy1->is_empty() && Q_copy2->is_empty());

    return 0;
}

