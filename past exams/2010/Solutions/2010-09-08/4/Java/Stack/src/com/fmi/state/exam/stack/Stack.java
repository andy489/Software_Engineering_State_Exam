package com.fmi.state.exam.stack;

import com.fmi.state.exam.node.Node;

import java.util.EmptyStackException;

public class Stack<T> {
    private Node<T> head;
    private int size;

    public Stack() {
        head = null;
        size = 0;
    }

    public Stack(Stack<T> other) {
        head = other.head();
        size = other.size();
    }

    public Node<T> head() {
        return head;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void push(T data) {
        if (size == 0) {
            head = new Node<>(data);
        } else {
            Node<T> temp = head;
            head = new Node<>(data, temp);
        }

        size++;
    }

    public void pop() {
        if (size == 0) {
            return;
        }

        head = head.getNext();

        size--;
    }

    public T peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }

        return head.getData();
    }

    public void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
}
