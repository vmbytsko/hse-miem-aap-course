#include <stdio.h>
#include <math.h>
#define lmax 100

int main()
{
    int f[lmax][lmax],n,m,q[lmax],k,buf,i,j,l,multiply,temp,flag,b[lmax],nb,numbers;

    printf("Лабораторная работа №2 Быцко Вячеслав БИТ233\n");
    // задание 1
    printf("Задание 1, вариант 3\n");
    do {
        printf("Введите число строк и столбцов матрицы F: ");
        buf = scanf("%d%d",&n,&m);
        while(getchar() != '\n');
    } while(n <= 0 || m <= 0 || n >= lmax || m >= lmax || buf != 2);

    printf("Введите матрицу %d на %d элементов:\n",n,m);

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            scanf("%d",&f[i][j]);
        }
    }

    do {
        printf("Введите длину массива Q: ");
        buf = scanf("%d",&k);
        while(getchar() != '\n');
    } while(k <= 0 || k >= lmax || buf != 1);

    printf("Введите массив Q из %d элементов:\n",k);
    for(i = 1; i <= k; i++) {
        scanf("%d",&q[i]);
    }

    for(j = 1; j <= m; j++) {
        multiply = 1;
        for(i = 1; i <= n; i++) {
            multiply*=f[i][j];
        }
        for(i = 1; i <= k && multiply != q[i]; i++);
        if(i<=k) {
            do {
                flag = 0;
                for(int l = 1; l <= n-1; l++) {
                    if(f[l][j] > f[l+1][j]) {
                        temp = f[l][j];
                        f[l][j] = f[l+1][j];
                        f[l+1][j] = temp;
                        flag = 1;
                    }
                }
            } while (flag);
        } else {
            printf("Нет произведения столбца %d в массиве Q\n",j);
        }
    }

    printf("Матрица F:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            printf("%4d",f[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // задание 2
    printf("Задание 2, вариант 8\n");
    do {
        printf("Введите длину массива B: ");
        buf = scanf("%d",&nb);
        while(getchar() != '\n');
    } while(nb <= 0 || nb >= lmax || buf != 1);

    printf("Введите массив B из %d элементов:\n",nb);
    for(i = 1; i <= nb; i++) {
        scanf("%d",&b[i]);
    }

    for(i = 1; i <= nb; i++) {
        temp = b[i];
        numbers = 0;
        while(temp/10!=0) {
            numbers++;
            temp/=10;
        }
        temp = b[i]%10;
        b[i] = b[i]/10+temp*(int)pow(10,numbers);
    }

    printf("Массив B:\n");
    for(i = 1; i <= nb; i++) {
        printf("%8d",b[i]);
    }

    return 0;
}
