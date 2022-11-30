import node.Node;
import pair.Pair;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class TreeBranches {

    public static void findBranches(Node curr, int val, String word, List<Pair> branches) {
        if (curr.noChildren()) {
            branches.add(new Pair(val, word));
            return;
        }

        for (Node child : curr.getChildren()) {
            findBranches(child, val + child.getVal(), word + child.getSym(), branches);
        }
    }

    public static int sumVal(Node u, Node v) {
        int sum = 0;
        List<Pair> uBranches = new ArrayList<>();
        List<Pair> vBranches = new ArrayList<>();

        findBranches(u, 0, "", uBranches);
        findBranches(v, 0, "", vBranches);

        for (int i = 0; i < uBranches.size(); i++) {
            for (int j = 0; j < vBranches.size(); j++) {
                if (Objects.equals(uBranches.get(i).second(), vBranches.get(i).second())) {
                    sum += uBranches.get(i).first() + vBranches.get(i).first();
                }
            }
        }

        return sum;
    }

    public static void main(String... args) {
        Node root = new Node(-1, ' ');

        Node n1 = new Node(1, 'a');
        Node n2 = new Node(2, 'a');

        Node nn1 = new Node(2, 'b');
        Node nn2 = new Node(1, 'b');

        Node nnn1 = new Node(3, 'c');
        Node nnn2 = new Node(3, 'c');

        nn1.addChild(nnn1);
        nn2.addChild(nnn2);

        n1.addChild(nn1);
        n2.addChild(nn2);

        root.addChild(n1);
        root.addChild(n2);

        System.out.println(sumVal(n1, n2));
        System.out.println(sumVal(nn1, nn2));
    }
}
