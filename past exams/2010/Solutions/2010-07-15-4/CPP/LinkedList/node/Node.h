template<typename T>
class Node {
    T data;
    Node<T>* next;
public:
    Node(T data, Node<T> *next) {
        this->data = data;
        this->next = next;
    }

    T get_data() {
        return data;
    }

    Node<T> *get_next() {
        return next;
    }

    void set_next(Node<T>* n) {
        next = n;
    }
};