#include <stdio.h>
#include <limits.h>
#include <math.h>
#define lmax 100

float zadanie1(float n1, float n2, float n3, float n4) {
    return (n1*n2)-(n3*n4);
}

void zadanie2_vvodA(float A[][lmax], int *n, int *m) {
    float *ptr_i,*ptr_j;
    int buf;

    do {
        printf("Введите число строк и столбцов матрицы A: ");
        buf = scanf("%d%d",n,m);
        while(getchar() != '\n');
    } while(*n <= 0 || *m <= 0 || *n >= lmax || *m >= lmax || buf != 2);

    printf("Введите матрицу %d на %d элементов:\n",*n,*m);

    for(ptr_i = *A; ptr_i < *A + *n*lmax; ptr_i+=lmax) {
        for(ptr_j = ptr_i; ptr_j < ptr_i+*m; ptr_j++) {
            scanf("%f",ptr_j);
        }
    }
}

float zadanie2_nahozhdenieD(float A[][lmax], int n, int m) {
    float D = INT_MIN;
    float *ptr_i, *ptr_j;
    for(ptr_i = *A; ptr_i < *A + n*lmax; ptr_i+=lmax) {
        float min = INT_MAX;
        for(ptr_j = ptr_i; ptr_j < ptr_i+m; ptr_j++)
            if(fabs(*ptr_j)<=fabs(min)) min = *ptr_j;
        if(min>D) D = min;
    }
    return D;
}

void zadanie3_vvodA(int A[lmax], int *n) {
    int *ptr_i, buf;

    do {
        printf("Введите число элементов массива A: ");
        buf = scanf("%d",n);
        while(getchar() != '\n');
    } while(*n <= 0 || *n >= lmax || buf != 1);

    printf("Введите массив A из %d элементов:\n",*n);
    for(ptr_i = A; ptr_i < A+*n; ptr_i++) {
        scanf("%d",ptr_i);
    }
}

void zadanie3_countA(int A[lmax], int *n, int B[lmax]) {
    int *ptr_i, *ptr_j, *ptr_k;

    // заполнение массива B нулями
    for(ptr_i = B; ptr_i < B+*n; ptr_i++) *ptr_i = 0;

    for(ptr_i = A; ptr_i < A+*n; ptr_i++)
        for(ptr_j = A, ptr_k = B; ptr_j < A+*n; ptr_j++, ptr_k++)
            if((*ptr_i == *ptr_j) && (ptr_i-A != ptr_j-A)) (*ptr_k)++;

    printf("Количество повторений каждого элемента массива A:\n");
    for(ptr_k = B; ptr_k < B+*n; ptr_k++) printf("%6d",*ptr_k);
    printf("\n");
}

void zadanie3_obrabotkaA(int A[lmax], int *n, int *k) {
    int *ptr_i, *ptr_j, offset=0;
    *k = 0;

    for(ptr_i = A; ptr_i < A+*n; ptr_i++) {
        ptr_j = A;
        while((ptr_j < A+*n && *ptr_j != *ptr_i) || ptr_i == ptr_j) ptr_j++;
        if(ptr_j==A+*n) offset++; // нет совпадений
        else {
            *(ptr_i-offset)=*ptr_i;
            (*k)++;
        }
    }
}

void zadanie3_vyvodA(int A[lmax], int *k) {
    int *ptr_i;

    if(*k == 0) printf("Нет повторяющихся элементов в массиве A\n");
    else {
        printf("Массив A:\n");

        for(ptr_i = A; ptr_i < A+*k; ptr_i++) {
            printf("%6d",*ptr_i);
        }
    }
}

int main() {
    printf("Лабораторная работа №3 Быцко Вячеслав БИТ233\n");

    printf("Задание 1 вариант 8\n");
    float x,y,a,b,c,d,e,f,zad2_A[lmax][lmax],zad2_D;
    int buf,n,m,k,zad3_A[lmax],zad3_B[lmax];

    do {
        printf("Введите a, b, c, d, e, f: ");
        buf = scanf("%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f);
        while(getchar() != '\n');
    } while(buf != 6);

    if(zadanie1(a,e,b,d) == 0.0) printf("Невозможно сосчитать: ошибка деления на ноль.\n");
    else {
        x = zadanie1(c,e,b,f) / zadanie1(a,e,b,d);
        y = zadanie1(a,f,c,d) / zadanie1(a,e,b,d);
        printf("x = %f; y = %f\n",x,y);
    }

    printf("\n");

    printf("Задание 2 вариант 7\n");
    zadanie2_vvodA(zad2_A,&n,&m);
    zad2_D = zadanie2_nahozhdenieD(zad2_A,n,m);
    printf("D = %f\n",zad2_D);

    printf("\n");

    printf("Задание 3 вариант 4\n");
    zadanie3_vvodA(zad3_A,&n);
    zadanie3_countA(zad3_A,&n,zad3_B);
    zadanie3_obrabotkaA(zad3_A,&n,&k);
    zadanie3_vyvodA(zad3_A,&k);

    return 0;
}
