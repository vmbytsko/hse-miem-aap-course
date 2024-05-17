#include <iostream>

using namespace std;

class Dot {
    float x,y,z;

    public:
    Dot() {
        x = 0.0; y = 0.0; z = 0.0;
        cout << "Создана точка с координатами по умолчанию" << endl;
    }
    Dot(float inputx, float inputy, float inputz) {
        x = inputx; y = inputy; z = inputz;
        cout << "Создана точка с координатами (" << x << "; " << y << "; " << z << ")" << endl;
    }
    ~Dot() {
        cout << "Точка удалена" << endl;
    }

    void input() {
        cout << "Введите координаты точки: ";
        cin >> x >> y >> z;
    }

    void output() {
        cout << "Координаты точки: (" << x << "; " << y << "; " << z << ")" << endl;
    }

    float getX() {return x;}
    float getY() {return y;}
    float getZ() {return z;}

    void setX(float inputx) {x = inputx;}
    void setY(float inputy) {y = inputy;}
    void setZ(float inputz) {z = inputz;}
};

class Sphere {
    Dot center;
    float radius;

    public:
    Sphere() {
        center = Dot();
        radius = 1.0;
        cout << "Создана сфера с координатами и радиусом по умолчанию" << endl;
    }
    Sphere(Dot inputcenter, float inputradius) {
        center = inputcenter;
        radius = inputradius;
        cout << "Создана точка с координатами (" << center.getX() << "; " << center.getY() << "; " << center.getZ() << ") и радиусом " << radius << endl;
    }
    ~Sphere() {
        cout << "Сфера удалена" << endl;
    }

    void input() {
        cout << "Введите координаты точки центра координаты:" << endl;
        center.input();
        cout << "Введите радиус: ";
        cin >> radius;
    }

    void output() {
        cout << "Сфера с координатами центра (" << center.getX() << "; " << center.getY() << "; " << center.getZ() << ") и радиусом " << radius << endl;
    }

    int isOnSphere(Dot checkDot) {
        float x = checkDot.getX(), y = checkDot.getY(), z = checkDot.getZ();
        return (x*x + y*y + z*z == radius*radius);
    }

    float getRadius() {return radius;}
    void setRadius(float inputradius) {radius = inputradius;}
};

int isOnSphere(Sphere checkSphere, Dot checkDot) {
    float x = checkDot.getX(), y = checkDot.getY(), z = checkDot.getZ(), radius = checkSphere.getRadius();
    return (x*x + y*y + z*z == radius*radius);
}

int main() {
    Sphere sphere = Sphere();
    sphere.input();
    cout << "Введите точку, которую надо проверить на принадлежность к сфере:" << endl;
    Dot checkDot = Dot();
    checkDot.input();
    if(sphere.isOnSphere(checkDot)) {
        cout << "Точка на сфере." << endl;
    } else {
        cout << "Точка НЕ на сфере." << endl;
    }
    return 0;
}
