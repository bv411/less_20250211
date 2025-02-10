#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

template <typename T>
void printM(T*, int);
template <typename T>
void printM(T**, int, int);
template <typename T>
void genM(T*, int);
template <typename T>
void genM(T**, int, int);

template <typename T>
void delM(T**, int);

template <typename T>
void delM(T*);

template <typename T>
T* resizeM(T*, int, int);

template <typename T>
T** resize_row(T**, int, int, int);
template <typename T>
void resize_col(T**, int, int, int);

int main() {

    int row = 10;
    int col = 10;

    int** mass = new int* [row];
    for (int i = 0; i < row; i++)
        mass[i] = new int[col] {};

    genM(mass, row, col);
    printM(mass, row, col);
    mass = resize_row(mass, row, row + 1, col);
    cout << "------------------------------------------------------------" << endl;
    printM(mass, row + 1, col);

    resize_col(mass, row + 1, col, col + 1);
    cout << "------------------------------------------------------------" << endl;
    printM(mass, row + 1, col + 1);

    /*for (int i = 0; i < row; i++)
        delete[] mass[i];
    delete[] mass;*/
    delM(mass, row);

    return 0;
}

template <typename T>
void printM(T* m, int s) {
    for (int i = 0; i < s; i++)
        cout << m[i] << "\t";
}

template <typename T>
void printM(T** m, int r, int c) {
    for (int i = 0; i < r; i++) {
        printM(m[i], c);
        cout << endl;
    }
}

template <typename T>
void genM(T* m, int s) {
    for (int i = 0; i < s; i++)
        m[i] = rand() % 100;
}

template <typename T>
void genM(T** m, int r, int c) {
    for (int i = 0; i < r; i++)
        genM(m[i], c);
}

template <typename T>
void delM(T* m) {
    delete[] m;
}

template <typename T>
void delM(T** m, int r) {
    for (int i = 0; i < r; i++)
        delM(m[i]);
    delete m;
}

template <typename T>
T* resizeM(T* m, int s, int n_s) {
    T* nm = new T[n_s]{};
    for (int i = 0; i < n_s && i < s; i++)
        nm[i] = m[i];

    delete[]m;
    return nm;
}

template <typename T>
T** resize_row(T** m, int s, int n_s, int col) {
    T** nm = new T * [n_s];
    for (int i = 0; i < n_s && i < s; i++)
        nm[i] = m[i];
    if (n_s > s)
        for (int i = s; i < n_s; i++)
            nm[i] = new T[col]{};

    delete[]m;
    return nm;
}

template <typename T>
void resize_col(T** m, int s, int col, int new_col) {
    for (int i = 0; i < s; i++)
        m[i] = resizeM(m[i], col, new_col);
}