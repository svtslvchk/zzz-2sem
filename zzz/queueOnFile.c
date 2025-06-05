#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_FILE "queue.dat"
#define TEMP_FILE "temp.dat"

typedef int T;

// Создание (очистка очереди)
void createQueue() {
    FILE *q = fopen(QUEUE_FILE, "wb");
    if (!q) {
        perror("Ошибка при создании очереди");
        exit(EXIT_FAILURE);
    }
    fclose(q);
}

// Проверка на пустоту
bool isEmpty() {
    FILE *q = fopen(QUEUE_FILE, "rb");
    if (!q) return true;  // Очередь не существует = пуста
    fseek(q, 0, SEEK_END);
    long size = ftell(q);
    fclose(q);
    return size == 0;
}

// Добавление элемента (push)
void push(T value) {
    FILE *q = fopen(QUEUE_FILE, "rb");
    FILE *temp = fopen(TEMP_FILE, "wb");
    T tmp;

    if (q) {
        while (fread(&tmp, sizeof(T), 1, q) == 1) {
            fwrite(&tmp, sizeof(T), 1, temp);
        }
        fclose(q);
    }

    fwrite(&value, sizeof(T), 1, temp);  // Добавляем в конец
    fclose(temp);

    // Перезаписываем исходный файл
    q = fopen(QUEUE_FILE, "wb");
    temp = fopen(TEMP_FILE, "rb");
    while (fread(&tmp, sizeof(T), 1, temp) == 1) {
        fwrite(&tmp, sizeof(T), 1, q);
    }

    fclose(q);
    fclose(temp);
    remove(TEMP_FILE);
}

// Просмотр первого элемента
T top() {
    FILE *q = fopen(QUEUE_FILE, "rb");
    if (!q) {
        fprintf(stderr, "Очередь не существует или пуста.\n");
        exit(EXIT_FAILURE);
    }
    T value;
    if (fread(&value, sizeof(T), 1, q) != 1) {
        fprintf(stderr, "Очередь пуста.\n");
        exit(EXIT_FAILURE);
    }
    fclose(q);
    return value;
}

// Удаление первого элемента (pop)
void pop() {
    FILE *q = fopen(QUEUE_FILE, "rb");
    FILE *temp = fopen(TEMP_FILE, "wb");
    T value;
    bool skipped = false;

    if (!q) return;

    while (fread(&value, sizeof(T), 1, q) == 1) {
        if (!skipped) {
            skipped = true;  // Пропустить первый элемент
            continue;
        }
        fwrite(&value, sizeof(T), 1, temp);
    }

    fclose(q);
    fclose(temp);

    // Перезапись исходного файла
    q = fopen(QUEUE_FILE, "wb");
    temp = fopen(TEMP_FILE, "rb");
    while (fread(&value, sizeof(T), 1, temp) == 1) {
        fwrite(&value, sizeof(T), 1, q);
    }

    fclose(q);
    fclose(temp);
    remove(TEMP_FILE);
}
