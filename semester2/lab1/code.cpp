// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <limits.h>
using namespace std;
struct matrix {
	int n, m;
	float** data;
};

void input(matrix *mt);
void output(matrix mt);
float* tostr(matrix mt);
float sum(matrix mt, int column);
float* search(float* arr, int n);

int _tmain(int argc, _TCHAR* argv[])
{
	matrix mt;
	input(&mt);
	output(mt);
	float* arr = tostr(mt);
	for (int i = 0; i < mt.n * mt.m; i++) {
		cout << arr[i] << " ";
	}

	int column = -1;
	do {
		cout << endl << "Enter the column: ";
		cin >> column;
	} while (column < 0 || column >= mt.m);
	cout << "The sum of the column is " << sum(mt, column) << endl;

	float* answer = search(arr, mt.n * mt.m);
	cout << "The min value is " << answer[0] << "; its index is " << (int)answer[1] << endl;

	for (int i = 0; i < mt.n; i++) delete[] mt.data[i];
	delete[] mt.data;

	system("pause");
	return 0;
}

void input(matrix *mt) {
	cout << "Enter the size of the matrix: ";
	cin >> mt->n >> mt->m;
	cout << "Enter matrix:" << endl;
	mt->data = new float*[mt->n];
	for (int i = 0; i < mt->n; i++) {
		mt->data[i] = new float[mt->m];
		for (int j = 0; j < mt->m; j++) {
			cin >> mt->data[i][j];
		}
	}
}

void output(matrix mt) {
	cout << "Your matrix is:" << endl;
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.m; j++) {
			cout << mt.data[i][j] << " ";
		}
		cout << endl;
	}
}

float* tostr(matrix mt) {
	float* arr = new float[mt.n*mt.m];
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.m; j++) {
			arr[i*mt.m + j] = mt.data[i][j];
		}
	}
	return arr;
}

float sum(matrix mt, int column) {
	float s = 0.0;
	for (int i = 0; i < mt.n; i++) {
		s += mt.data[i][column];
	}
	return s;
}

float* search(float* arr, int n) {
	float min = INFINITY;
	int index = -1;
	for (int i = 1; i < n; i += 2) {
		if (min >= arr[i]) {
			min = arr[i];
			index = i;
		}
	}

	float* answer = new float[2];
	answer[0] = min;
	answer[1] = (float)index;
	return answer;
}
