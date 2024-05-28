class Dot:
    def __init__(self,x=None,y=None,z=None):
        self.__x = x
        self.__y = y
        self.__z = z

    def input(self):
        print("Введите координаты точки: ",end="")
        self.__x, self.__y, self.__z = map(float, input().split())

    def output(self):
        print(f"Точка ({self.__x}, {self.__y}, {self.__z})")

    def getcoordinates(self):
        return self.__x, self.__y, self.__z


class Disk:
    def __init__(self,center=None,a=None,b=None,w=None):
        self.__center = center
        self.__a = a
        self.__b = b
        self.__w = w

    def input(self):
        print("Введите центр:")
        self.__center = Dot()
        self.__center.input()

        print("Введите a, b, толщину: ",end="")
        self.__a, self.__b, self.__w = map(float, input().split())

    def output(self):
        print("Эллипсоидный диск с толщиной:")
        print("Центр: ",end="")
        self.__center.output()
        print(f"a: {self.__a}")
        print(f"b: {self.__b}")
        print(f"Толщина: {self.__w}")

    def getparameters(self):
        return self.__center, self.__a, self.__b, self.__w

    def dotin(self, dot):
        a,b,w = self.__a, self.__b, self.__w
        centerx, centery, centerz = self.__center.getcoordinates()
        dotx, doty, dotz = dot.getcoordinates()

        if ((dotx - centerx) ** 2 / a ** 2) + ((doty - centery) ** 2 / b ** 2) > 1:
            return False

        if dotz < centerz - w or dotz > centerz + w:
            return False

        return True


def dotindisk(dot, disk):
    center, a, b, w = disk.getparameters()
    centerx, centery, centerz = center.getcoordinates()
    dotx, doty, dotz = dot.getcoordinates()

    if ((dotx - centerx) ** 2 / a ** 2) + ((doty - centery) ** 2 / b ** 2) > 1:
        return False

    if dotz < centerz-w or dotz > centerz+w:
        return False

    return True


print("Введите диск:")
disk = Disk()
disk.input()

print("Введите точку:")
dot = Dot()
dot.input()

disk.output()
dot.output()

print("Точка внутри или на диске" if disk.dotin(dot) else "Точка снаружи диска")
print("Точка внутри или на диске" if dotindisk(dot, disk) else "Точка снаружи диска")



    

