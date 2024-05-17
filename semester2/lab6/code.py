temp = 0
for n in range(int(input("Введите n: "))):
    temp += ((-1)**n * (n+1)/(3*(n+3)**3))
    print(n, temp)