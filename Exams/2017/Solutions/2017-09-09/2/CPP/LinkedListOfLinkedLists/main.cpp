#include <iostream>

using namespace std;

template<typename T>
struct Node {
    T data;
    Node *next;

    Node() = default;

    explicit Node(const T &data) : data(data), next(nullptr) {}
};

template<typename T>
class LinkedList {
    Node<T> *head, *tail;
    int size;

public:
    LinkedList<T>() : head(nullptr), tail(nullptr), size(0) {}

    LinkedList<T>(T *arr, int N) : size(0) {
        for (int i = 0; i < N; ++i) {
            this->addAtTail(arr[i]);
        }
    }

    Node<T> *getHead() {
        return head;
    }

    void addAtTail(T data) {
        Node<T> *toAdd = new Node<T>(data);

        if (head == nullptr) {
            head = tail = toAdd;
        } else {
            tail->next = toAdd;
            tail = toAdd;
        }

        ++size;
    }

    friend ostream &operator<<(ostream &os, const LinkedList<T> &list) {
        Node<T> *traversal = list.head;

        if (traversal == nullptr) {
            os << "empty list";
        } else {
            while (traversal != nullptr) {
                os << traversal->data << " -> ";
                traversal = traversal->next;
            }
            os << "\b\b\b\b";
        }

        os << endl;
        return os;
    }

    int getSize() {
        return size;
    }

    Node<T> *begin() {
        return head;
    }

    Node<T> *end() {
        return tail->next;
    }

    bool checkSorted() {
        Node<T> *traversal = head;

        if (size < 2) {
            return true;
        }

        while (traversal && traversal->next) {
            if (traversal->data > traversal->next->data) {
                return false;
            }
            traversal = traversal->next;
        }

        return true;
    }
};

Node<int> *merge(Node<int> *left, Node<int> *right) {
    // Create a dummy node
    Node<int> *head = new Node<int>(-1);
    // Temp node
    Node<int> *temp = head;
    // Loop until any of the list becomes null
    while (left != nullptr && right != nullptr) {
        // Choose the value from the left and right which is smaller
        if (left->data < right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    // Take all nodes from left list if remaining
    while (left != nullptr) {
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }
    // Take all nodes from right list if remaining
    while (right != nullptr) {
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }
    return head->next;
}

Node<int> *mergeKLists(Node<int> **lists, int start, int end) {
    if (start == end) {
        return lists[start];
    }
    // Mid of list of lists
    int mid = start + (end - start) / 2;
    // Recursive call for left sublist
    Node<int> *left = mergeKLists(lists, start, mid);
    // Recursive call for right sublist
    Node<int> *right = mergeKLists(lists, mid + 1, end);
    // Merge the left and right sublist
    return merge(left, right);
}

Node<int> *mergeSortedLists(LinkedList<LinkedList<int>> &lists) {
    int i = 0;
    LinkedList<int> *onlySorted = new LinkedList<int>[lists.getSize()];

    for (Node<LinkedList<int>> *curr = lists.begin(); curr != lists.end(); curr = curr->next) {
        LinkedList<int> currList = curr->data;

        if (currList.getSize() > 0 && currList.checkSorted()) {
            onlySorted[i++] = currList;
        }
    }

    int SIZE = onlySorted->getSize();
    if (!SIZE) {
        return nullptr;
    }

    Node<int> **heads = new Node<int> *[SIZE];
    for (int j = 0; j < SIZE; ++j) {
        heads[j] = onlySorted[j].getHead();
    }

    return mergeKLists(heads, 0, SIZE - 1);
}

template<typename T>
void display(Node<T> *start) {
    while (start != nullptr) {
        cout << start->data;
        if (start->next) {
            cout << " -> ";
        }
        start = start->next;
    }
    cout << endl;
}

int main() {
    LinkedList<LinkedList<int>> *listOfLists = new LinkedList<LinkedList<int>>();

    listOfLists->addAtTail(*(new LinkedList<int>(new int[]{0, 4, 8,}, 3)));
    listOfLists->addAtTail(*(new LinkedList<int>(new int[]{2, 3, 9,}, 3)));
    listOfLists->addAtTail(*(new LinkedList<int>(new int[]{5, 3, 6,}, 3)));
    listOfLists->addAtTail(*(new LinkedList<int>(new int[]{1, 2, 3,}, 3)));

    Node<int> *resultHead = mergeSortedLists(*listOfLists);

    display(resultHead);

    return 0;
}
