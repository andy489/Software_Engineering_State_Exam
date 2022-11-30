package node;

import java.util.ArrayList;
import java.util.List;

public class Node {
    private final Long value;
    private final Character label;

    private final List<Node> children;

    public Node(Long value, Character label) {
        this.value = value;
        this.label = label;

        children = new ArrayList<>();
    }

    public Long getValue(){
        return value;
    }

    public Character getLabel(){
        return label;
    }

    public List<Node> getChildren(){
        return children;
    }

    public void addChild(Node child){
        children.add(child);
    }
}
