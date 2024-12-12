#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
int is_word_char(char c) {
    return isalnum(c) || c == '\''; // �������, �� ����� ���� ������ �����, ����� �� ��������
}

int main() {
    setlocale(LC_ALL, "RU");
    FILE* inputFile, * outputFile;
    char ch;
    int wordCount = 0, sentenceCount = 0;
    int inWord = 0;

    // ³�������� ������� ���� ��� �������
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("�� ������� ������� ������� ����");
        return EXIT_FAILURE;
    }

    // ������ ���� ������ �� ��������
    while ((ch = fgetc(inputFile)) != EOF) {
        // ����������, �� � ������ �������� �����
        if (is_word_char(ch)) {
            if (!inWord) {
                inWord = 1; // ������� ������ �����
                wordCount++;
            }
        }
        else {
            inWord = 0; // ʳ���� �����
        }

        // ����������, �� � ������ ���������� �������
        if (ch == '.' || ch == '!' || ch == '?') {
            sentenceCount++;
        }
    }

    // ��������� ������� ����
    fclose(inputFile);

    // ³�������� �������� ���� ��� ������
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("�� ������� ������� ������� ����");
        return EXIT_FAILURE;
    }

    // �������� ���������� � �������� ����
    fprintf(outputFile, "���������� ����: %d\n", wordCount);
    fprintf(outputFile, "���������� �����������: %d\n", sentenceCount);

    // ��������� �������� ����
    fclose(outputFile);

    printf("��������� ���������. ���������� �������� � ���� output.txt\n");
    return EXIT_SUCCESS;
}