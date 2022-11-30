#include "./LinkedList/LinkedList.h"

int main() {
    Linked_List<int> *ll = new Linked_List<int>();

    for (int i = 0; i < 6; i++) {
        ll->add_at_tail(i);
        for (int j = 0; j < i; j++) {
            ll->add_at_tail(i + i % 3);
        }
    }

    std::cout << *ll;
    std::cout << ll->countConsecutiveEqualElements() << std::endl;

    return 0;
}
