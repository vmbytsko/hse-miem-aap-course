#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define lmax 100

// функция удаления \n в конце строки, который оставил fgets
void deln(char *s) {
    for (; *s && *s!='\n'; s++);
	*s='\0';
}

void taskOne_rewrite(char filenameIn[], char filenameOut[]) {

    FILE *fin, *fout;
    int i,j;

    if (!(fin=fopen(filenameIn,"r"))) {
        puts("Файл не найден!");
        exit(1);
    }

    fout = fopen(filenameOut,"w");

    while (!feof(fin)) {
        char string[lmax] = "";
        int temp = fscanf(fin, "%s", string);
        if (temp > 0) { // строка считалась успешно
            int count = 0;
            for (int i = 0; i <= strlen(string); i++) {
                if(isdigit(string[i])) {
                    count++;
                } else {
                    if(count >= 2) {
                        for(int j = strlen(string); j >= i; j--) {
                            string[j+1] = string[j];
                        }
                        string[i] = 'A';
                    }
                    count = 0;
                }
            }
        fprintf(fout, "%s\n", string);
        printf("%s\n", string);
        }
    }
    fclose(fin);
    fclose(fout);

}

int main() {

    char filenameIn[lmax], filenameOut[lmax];

    printf("Лабораторная работа №5 Быцко Вячеслав БИТ233\n");
    printf("Задание 2 вариант 7\n");

    printf("Введите название файла, откуда будут считываться строки: ");
    fgets(filenameIn, lmax, stdin);
    deln(filenameIn);

    printf("Введите название файла, куда будет вписан результат: ");
    fgets(filenameOut, lmax, stdin);
    deln(filenameOut);

    taskOne_rewrite(filenameIn, filenameOut);

    return 0;
}
