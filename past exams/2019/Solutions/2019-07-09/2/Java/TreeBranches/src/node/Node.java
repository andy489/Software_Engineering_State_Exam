package node;

import java.util.ArrayList;
import java.util.List;

public class Node {
    private final int val;
    private final char sym;
    private final List<Node> children;

    public Node(int val, char sym) {
        this.val = val;
        this.sym = sym;

        children = new ArrayList<>();
    }

    public int getVal(){
        return val;
    }

    public char getSym(){
        return sym;
    }

    public void addChild(Node toAdd) {
        children.add(toAdd);
    }

    public boolean noChildren(){
        return children.isEmpty();
    }

    public List<Node> getChildren(){
        return children;
    }
}
