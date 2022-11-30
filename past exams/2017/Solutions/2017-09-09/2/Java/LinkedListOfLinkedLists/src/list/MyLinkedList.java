package list;

import node.Node;

import java.util.Arrays;
import java.util.Objects;

public class MyLinkedList<T extends Comparable<? super T>> implements Comparable<MyLinkedList<T>> {
    private Node<T> head, tail;
    private Integer size;

    public MyLinkedList() {
        head = null;
        size = 0;
    }

    public MyLinkedList(Node<T> h) {
        head = h;
        int sz = 0;
        Node<T> traversal = h;

        while (traversal != null) {
            tail = traversal;
            traversal = traversal.getNext();
            sz++;
        }

        size = sz;
    }

    @SafeVarargs
    public MyLinkedList(T... arr) {
        this();
        Arrays.stream(arr).filter(Objects::nonNull).forEach(this::addAtTail);
    }

    public Node<T> getHead() {
        return head;
    }

    public Integer size() {
        return size;
    }

    public void addAtTail(T data) {
        if (head == null) {
            head = tail = Node.of(data);
        } else {
            Node<T> toAdd = Node.of(data);
            tail.setNext(toAdd);
            tail = toAdd;
        }

        size++;
    }

    public Boolean checkSorted() {
        Node<T> traversal = head;

        while (traversal != null && traversal.getNext() != null) {
            if (traversal.getData().compareTo(traversal.getNext().getData()) > 0) {
                return false;
            }

            traversal = traversal.getNext();
        }

        return true;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(" ");

        Node<T> traversal = head;
        while (traversal != null) {
            sb.append(traversal).append(" ");
            traversal = traversal.getNext();
        }

        sb.append(System.lineSeparator());
        return sb.toString();
    }

    @Override
    public int compareTo(MyLinkedList<T> o) {
        return this.head.getData().compareTo(o.head.getData());
    }
}
