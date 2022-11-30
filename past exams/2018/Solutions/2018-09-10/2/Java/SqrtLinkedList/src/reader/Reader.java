package reader;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Arrays;

public class Reader {
    private Reader() {

    }

    public static int[] readFromFile(Path filePath) {
        int[] numbers;
        try (BufferedReader br = Files.newBufferedReader(filePath)) {
            String line;
            StringBuilder sb = new StringBuilder();

            while ((line = br.readLine()) != null) {
                if (line.length() > 0) {
                    sb.append(line).append(' ');
                }
            }

            numbers = Arrays.stream(sb.toString().split(" "))
                    .mapToInt(Integer::parseInt)
                    .toArray();
        } catch (IOException e) {
            throw new IllegalStateException("A problem occurred while reading from a file", e);
        }

        return numbers;
    }
}
