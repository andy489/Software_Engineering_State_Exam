package com.fmi.statistics;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.concurrent.ThreadLocalRandom;

public class Statistics {
    private static boolean checkAllTraversed(boolean[] flags) {
        for (boolean flag : flags) {
            if (!flag) {
                return false;
            }
        }

        return true;
    }

    public static void main(String... args) {
        final int SIZE = 27;
        final int ORIGIN = 1;
        final int BOUND = 4900;
        final int INTERVALS = 5;

        int[] arr = new int[SIZE];

        Random rng = new Random(ThreadLocalRandom.current().nextInt());

        for (int i = 0; i < SIZE; i++) {
            arr[i] = rng.nextInt(ORIGIN, BOUND);
        }

        Map<Integer, Map<Integer, Integer>> histogram = new TreeMap<>();

        for (int i = 0; i < INTERVALS; i++) {
            histogram.put(i, new TreeMap<>());
        }

        boolean[] indicatorsEmpty = new boolean[INTERVALS];
        Arrays.fill(indicatorsEmpty, true);

        for (int r : arr) {
            int intervalNum = r / 1_000;
            histogram.get(intervalNum).merge(r, 1, Integer::sum);
            indicatorsEmpty[intervalNum] = false;
        }

        Map<Integer, List<Integer>> histogramFlat = new TreeMap<>();

        for (int i = 0; i < INTERVALS; i++) {
            histogramFlat.put(i, histogram.get(i).keySet().stream().toList());
        }

        DecimalFormat ft = new DecimalFormat();

        List<Iterator<Integer>> iterators = new ArrayList<>();

        for (int i = 0; i < INTERVALS; i++) {
            iterators.add(histogramFlat.get(i).iterator());
        }

        final String nl = System.lineSeparator();
        StringBuilder sb = new StringBuilder("Под 1\t\tПод 2\t\tПод 3\t\tПод 4\t\tПод 5").append(nl);

        while (!checkAllTraversed(indicatorsEmpty)) {
            for (int i = 0; i < INTERVALS; i++) {
                if (iterators.get(i).hasNext()) {
                    Integer next = iterators.get(i).next();
                    sb.append("\t").append(ft.format(next / 1000.0)).append("\t");
                    if (next % 100 == 0) {
                        sb.append("\t");
                    }
                } else {
                    sb.append("\t\t\t");
                    indicatorsEmpty[i] = true;
                }
            }
            sb.append(nl);
        }

        System.out.print(sb);
    }
}
