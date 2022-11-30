#include <iostream>

struct Node {
    int data{};
    Node *next{};

    Node() = default;

    explicit Node(int data) : data(data), next(nullptr) {}

    [[maybe_unused]] Node(int data, Node *next) : data(data), next(next) {}
};

class LinkedList {
    Node *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void addAtHead(int data) {
        if (!head) {
            head = new Node(data);
        } else {
            head = new Node(data, head);
        }

        ++size;
    }

    [[nodiscard]] int getSize() const {
        return size;
    }

    Node **getHead() {
        return &head;
    }

    void print() {
        Node *traversal = head;

        while (traversal) {
            printf("%d", traversal->data);
            if (traversal->next) {
                printf(" -> ");
            }
            traversal = traversal->next;
        }

        printf("\n");
    }

    ~LinkedList() {
        Node *traversal = head;

        while (traversal) {
            Node *next = traversal->next;
            delete traversal;
            traversal = next;
        }

        head = nullptr;
        size = 0;
    }
};

Node *mergeSorted(Node *a, Node *b) {
    Node *result;

    if (!a) return b;
    else if (!b) return a;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeSorted(a->next, b);
    } else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }

    return result;
}

void split(Node *head, Node **frontRef, Node **backRef) {
    Node *fast, *slow;
    slow = head;
    fast = head->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = head;
    *backRef = slow->next;
    slow->next = nullptr;
}

void mergeSort(Node **headRef) {
    Node *head = *headRef;
    Node *a, *b;

    if (!head || !head->next) return;

    split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = mergeSorted(a, b);
}

int main() {
    LinkedList ll = LinkedList();

    int data[] = {23, 8, 5, 1, 6, -4, 12, 3, 5, 0, 22};
    for (int d: data) ll.addAtHead(d);

    ll.print();
    mergeSort(ll.getHead());
    ll.print();

    return 0;
}
