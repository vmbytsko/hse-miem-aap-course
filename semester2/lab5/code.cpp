#include <iostream>
#include <math.h>

using namespace std;

class Figure {

    protected:
    float x,y,z;

    public:
    Figure(){
        x = 0.0; y = 0.0; z = 0.0;
    }

    Figure(float ix, float iy, float iz) {
        x = ix; y = iy; z = iz;
    }

    void output() {
        cout << "точка отсчёта (" << x << ", " << y << ", " << z << ")" << endl;
    }

    void moveTo(float ix, float iy, float iz) {
        x = ix; y = iy; z = iz;
    }

    virtual float getArea() {
        return 0.0;
    }

    virtual void stretchZ(float izlen) {
        // do nothing
    }
};

class Parallelepiped : public Figure {
    float xlen, ylen, zlen, angle;

    public: 
    Parallelepiped() : Figure() {
        xlen = 0.0; ylen = 0.0; zlen = 0.0; angle = 90.0;
    }

    Parallelepiped(float ix, float iy, float iz, float ixlen, float iylen, float izlen, float iangle) : Figure(ix,iy,iz) {
        xlen = ixlen; ylen = iylen; zlen = izlen; angle = iangle;
    }

    void input() {
        cout << "Введите стартовую точку параллелепипеда: ";
        cin >> x >> y >> z;
        cout << "Введите длину, ширину и высоту параллелепипеда: ";
        cin >> xlen >> ylen >> zlen;
        cout << "Введите угол между длиной и шириной параллелепипеда: ";
        cin >> angle;
    }

    void output() {
        cout << "точка отсчёта (" << x << ", " << y << ", " << z << "); длина по X " << xlen << "; длина по Y " << ylen << "; длина по Z " << zlen << "; угол " << angle << endl;
    }

    float getArea() {
        float topandbottom = 2 * (xlen * ylen * sin(angle * M_PI / 180.0));
        float sides = 2 * (zlen * xlen + zlen * ylen);
        return topandbottom + sides;
    }

    void stretchZ(float izlen) {
        zlen += izlen;
    }
};

float compareAreas(Figure* f1, Figure* f2) {
    return fabs(f1->getArea() - f2->getArea());
}

int main() {

    setlocale(LC_ALL, "RU");
    Parallelepiped f1, f2;
    cout << "Введите параллелепипед №1: " << endl;
    f1.input();
    cout << "Параллелепипед №1: ";
    f1.output();
    cout << "Введите параллелепипед №2: " << endl;
    f2.input();
    cout << "Параллелепипед №2: ";
    f2.output();
    cout << "Растяните параллелепипед №1 -- введите, на сколько именно: ";
    float temp = 0.0;
    cin >> temp;
    f1.stretchZ(temp);
    cout << "Параллелепипед №1: ";
    f1.output();
    cout << "Разница площадей двух параллелепипедов: " << compareAreas(&f1, &f2) << endl;
    return 0;
}
