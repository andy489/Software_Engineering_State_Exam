package node;

public class Node<T extends Comparable<? super T>> {
    private final T data;
    private Node<T> next;

    public Node(T data, Node<T> next) {
        this.data = data;
        this.next = next;
    }

    public T getData() {
        return data;
    }

    public Node<T> getNext() {
        return next;
    }


    public void setNext(Node<T> next) {
        this.next = next;
    }

    public static <T extends Comparable<? super T>> Node<T> of(T data) {
        return new Node<>(data, null);
    }

    @Override
    public String toString() {
        return data.toString();
    }
}
