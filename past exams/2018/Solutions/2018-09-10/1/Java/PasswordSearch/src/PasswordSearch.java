public class PasswordSearch {

    public static int ROWS = 3;
    public static int BOOKS = 3;

    public static final String[][] library = {
            {"Алгебра", "Аналитична геометрия", "Математически анализ"},
            {"Увод в програмирането", "Обектно-ориентирано програмиране", "Структури от данни и програмиране"},
            {"Бази от данни", "Изкуствен интелект", "Функционално програмиране"}
    };

    public static void revealPassword() {
        for (int i = 0; i < BOOKS; i++) {
            if (checkRow(i)) {
                int mid = ROWS >> 1;
                countLetters(i, mid);
            }
        }
    }

    public static boolean checkRow(int i) {
        for (int j = 1; j < ROWS; j++) {
            if (library[i][j - 1].compareTo(library[i][j]) > 0) {
                return false;
            }
        }

        return true;
    }

    public static void countLetters(int i, int mid) {
        int currLetterCnt = 0, SIZE = library[i][mid].length();
        for (int j = 0; j < SIZE; j++) {
            if (library[i][mid].charAt(j) == ' ') {
                System.out.printf("%d ", currLetterCnt);
                currLetterCnt = 0;
            } else {
                currLetterCnt++;
            }
        }

        System.out.printf("%d ", currLetterCnt);
    }

    public static void main(String... args) {
        revealPassword();
    }
}
