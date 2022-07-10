#include <iostream>

using namespace std;

struct EmptyStackException : public exception {
    const char *what() const noexcept override {
        return "Stack is empty!";
    }
};

template<typename T>
struct Node {
    T data;
    Node *next;

    Node(T data, Node<T> *next = nullptr) : data(data), next(next) {}
};

template<typename T>
class Stack {
    Node<T> *head;
    int size;

    void clear() {
        while (!is_empty()) {
            pop();
        }

        size = 0;
    }

    void copy(const Stack &o) {
        Node<T> *traversal = o.head;
        Stack *aux = new Stack();

        while (traversal) {
            aux->push(traversal->data);
            traversal = traversal->next;
        }

        while (!aux->is_empty()) {
            this->push(aux->top());
            aux->pop();
        }
    }

public:
    Stack() : head(nullptr), size(0) {}

    Stack(const Stack &o) {
        clear();
        copy(o);
    }

    Stack &operator=(const Stack &o) {
        clear();

        if (&o != this) {
            copy(o);
        }

        return *this;
    }

    ~Stack() {
        clear();
    }

    int get_size() {
        return size;
    }

    bool is_empty() {
        return head == nullptr;
    }

    void push(T data) {
        Node<T> *n = new Node<T>(data);

        if (!head) {
            head = n;
        } else {
            n->next = head;
            head = n;
        }

        ++size;
    }

    bool pop() {
        if (is_empty()) {
            return false;
        } else {
            Node<T> *n = head;
            head = head->next;

            delete n;
            --size;
            return true;
        }
    }

    T top() {
        if (is_empty()) {
            throw EmptyStackException();
        }

        return head->data;
    }
};


int main() {
    Stack<int> *S = new Stack<int>();

    int toPush[]{1, 2, 3, 4};
    const int size = sizeof toPush / sizeof(int);

    for (int i = 0; i < size; ++i) {
        assert(S->get_size() == i);
        S->push(toPush[i]);
        assert(S->top() == toPush[i]);
    }

    assert(S->get_size() == size);

    assert(S->pop() == true);
    assert(S->top() == toPush[2]);

    Stack<int> *C = new Stack<int>(*S); //copy constructor
    Stack<int> *A = new Stack<int>();   // assignment operator
    *A = *C;

    assert(A->get_size() == C->get_size() && C->get_size() == S->get_size());

    return 0;
}
