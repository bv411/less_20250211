#include <iostream>
using namespace std;

int pow_rec(int a, int b) {
    if (b == 0)
        return 1;
    return pow_rec(a, b - 1) * a;
}

void print_rec(int a) {
    cout << a << endl;
    if (a == 0)
        return;
    print_rec(a - 1);
}


void print_rec2(int a) {
    if (a == 0)
        return;

    print_rec2(a - 1);

    cout << a << endl;
}


int main77() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    //cout << pow_rec(2, 3) << endl;
    print_rec2(10);

    return 0;

}


void foo() {
    foo();
}

void foo1(int i) {
    cout << i << endl;
    if (i == 10)
        return;
    foo1(++i);
}



int foo2(int i) {
    if (i < 1)
        return 0;
    i--;
    cout << i << endl;
    return foo2(i);
    //return foo2(i)+i;
}


void printArray(int a[], int ind, int rows) {
    cout << a[ind] << " ";
    ind++;
    if (ind == rows)
        return;
    printArray(a, ind, rows);
}

// Рекурсия.
int main2() {
    srand(time(NULL));
    //foo1(1);

    //foo2(10);
    int res = foo2(10);
    cout << "\nRes foo2() = " << res << endl;

    //int a[] = {1,2,3,4,5,6,7,8,9};

    //printArray (a , 0,sizeof (a)/4);

    return 0;
}




// Быстрая сортировка
void quicksort(int mas[], int first, int last) {

    int mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2];
    do {
        while (mas[f] < mid) f++;
        while (mas[l] > mid) l--;

        if (f <= l) {
            swap(mas[f], mas[l]);
            f++;
            l--;
        }
    } while (f < l);

    if (first < l) quicksort(mas, first, l);
    if (f < last) quicksort(mas, f, last);
}

int main99() {
    srand(time(NULL));
    const long SIZE = 10;
    int ar[SIZE];

    for (int i = 0; i < SIZE; i++) {
        ar[i] = rand() % 100;
        cout << ar[i] << "\t";
    }
    cout << "\n\n";

    quicksort(ar, 0, SIZE - 1);
    for (int i = 0; i < SIZE; i++) {
        cout << ar[i] << "\t";
    }

    cout << "\n\n";

    return 0;
}

int BinarySearch(int A[], int Lb, int Rb, int Key) {
    int M;
    while (true) {
        M = (Lb + Rb) / 2;
        if (Key < A[M])
            Rb = M - 1;
        else
            if (Key > A[M])
                Lb = M + 1;
            else
                return M;
        if (Lb > Rb)
            return -1;
    }
}

int BinarySearch2(int A[], int Lb, int Rb, int Key) {

    if (Lb > Rb)
        return -1;

    int M = (Lb + Rb) / 2;

    if (Key < A[M])
        return BinarySearch2(A, Lb, M - 1, Key);

    if (Key > A[M])
        return BinarySearch2(A, M + 1, Rb, Key);

    return M;
}


int main_11() {
    srand(time(NULL));
    const long SIZE = 10;
    int ar[SIZE];
    int key, ind;
    // до сортировки
    for (int i = 0; i < SIZE; i++) {
        ar[i] = rand() % 100;
        cout << ar[i] << "\t";
    }
    cout << "\n\n";
    quicksort(ar, 0, SIZE - 1);

    //после сортировки
    for (int i = 0; i < SIZE; i++) {
        cout << ar[i] << "\t";
    }
    cout << "\n\n";
    cout << "Enter any digit:";
    cin >> key;
    ind = BinarySearch2(ar, 0, SIZE, key);
    cout << "Index - " << ind << "\t"; cout << "\n\n";
    return 0;
}






