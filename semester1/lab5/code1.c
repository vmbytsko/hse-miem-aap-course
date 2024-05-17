#include <stdio.h>
#define lmax 100

// функция удаления \n в конце строки, который оставил fgets
void deln(char *s) { 
    for (; *s && *s!='\n'; s++);
	*s='\0';
}

void taskOne_writeFile(char filename[]) {

    FILE *fout; 
    char str[lmax+1];

    printf("Введите файл. Пустая строка равна концу файла: \n"); 
    fout = fopen(filename,"w");
    while(gets(str) != NULL && strcmp(str,"") != 0) {
        fputs(str, fout);
        fputc('\n', fout);
    }

    fclose(fout); 
}

void taskOne_calculate(char filename[]) {

    FILE *fin;
    int i,j,numOfPositives = 0;
    float sumOfPositives = 0.0;
    if (!(fin=fopen(filename,"r"))) {
        puts("Файл не найден!");
        exit(1);
    }

    while (!feof(fin)) {
        float tempFloat;
        int temp = fscanf(fin, "%f", &tempFloat);
        if (temp > 0) {
            if (tempFloat > 0) {
                numOfPositives++;
                sumOfPositives += tempFloat;
            } 
        } else {
            if(!feof(fin)) {
                printf("Ошибка чтения действительного числа.");
                exit(1);
            } 
        }
    }
    fclose(fin);
    if(numOfPositives == 0) {
        printf("Нет положительных чисел.");
    } else {
        printf("Среднее арифметическое: %f", sumOfPositives / numOfPositives);
    }
}

int main() {

    char filename[lmax];

    printf("Лабораторная работа №5 Быцко Вячеслав БИТ233\n");
    printf("Задание 1 вариант 4\n");

    printf("Введите название файла: ");
    fgets(filename, lmax, stdin);
    deln(filename);

    taskOne_writeFile(filename);
    taskOne_calculate(filename);

    return 0;
}
