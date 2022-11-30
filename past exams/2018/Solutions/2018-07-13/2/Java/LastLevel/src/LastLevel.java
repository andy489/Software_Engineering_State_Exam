import node.Node;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

public class LastLevel {
    public static String readLast(Node root) {
        StringBuilder sb = new StringBuilder();
        if (root == null) {
            return sb.toString();
        }

        Queue<Node> nodes = new LinkedList<>();
        nodes.add(root);

        while (!nodes.isEmpty()) {
            int lvl_size = nodes.size();
            sb.setLength(0);

            for (int i = 0; i < lvl_size; ++i) {
                Node curr = nodes.poll();
                if (curr == null) {
                    throw new IllegalStateException("The must not be null nodes in queue for BFS");
                }

                sb.append(curr.getChar());

                for (Node child : curr.getChildren()) {
                    if (child != null) {
                        nodes.add(child);
                    }
                }
            }
        }
        return sb.toString();
    }

    private static String serialize(Node n) {
        StringBuilder sb = new StringBuilder();

        if (n == null) return sb.toString();

        sb.append('(').append(n.getChar()).append(' ');

        for (Node child : n.getChildren()) {
            sb.append(child != null ? serialize(child) : "* ");
        }

        sb.append(") ");
        return sb.toString();
    }

    private static void saveToFile(final String toSave, final String fileName) throws FileNotFoundException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            writer.write(toSave);
        } catch (FileNotFoundException e) {
            throw e;
        } catch (IOException e) {
            System.err.print("Something went wrong");
        }
    }

    public static void serialize(Node n, final String fileName) throws FileNotFoundException {
        saveToFile(serialize(n), fileName);
    }

    public static void main(String... args) throws FileNotFoundException {
        Node root = new Node('b');
        Node l1 = new Node('x');
        Node m1 = new Node('y');
        root.setChild(0, l1);
        root.setChild(1, m1);

        Node l2 = new Node('p');
        Node m2 = new Node('q');
        Node r2 = new Node('r');
        l1.setChild(0, l2);
        l1.setChild(1, m2);
        l1.setChild(2, r2);

        Node l3 = new Node('c');
        Node r3 = new Node('a');
        r2.setChild(0, l3);
        r2.setChild(2, r3);

        Node r4 = new Node('s');
        m1.setChild(2, r4);

        Node r5 = new Node('t');
        r4.setChild(1, r5);

        System.out.println(readLast(root));
        serialize(root, "file.txt");
    }
}
