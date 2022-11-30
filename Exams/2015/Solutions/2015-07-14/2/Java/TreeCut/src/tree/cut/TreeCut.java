package tree.cut;

import com.sun.source.tree.Tree;

import java.util.Collection;
import java.util.List;

public class TreeCut {
    private Node root;

    public TreeCut() {
        root = null;
    }

    public TreeCut(Node root) {
        this.root = root;
    }

    public void print() {
        System.out.print("DFS Tree: ");
        dfs(root);
        System.out.println();
    }

    public boolean member(int x) {
        return member(root, x);
    }

    public void filterOdd() {
        filterOdd(root);
    }

    private void dfs(Node n) {
        if (n != null) {
            for (Node child : n.children()) {
                dfs(child);
            }
            System.out.print(n);
        }
    }

    private boolean member(Node n, int x) {
        if (n == null) {
            return false;
        }
        if (n.data() == x) {
            return true;
        }

        boolean isMemberInChildren = false;

        for (Node child : n.children()) {
            isMemberInChildren = isMemberInChildren || member(child, x);
        }

        return isMemberInChildren;
    }

    private boolean filterOdd(Node n) {
        if (n == null) {
            return false;
        }

        if (n.data() % 2 == 1) {
            n = null;
            return true;
        }

        for (int i = 0; i < n.children().size(); ) {
            if (filterOdd(n.children().get(i))) {
                List<Node> nodes = n.children().subList(0, i);
                n.setChildren(nodes);
            } else {
                i++;
            }
        }

        return false;
    }

    public static void main(String... args) {
        Node root = Node.of(8);
        Node left = Node.of(2);
        Node right = Node.of(3);
        Node first = Node.of(4);
        Node second = Node.of(5);
        Node third = Node.of(6);

        right.children().add(first);
        right.children().add(second);
        right.children().add(third);

        root.children().add(left);
        root.children().add(right);

        TreeCut tree = new TreeCut(root);
        tree.print();

        int search1 = 1, search2 = 2;

        String fmt = "Member %d is %s present%n";
        System.out.printf(fmt, search1, tree.member(search1) ? "" : "NOT");
        System.out.printf(fmt, search2, tree.member(search2) ? "" : "NOT");

        tree.filterOdd();

        tree.print();
    }
}
