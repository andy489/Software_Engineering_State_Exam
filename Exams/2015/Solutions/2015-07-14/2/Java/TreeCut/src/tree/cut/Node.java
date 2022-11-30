package tree.cut;

import java.util.ArrayList;
import java.util.List;

public class Node {
    private int data;
    private List<Node> children;

    public Node(int data, List<Node> children) {
        this.data = data;
        this.children = children;
    }

    public int data() {
        return data;
    }

    public List<Node> children() {
        return children;
    }

    public void setChildren(List<Node> newChildren) {
        children = newChildren;
    }

    public static Node of(int data) {
        return new Node(data, new ArrayList<>());
    }

    @Override
    public String toString() {
        return String.format("%d ", data);
    }
}
