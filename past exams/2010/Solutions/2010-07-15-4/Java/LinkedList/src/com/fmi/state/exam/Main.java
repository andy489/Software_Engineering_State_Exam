package com.fmi.state.exam;

import com.fmi.state.exam.list.LinkedList;

public class Main {
    public static void main(String... args) {
        LinkedList<Integer> ll = new LinkedList<>();

        for (int i = 0; i < 6; i++) {
            ll.addAtTail(i);
            for (int j = 0; j < i; j++) {
                ll.addAtTail(i + i % 3);
            }
        }

        System.out.println(ll);
        System.out.println(ll.countConsecutiveEqualElements());
    }
}
