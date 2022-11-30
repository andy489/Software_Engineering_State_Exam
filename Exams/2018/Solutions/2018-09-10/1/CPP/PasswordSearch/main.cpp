#include <iostream>

using namespace std;

const int ROWS = 3;
const int BOOKS = 3;
const int MAX_CHARS_TITLE = 100;

void countLetters(const wchar_t bookName[]) {
    int i = 0, currLetterCnt = 0;
    while (bookName[i] != '\0') {
        if (isspace(bookName[i])) {
            cout << currLetterCnt << ' ';
            currLetterCnt = 0;
        } else {
            ++currLetterCnt;
        }

        ++i;
    }

    cout << currLetterCnt << ' ';
}

bool checkRow(const wchar_t row[][MAX_CHARS_TITLE]) {
    for (int i = 1; i < ROWS; ++i) {
        if (wcscmp(row[i - 1], row[i]) > 0) {
            return false;
        }
    }

    return true;
}

void revealPassword(const wchar_t library[][BOOKS][MAX_CHARS_TITLE]) {
    for (int i = 0; i < BOOKS; ++i) {
        if (checkRow(library[i])) {
            int mid = ROWS >> 1;
            countLetters(library[i][mid]);
        }
    }
}

int main() {
    const wchar_t library[][BOOKS][MAX_CHARS_TITLE] = {
            {L"Алгебра",               L"Аналитична геометрия",             L"Математически анализ"},
            {L"Увод в програмирането", L"Обектно-ориентирано програмиране", L"Структури от данни и програмиране"},
            {L"Бази от данни",         L"Изкуствен интелект",               L"Функционално програмиране"}
    };

    revealPassword(library);

    return 0;
}