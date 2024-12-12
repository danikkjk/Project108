#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
int is_word_char(char c) {
    return isalnum(c) || c == '\''; // Вважаємо, що слово може містити літери, цифри та апостроф
}

int main() {
    setlocale(LC_ALL, "RU");
    FILE* inputFile, * outputFile;
    char ch;
    int wordCount = 0, sentenceCount = 0;
    int inWord = 0;

    // Відкриваємо вхідний файл для читання
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Не удалось открыть входной файл");
        return EXIT_FAILURE;
    }

    // Читаємо файл символ за символом
    while ((ch = fgetc(inputFile)) != EOF) {
        // Перевіряємо, чи є символ частиною слова
        if (is_word_char(ch)) {
            if (!inWord) {
                inWord = 1; // Початок нового слова
                wordCount++;
            }
        }
        else {
            inWord = 0; // Кінець слова
        }

        // Перевіряємо, чи є символ закінченням речення
        if (ch == '.' || ch == '!' || ch == '?') {
            sentenceCount++;
        }
    }

    // Закриваємо вхідний файл
    fclose(inputFile);

    // Відкриваємо вихідний файл для запису
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Не удалось открыть входной файл");
        return EXIT_FAILURE;
    }

    // Записуємо результати у вихідний файл
    fprintf(outputFile, "Количество слов: %d\n", wordCount);
    fprintf(outputFile, "Количество предложений: %d\n", sentenceCount);

    // Закриваємо вихідний файл
    fclose(outputFile);

    printf("Обработка завершена. Результаты записано в файл output.txt\n");
    return EXIT_SUCCESS;
}