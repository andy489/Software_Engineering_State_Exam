import list.MyLinkedList;
import node.Node;

import java.lang.reflect.Array;

public class LinkedListOfLinkedLists {

    private static Node<Integer>[] extractSorted(MyLinkedList<MyLinkedList<Integer>> ll) {
        MyLinkedList<MyLinkedList<Integer>> onlySorted = new MyLinkedList<>();

        Node<MyLinkedList<Integer>> traversal = ll.getHead();

        while (traversal != null) {
            if (traversal.getData().checkSorted()) {
                onlySorted.addAtTail(traversal.getData());
            }

            traversal = traversal.getNext();
        }

        @SuppressWarnings("unchecked")
        Node<Integer>[] arr = (Node<Integer>[]) Array.newInstance(Node.class, onlySorted.size());

        traversal = onlySorted.getHead();
        int i = 0;
        while (traversal != null) {
            arr[i++] = traversal.getData().getHead();
            traversal = traversal.getNext();
        }

        return arr;
    }

    private static Node<Integer> mergeKLists(Node<Integer>[] heads) {
        // Base condition
        if (heads == null || heads.length == 0) {
            return null;
        }

        return mergeKLists(heads, 0, heads.length - 1);
    }

    private static Node<Integer> mergeKLists(Node<Integer>[] lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        // Mid of list of lists
        int mid = start + (end - start) / 2;
        // Recursive call for left sublist
        Node<Integer> left = mergeKLists(lists, start, mid);
        // Recursive call for right sublist
        Node<Integer> right = mergeKLists(lists, mid + 1, end);
        // Merge the left and right sublist
        return merge(left, right);
    }

    private static Node<Integer> merge(Node<Integer> left, Node<Integer> right) {
        // Create a dummy node
        Node<Integer> head = Node.of(-1);
        // Temp node
        Node<Integer> temp = head;
        // Loop until any of the list becomes null
        while (left != null && right != null) {
            // Choose the value from the left and right which is smaller
            if (left.getData() < right.getData()) {
                temp.setNext(left);
                left = left.getNext();
            } else {
                temp.setNext(right);
                right = right.getNext();
            }
            temp = temp.getNext();
        }
        // Take all nodes from left list if remaining
        while (left != null) {
            temp.setNext(left);
            left = left.getNext();
            temp = temp.getNext();
        }
        // Take all nodes from right list if remaining
        while (right != null) {
            temp.setNext(right);
            right = right.getNext();
            temp = temp.getNext();
        }
        return head.getNext();
    }


    public static void main(String... args) {
        MyLinkedList<Integer> ll1 = new MyLinkedList<>(2, 4, 7, 8, 9);
        MyLinkedList<Integer> ll2 = new MyLinkedList<>(1, 3, 5, 6, 10);
        MyLinkedList<Integer> ll3 = new MyLinkedList<>(1, 0, 1, 1, 0, 1);

        MyLinkedList<MyLinkedList<Integer>> ll = new MyLinkedList<>(ll1, ll2, ll3);

        Node<Integer>[] headNodes = extractSorted(ll);

        MyLinkedList<Integer> result = new MyLinkedList<>(mergeKLists(headNodes));

        System.out.println(result);


    }
}
