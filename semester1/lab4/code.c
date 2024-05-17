#include <stdio.h>
#include <string.h>
#include <limits.h>
#define nmax 20
#define lmax 100
#define CLR while (getchar()!='\n')

void task1(char strs[nmax][lmax], int k, char substrs[lmax][lmax], int *num_of_substrs, int substrs_to_strs[lmax]) {
    int i;
    char *str_ptr, *start_str_ptr, *end_str_ptr, divider;

    for(i = 0; i < k; i++) {
        str_ptr = strs[i];
        for(str_ptr = strs[i]; *str_ptr; str_ptr++) {
            if(*str_ptr == '+' || *str_ptr == '-' || *str_ptr == '*' || *str_ptr == '/') {
                divider = *str_ptr; // запоминаем, что за символ
                start_str_ptr = end_str_ptr = str_ptr+1; // отмечаем начало подстроки и конец подстроки

                // циклом доходим до второго такого же divider'а или до конца строки
                while(*end_str_ptr != divider && *end_str_ptr) end_str_ptr++;

                // проверяем, что не в конце строки и что подстрока не нулевой длины
                if(*end_str_ptr == divider && start_str_ptr != end_str_ptr) {
                    substrs_to_strs[*num_of_substrs] = i; // создаём связь между строкой и подстрокой
                                                          // связь: по очереди указывается, к какой строке
                                                          // относится подстрока. НАПРИМЕР
                                                          // substrs[0] - подстрока
                                                          // substrs_to_strs[0] - число, указывающее, из какой
                                                          //                      по счёту строки выделена подстрока
                    strncpy(substrs[*num_of_substrs], start_str_ptr, end_str_ptr - start_str_ptr); // копируем подстроку
                    substrs[*num_of_substrs][end_str_ptr - start_str_ptr] = '\0';
                    (*num_of_substrs)++;
                }
            }
        }
    }
}

int task2(char substrs[lmax][lmax], char substrs_to_strs[lmax], int num_of_substrs) {

    int found = -1, i, temp, min_digits = INT_MAX;
    char *str_ptr;

    for(i = 0; i < num_of_substrs; i++) {
        temp = 0;
        str_ptr = substrs[i];

        // указатель на '\0'
        while(*str_ptr) str_ptr++;

        // указатель на последнем символе
        str_ptr--;

        while(isdigit(*str_ptr)) {
            temp++; str_ptr--;
        }

        if(temp < min_digits && temp != 0) {
            min_digits = temp;
            found = i;
        }
    }

    return found;
}

void task3(char str[lmax]) {

    char *str_ptr_to_end, *str_ptr_to_digit, *str_ptr;

    // доходим до '\0'
    str_ptr_to_end = str;
    while(*str_ptr_to_end) str_ptr_to_end++;

    // и продублируем адрес последнего символа ('\0') в указатель str_ptr_to_digit
    str_ptr_to_digit = str_ptr_to_end;

    // цикл укажет на последнюю цифру
    while(!isdigit(*str_ptr_to_digit)) str_ptr_to_digit--;

    // не проверяем, что цифры нет, ибо цифра обязательно есть
    // перемещаем символы с последнего до цифры включительно на три символа вперёд
    for(str_ptr = str_ptr_to_end; str_ptr >= str_ptr_to_digit; str_ptr--) {
        *(str_ptr+3) = *str_ptr;
    }
    *str_ptr_to_digit = '*'; *(str_ptr_to_digit+1) = '*'; *(str_ptr_to_digit+2) = '*';
}

int main()
{
    int i, k, temp, substrs_to_strs[lmax], num_of_substrs, task2_found_substr;
    char strs[nmax][lmax], substrs[lmax][lmax];

    printf("Лабораторная работа №4 Быцко Вячеслав БИТ233\n");
    printf("Задание 1 вариант 4\n");
    do {
        printf("Введите количество строк k: ");
        temp = scanf("%d", &k);
    } while(temp != 1 && k <= 0 && k >= lmax);

    // очистка буфера
    // смотрим define
    CLR;

    printf("Введите %d строк:\n", k);
    for(i = 0; i < k; i++) {
        gets(strs[i]);
    }

    num_of_substrs = 0;
    task1(strs, k, substrs, &num_of_substrs, substrs_to_strs);

    if(num_of_substrs) {
        puts("Подстроки:");
        for(i = 0; i < num_of_substrs; i++) {
            puts(substrs[i]);
        }

        printf("Задание 2 вариант 8\n");
        task2_found_substr = task2(substrs, substrs_to_strs, num_of_substrs);
        if(task2_found_substr != -1) {
            printf("Подстрока, оканчивающаяся на минимальное количество цифр:\n%s\n", substrs[task2_found_substr]);
            printf("Она была взята из исходной строки №%d:\n",substrs_to_strs[task2_found_substr]+1);
            puts(strs[substrs_to_strs[task2_found_substr]]);

            printf("Задание 3 вариант 11\n");
            task3(strs[substrs_to_strs[task2_found_substr]]);
            printf("Изменённая строка:\n");
            puts(strs[substrs_to_strs[task2_found_substr]]);
        } else puts("Подстроки, оканчивающейся на цифру(ы), нет.");
    } else puts("Подстрок нет.");

    return 0;
}
