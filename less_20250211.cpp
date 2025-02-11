#include <iostream>

// Прототипы
void gen_array(int**, int, int);
void gen_array(int*, int);
void print_array(int**, int, int);

void delete_array(int**, int);

int** create_array(int, int);

int* find_key(int**, int, int, int);

int** resize_row(int**, int, int);

int* resize_col(int*, int);
void resize_col(int**, int, int);

void swap_row(int**, int, int, int);

void gen_array(int* arr, int size) {
    for (int j = 0; j < size; j++) {
        arr[j] = rand() % 101;
    }
}


void gen_array(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        gen_array(arr[i], col);
    }
}

void print_array(int** arr, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void delete_array(int** arr, int row) {
    // Удалим строки
    for (int i = 0; i < row; i++)
        delete[] arr[i];

    // Удалим массив указателей
    delete[] arr;
}

int** create_array(int row, int col) {
    //Выделим память для хранения массива указателей
    int** arr = new int* [row];

    std::cout << sizeof(arr) << std::endl;

    //Выделим память для хранения каждой строки
    for (int i = 0; i < row; i++)
        arr[i] = new int[col] {};

    return arr;
}

int* find_key(int** arr, int row, int col, int key) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == key)
                return &(arr[i][j]);
        }
    }
    return nullptr;
}

int** resize_row(int** arr, int row, int col) {
    // Выделили новую память
    int** new_arr = new int* [row + 1];

    // Скопировали указатели
    for (int i = 0; i < row; i++)
        new_arr[i] = arr[i];

    // Выделили память для новой строки
    new_arr[row] = new int[col] {};

    // Запонили новую строку случайными числами
   /* for (int j = 0; j < col; j++) {
        new_arr[row][j] = rand() % 101;
    }*/

    gen_array(new_arr[row], col);

    delete[] arr;
    // Вернули новый массив
    return new_arr;
}

int* resize_col(int* arr, int size) {

    int* new_arr = new int [size + 1] {};

    for (int i = 0; i < size; i++)
        new_arr[i] = arr[i];

    delete[] arr;

    return new_arr;

}

void resize_col(int** arr, int row, int col) {

    for (int i = 0; i < row; i++)
        arr[i] = resize_col(arr[i], col);
}

void swap_row(int** arr, int row, int ind1, int ind2) {

    if (!(ind1 >= 0 && ind1 < row && ind2 >= 0 && ind2 < row))
        return;

    int* t = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = t;

}

int main()
{
    using namespace std;
    srand(time(NULL));

    int row = 10;
    int col = 10;

    int** arr = create_array(row, col);
    gen_array(arr, row, col);
    print_array(arr, row, col);


    swap_row(arr, row, 11, 12);

    std::cout << "\n\n\n";
    print_array(arr, row, col);

    //arr = resize_row(arr, row, col);
    //row++;

    /*resize_col(arr, row, col);
    col++;

    std::cout << "\n\n\n";
    print_array(arr, row, col);*/

    //int key;
    //std::cout << "Enter find key ";
    //std::cin >> key;

    //int* find_element = find_key(arr, row, col, key);

    //if (find_element) {
    //    std::cout << " Key found!" << std::endl;
    //    int new_val;
    //    std::cout << "Enter new value ";
    //    std::cin >> new_val;
    //    *find_element = new_val;
    //}
    //else
    //    std::cout << " Key NOT found!" << std::endl;

    ///*if (find_key(arr, row, col, key))
    //    std::cout << " Key found!" << std::endl;
    //else
    //    std::cout << " Key NOT found!" << std::endl;*/


    //print_array(arr, row, col);

    delete_array(arr, row);

}
