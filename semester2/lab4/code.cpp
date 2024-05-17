#include <iostream>

using namespace std;

class Array {
    int elements[5];

    public:
    Array() {
        for(int i = 0; i < 5; i++) elements[i] = 0;
    }

    Array(int value) {
        for(int i = 0; i < 5; i++) elements[i] = value;
    }

    ~Array() {
    }

    friend istream& operator>>(istream&, Array&);
    friend ostream& operator<<(ostream&, Array&);
    friend Array operator-(Array arr);

    Array operator*=(int value) {
        for(int i = 0; i < 5; i++) elements[i] = elements[i] * value;
        return *this;
    }
};

istream& operator>> (istream& s, Array& A) {
    for (int i=0; i<5; i++) s >> A.elements[i];
    return s;
}

ostream& operator<< (ostream& s, Array& A){
    s<< "[ ";
    for (int i=0; i<5; i++) s << A.elements[i] << " ";
    return s << "]" << endl;
}

Array operator-(Array arr) {
    Array answer;
    for(int i = 0; i < 5; i++) answer.elements[i] = -arr.elements[i];
    return answer;
}

int main() {

    Array arr;

    cout << "Введите массив: ";
    cin >> arr;
    cout << arr;

    int temp;
    cout << "Введите, на какое число умножить массив: ";
    cin >> temp;
    arr*=temp;
    cout << arr;

    arr=-arr;
    cout << arr;

    return 0;
}
