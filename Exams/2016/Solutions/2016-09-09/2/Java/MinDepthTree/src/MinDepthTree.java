import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class MinDepthTree {

    private record Node(int data, ArrayList<Node> children) {
        public static Node of(int data) {
            return new Node(data, new ArrayList<>());
        }
    }

    public static Node constructTreeRec(final int[] A, final int K, int curr) {
        Node current = Node.of(A[curr]);
        final int N = A.length;

        for (int i = 0; i < K && curr * K + i + 1 < N; i++) {
            Node child = constructTreeRec(A, K, curr * K + i + 1);

            current.children.add(child);
        }

        return current;
    }

    public static Node constructTree(final int[] A, final int K) {
        return constructTreeRec(A, K, 0);
    }

    public static int getDepth(Node curr, int currDepth) {
        int maxDepth = currDepth;

        for (final Node child : curr.children) {
            maxDepth = Math.max(maxDepth, getDepth(child, currDepth + 1));
        }

        return maxDepth;
    }

    public static void displayTreeLvlOrderBfs(Node n) {
        Queue<Node> Q = new LinkedList<>();
        Q.add(n);

        int currLvl = 1;

        while (!Q.isEmpty()) {
            System.out.printf("%d: ", currLvl);
            int sz = Q.size();

            while (sz-- > 0) {
                Node curr = Q.poll();

                assert curr != null;
                Q.addAll(curr.children());

                System.out.printf("%d%s", curr.data, sz > 0 ? ", " : "");
            }

            currLvl++;
            System.out.println();
        }
    }

    public static void main(String... args) {
        final int[] A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        final int K = 3;

        Node root = constructTree(A, K);

        // displayTreeLvlOrderBfs(root);

        int initDepth = 1;
        System.out.printf("%d%n", getDepth(root, initDepth));
    }
}
