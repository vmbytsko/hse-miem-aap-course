def iinput():
    print("Введите массив:")
    m2d = []
    for i in range(3):
        m2d.append([])
        m2d[i].extend(map(int, input().split()))
    print("Введите два числа: ",end="")
    i1, i2 = map(int, input().split())
    return (m2d, i1, i2)


def to1d(m2d):
    m1d = []
    for j in range(4):
        for i in range(3):
            m1d.append(m2d[i][j])
    return m1d


def count(m1d, i1, i2):
    maxx = max(i1, i2)
    minn = min(i1, i2)
    maxx_count = 0
    minn_count = 0
    for i in m1d:
        if i > maxx:
            maxx_count+=1
        if i < minn:
            minn_count+=1
    return (maxx_count, minn_count)


def ooutput(m1d, maxx_count, minn_count):
    print("Одномерный массив:")
    print(*m1d)
    print(f"Количество элементов, больших максимального значения из двух заданных чисел = {maxx_count}")
    print(f"Количество элементов, меньших минимального значения из тех же двух заданных чисел = {minn_count}")


def ooutput2d(m2d):
    print("Двумерный массив:")
    for i in range(3):
        print(*m2d[i])


m2d, i1, i2 = iinput()
ooutput2d(m2d)
m1d = to1d(m2d)
maxx_count, minn_count = count(m1d, i1, i2)
ooutput(m1d, maxx_count, minn_count)






