import node.Node;
import path.Path;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class CommonBranches {

    private static void findBranches(Node curr, Long val, String word, List<Path> branches) {
        if (curr.getChildren().isEmpty()) {
            branches.add(Path.of(val, word));
            return;
        }

        for (Node child : curr.getChildren()) {
            findBranches(child, val + child.getValue(), word + child.getLabel(), branches);
        }
    }

    public static void commonBranches(Node u, Node v, Long k) {
        List<Path> uBranches = new ArrayList<>();
        List<Path> vBranches = new ArrayList<>();

        findBranches(u, 0L, "", uBranches);
        findBranches(v, 0L, "", vBranches);

        for (int i = 0; i < uBranches.size(); i++) {
            for (int j = 0; j < vBranches.size(); j++) {
                if (uBranches.get(i).cost() + vBranches.get(i).cost() == k &&
                        Objects.equals(uBranches.get(i).word(), vBranches.get(i).word())) {
                    System.out.println(uBranches.get(i).word());
                }
            }
        }
    }

    public static void main(String... args) {
        Node root = new Node(-1L, ' ');

        Node n1 = new Node(1L, 'a');
        Node n2 = new Node(2L, 'a');

        Node nn1 = new Node(2L, 'b');
        Node nn2 = new Node(1L, 'b');

        Node nnn1 = new Node(3L, 'c');
        Node nnn2 = new Node(3L, 'c');

        nn1.addChild(nnn1);
        nn2.addChild(nnn2);

        n1.addChild(nn1);
        n2.addChild(nn2);

        root.addChild(n1);
        root.addChild(n2);

        commonBranches(n1, n2, 9L);
    }
}
