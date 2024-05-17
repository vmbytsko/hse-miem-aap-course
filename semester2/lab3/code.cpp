#include <iostream>
#include <limits.h>

using namespace std;

class Array {

    int size;
    int* data;

    public:
    Array() {
        size = 0;
        data = nullptr;
    }
    Array(int n, int a) {
        size = n;
        data = new int[size];
        for(int i = 0; i < size; i++) data[i] = a;
    }

    ~Array() {
        delete[] data;
    }

    void input() {
        cout << "Введите размер массива: ";
        cin >> size;
        delete[] data;
        data = new int[size];
        cout << "Введите массив: ";
        for(int i = 0; i < size; i++) cin >> data[i];
    }

    void output() {
        cout << "Массив: ";
        for(int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }

    int* findAnswer(int lastn) {
        int equalsZero = 0;
        int lessThanZero = 0;
        int* answer = new int[2];
        for(int i = (int)((size - 1) / 2) * 2; i >= size-(lastn*2) && i >= 0; i-=2) {
            if(data[i] == 0) equalsZero++;
            if(data[i] < 0) lessThanZero++;
        }
        answer[0] = equalsZero;
        answer[1] = lessThanZero;
        return answer;
    }
};

int main() {

    Array arr = Array(10, 0);
    arr.output();
    arr.input();
    arr.output();
    cout << "Введите количество последних n нечётных элементов: ";
    int n;
    cin >> n;
    int* answer = arr.findAnswer(n);

    cout << "Равное нулю: " << answer[0] << ", меньше нуля: " << answer[1] << endl;
    delete[] answer;
    return 0;
}
