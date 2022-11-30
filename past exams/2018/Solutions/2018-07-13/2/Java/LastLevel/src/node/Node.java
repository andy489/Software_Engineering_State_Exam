package node;

public class Node {
    private final Character c;
    private final Node[] children;

    public Node(Character c) {
        this.c = c;
        children = new Node[3];
    }

    public Character getChar() {
        return c;
    }

    public Node[] getChildren() {
        return children;
    }

    public void setChild(int i, Node child) {
        if (i < 0 || i >= 3) {
            throw new IllegalArgumentException("Child index out of range");
        }

        children[i] = child;
    }
}
