public class LinkedListSort {
    public Node head = null;

    static class Node {
        public int data;
        public Node next;

        public Node(int val) {
            this.data = val;
        }
    }

    Node mergeSorted(Node a, Node b) {
        Node result;

        if (a == null) return b;
        if (b == null) return a;

        if (a.data <= b.data) {
            result = a;
            result.next = mergeSorted(a.next, b);
        } else {
            result = b;
            result.next = mergeSorted(a, b.next);
        }

        return result;
    }

    Node mergeSort(Node h) {
        if (h == null || h.next == null) return h;

        Node middle = getMiddle(h);
        Node nextOfMiddle = middle.next;

        middle.next = null;

        Node left = mergeSort(h);
        Node right = mergeSort(nextOfMiddle);

        return mergeSorted(left, right);
    }

    public static Node getMiddle(Node head) {
        if (head == null) return null;

        Node slow = head, fast = head;

        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    void add(int data) {
        Node toAdd = new Node(data);
        toAdd.next = head;
        head = toAdd;
    }

    void printList(Node headRef) {
        while (headRef != null) {
            System.out.print(headRef.data);
            if (headRef.next != null) {
                System.out.print(" -> ");
            }
            headRef = headRef.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {

        LinkedListSort ll = new LinkedListSort();

        int[] data = {23, 8, 5, 1, 6, -4, 12, 3, 5, 0, 22};

        for (int d : data) ll.add(d);

        ll.printList(ll.head);
        ll.head = ll.mergeSort(ll.head);
        ll.printList(ll.head);
    }
}
