import numpy as np

def maketime(timestr):
    timestr = timestr.replace(".", ":")
    minutes, seconds, milliseconds = map(int, timestr.split(":"))
    return minutes * 60 + seconds + (milliseconds / 1000)


class Circles:
    def __init__(self, filename, columns):
        self.filename = filename
        self.columns = columns
        self.circles = np.loadtxt(filename, skiprows=1, usecols=columns, dtype=object)
        # первый столбик - номер круга
        self.circles[:, 0] = self.circles[:, 0].astype(int)
        # второй и третий столбики - делаем float из строкового времени
        self.circles[:, 1] = list(map(maketime, self.circles[:, 1]))
        self.circles[:, 2] = list(map(maketime, self.circles[:, 2]))

    def update(self, filename, columns):
        self.__init__(filename, columns)

    def __str__(self):
        result = []
        for i in self.circles:
            n, time1, time2 = i
            result.append(f"{n}: {time1}, {time2}")
        return "\n".join(result)

    def besttime(self, fromn, ton, racer):
        bestcircle = None
        circles = self.circles[fromn-1:ton]

        # поиск лучшего круга по времени
        for circle in circles:
            if bestcircle is None or bestcircle[racer] >= circle[racer]:
                bestcircle = circle
        return bestcircle[0], bestcircle[racer]

    def maxtempchange(self, fromn, ton, racer):
        #  падения темпа нет
        if ton - fromn == 0:
            return 0, 0

        circles = self.circles[fromn-1:ton]
        # номер круга, изменение
        prevtempchange = (0, 0)

        for i in range(len(circles)-1):
            if circles[i+1, racer] - circles[i, racer] > prevtempchange[1]:
                prevtempchange = circles[i+1, 0], circles[i+1, racer] - circles[i, racer]

        # возвращается номер круга, когда гонщик замедлился, и насколько сильно по сравнению с предыдущим
        return prevtempchange




racer1, racer2 = map(int, input("Введите два номера гонщиков, начиная с 1: ").split())
data = Circles("Монако 23.txt", [0, racer1, racer2])
print("Информация о кругах: (номер, гонщик1, гонщик2) ")
print(data)
fromn, ton, racer = map(int, input("Введите, с какого по какой круг найти лучшее время, и номер гонщика (1 или 2): ").split())
bt = data.besttime(fromn, ton, racer)
print(f"Самое лучшее время у гонщика было на круге {bt[0]}: {bt[1]}")
fromn, ton, racer = map(int, input("Введите, с какого по какой круг найти максимальное падение темпа, и номер гонщика (1 или 2): ").split())
tc = data.maxtempchange(fromn, ton, racer)
if tc[0] == 0:
    print("У гонщика не было падения темпа на этих кругах")
else:
    print(f"Самое большое падение темпа у гонщика было на круге {tc[0]}: по сравнению с предыдущим кругом, темп изменился на {tc[1]}")

