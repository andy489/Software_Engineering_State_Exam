package com.fmi.state.exam;

public class Main {
    public static void main(String... args) {
        System.out.println(Laptop.getAllConnected());

        Laptop l1 = new Laptop(true, 500, 1, 3.2f);
        Laptop l2 = new Laptop(false, 1000, 1, 2.8f);

        System.out.println(Laptop.getAllConnected());

        l2.setIsConnected(true);

        System.out.println(Laptop.getAllConnected());

        l1.setIsConnected(false);

        System.out.println(Laptop.getAllConnected());

        l2 = null;
        Laptop.decrementAllConnected();

        System.out.println(Laptop.getAllConnected());
    }
}
