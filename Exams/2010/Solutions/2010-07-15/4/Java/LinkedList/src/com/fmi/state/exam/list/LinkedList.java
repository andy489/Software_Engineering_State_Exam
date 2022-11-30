package com.fmi.state.exam.list;

import com.fmi.state.exam.node.Node;

public class LinkedList<T> {
    private Node<T> head;
    private Node<T> tail;
    private int size;

    public LinkedList() {
        head = tail = null;
    }

    public int size() {
        return size;
    }

    public Node<T> getHead() {
        return head;
    }

    public Node<T> getTail() {
        return tail;
    }

    public void addAtTail(T data) {
        Node<T> n = new Node<>(data, null);

        if (head == null) {
            head = tail = n;
        } else {
            tail.setNext(n);
            tail = n;
        }

        size++;
    }

    public int countConsecutiveEqualElements() {
        Node<T> traversal = head;

        int cnt = 0;
        boolean flagFirstMatch = false;

        while (traversal != null && traversal.getNext() != null) {
            Node<T> prev = traversal;
            traversal = traversal.getNext();

            if (prev.getData() == traversal.getData()) {
                if (!flagFirstMatch) {
                    cnt++;
                    flagFirstMatch = true;
                }
                cnt++;
            } else {
                flagFirstMatch = false;
            }
        }
        if (cnt == 0 && size != 0) {
            return 1;
        }

        return cnt;
    }

    @Override
    public String toString() {
        if (size == 0) {
            return "Empty list";
        }

        Node<T> traversal = head;
        StringBuilder sb = new StringBuilder();

        while (traversal != null) {
            sb.append(traversal.getData()).append("->");
            traversal = traversal.getNext();
        }

        sb.delete(sb.length() - 1, sb.length());
        sb.append("|");

        return sb.toString();
    }
}
