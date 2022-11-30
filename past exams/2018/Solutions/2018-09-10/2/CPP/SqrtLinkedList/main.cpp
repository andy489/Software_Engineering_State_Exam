#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int MAX_NUMS = 1e4;

struct Node {
    int data;
    Node *next, *nextK;

    explicit Node(int data) : data(data), next(nullptr), nextK(nullptr) {}
};

string readFromFile(const string &path) {
    string nums;

    ifstream fileStream(path);

    if (fileStream.is_open()) {
        getline(fileStream, nums);
    }

    fileStream.close();

    return nums;
}

int addDigit(char digit, int num) {
    return (num * 10) + (digit - '0');
}

int *extractValues(const string &nums) {
    int *numbers = new int[MAX_NUMS];

    int i = 1, currNum = 0;
    for (char c: nums) {
        if (c == ' ') {
            numbers[i++] = currNum;
            currNum = 0;
            continue;
        }

        currNum = addDigit(c, currNum);
    }

    numbers[i] = currNum;
    numbers[0] = i; // storing the size of the array numbers

    return numbers;
}

Node *createList(int *nums) {
    int SIZE = nums[0];
    int k = ceil(sqrt(SIZE));

    Node *head = new Node(nums[1]);
    Node *traversal = head;
    Node *traversalK = head;

    for (int i = 2; i <= SIZE; ++i) {
        Node *curr = new Node(nums[i]);
        traversal->next = curr;
        traversal = curr;

        if (i % k == 1) {
            traversalK->nextK = traversal;
            traversalK = traversal;
        }
    }

    return head;
}

Node *readList(const string &path) {
    return createList(extractValues(readFromFile(path)));
}

void printList(Node *head) {
    Node *traversal = head;
    cout << "Next link:" << endl;
    while (traversal) {
        cout << traversal->data << ' ';
        traversal = traversal->next;
    }

    cout << endl << "Square step link:" << endl;
    traversal = head;
    while (traversal) {
        cout << traversal->data << ' ';
        traversal = traversal->nextK;
    }
    cout << endl << endl;
}

bool member(Node *head, int target) {
    Node *traversal = head;

    while (traversal) {
        if (traversal->data == target) {
            return true;
        }

        if (traversal->nextK && traversal->nextK->data < target) {
            traversal = traversal->nextK;
        } else {
            traversal = traversal->next;
        }
    }

    return false;
}

int main() {
    Node *head = readList("list.txt");

    // printList(head);

    const int SEARCHED[] = {0, 6, 10};

    for (int i: SEARCHED) {
        cout << i << ' ' << (member(head, i) ? "FOUND" : "NOT FOUND") << endl;
    }

    return 0;
}
