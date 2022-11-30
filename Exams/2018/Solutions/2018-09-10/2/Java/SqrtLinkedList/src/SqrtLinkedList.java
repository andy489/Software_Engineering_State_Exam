import node.Node;
import reader.Reader;

import java.nio.file.Path;

public class SqrtLinkedList {
    private static final String filePath = "./list.txt";

    private static Node createList(int[] numbers) {
        int SIZE = numbers.length;
        int K = (int) Math.ceil(Math.sqrt(SIZE));

        Node head = new Node(numbers[0]);
        Node traversal = head;
        Node traversalK = head;

        for (int i = 1; i < SIZE; i++) {
            Node curr = new Node(numbers[i]);
            traversal.setNext(curr);
            traversal = curr;

            if (i % K == 0) {
                traversalK.setNextK(traversal);
                traversalK = traversal;
            }
        }

        return head;
    }

    public static Node readList() {
        return createList(Reader.readFromFile(Path.of(filePath)));
    }

    public static void printList(Node head) {
        Node traversal = head;
        System.out.println("Next link:");
        while (traversal != null) {
            System.out.print(traversal);
            traversal = traversal.getNext();
        }

        System.out.println(System.lineSeparator() + "Square step link:");
        traversal = head;
        while (traversal != null) {
            System.out.print(traversal);

            traversal = traversal.getNextK();
        }
        System.out.println(System.lineSeparator());
    }

    public static boolean member(Node head, int target) {
        Node traversal = head;

        while (traversal != null) {
            if (traversal.getData() == target) {
                return true;
            }

            if (traversal.getNextK() != null && traversal.getNextK().getData() < target) {
                traversal = traversal.getNextK();
            } else {
                traversal = traversal.getNext();
            }
        }

        return false;
    }

    public static void main(String... args) {
        Node head = readList();

        // printList(head);

        int[] SEARCHED = {0, 6, 10};

        for (int i : SEARCHED) {
            System.out.printf("%d %s%n", i, member(head, i) ? "FOUND" : "NOT FOUND");
        }
    }
}
