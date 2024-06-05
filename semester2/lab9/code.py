class Vector:
    def __init__(self, x=None, y=None, z=None):
        if x == 0 and y == 0 and z == 0:
            raise VectorIsZeroException("Вектор нулевой")
        self.x = x
        self.y = y
        self.z = z

    def input(self):
        try:
            print("Введите вектор: ", end="")
            x, y, z = map(int, input().split())
            if x == 0 and y == 0 and z == 0:
                raise VectorIsZeroException("Вектор нулевой")
            self.x = x
            self.y = y
            self.z = z
        except VectorIsZeroException:
            print("Вектор нулевой. Введите вектор ещё раз.")
            self.input()

    def __str__(self):
        return f"Вектор ({self.x}, {self.y}, {self.z})"

    def __iadd__(self, other):
        self.x += other.x
        self.y += other.y
        self.z += other.z
        return self

class VectorIsZeroException(Exception):
    pass

try:
    vnull = Vector(0,0,0)
except VectorIsZeroException:
    print("Проверка удалась.")

v1 = Vector(1,2,3)
v2 = Vector()
v2.input()
print("До прибавления:")
print(v1)
v1 += v2
print("После:")
print(v1)
