template<typename T>
class Node {
    T data;
    Node<T> *next;
public:
    Node() {
        this->data = T();
        this->next = nullptr;
    }

    Node(T data, Node<T> *next) {
        this->data = data;
        this->next = next;
    }

    explicit Node(T data) {
        this->data = data;
        this->next = nullptr;
    }

    T get_data() const {
        return data;
    }

    void set_data(T new_data) {
        this->data = new_data;
    }

    Node<T> *get_next() const {
        return next;
    }

    void set_next(Node<T> *n) {
        next = n;
    }

};