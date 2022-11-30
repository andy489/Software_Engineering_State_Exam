package node;

public class Node {
    private final int data;
    private Node next, nextK;

    public Node(int data) {
        this.data = data;
        next = nextK = null;
    }

    public int getData() {
        return data;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public Node getNextK() {
        return nextK;
    }

    public void setNextK(Node nextK) {
        this.nextK = nextK;
    }

    @Override
    public String toString() {
        return String.valueOf(data) + ' ';
    }
}
