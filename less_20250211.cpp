#include <iostream>

using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    std::cout << "Программа рисует шахматную доску заданного размера клетки\n";//Сообщаем, что выполняет программа

    int size, rows, cols;//создаем переменные

    std::cout << "Введите целое число для размера шахматной клетки \n"; //просим ввести значение переменной
    std::cin >> size;
    std::cout << "Введите целое число для ширины шахматного поля \n"; //просим ввести значение переменной
    std::cin >> cols;
    std::cout << "Введите целое число для высоты шахматного поля \n"; //просим ввести значение переменной
    std::cin >> rows;
    char white;
    std::cout << "Введите для белых клеток шахматного поля \n";//игровой момент для красоты
    std::cin >> white;
    for (int i = 0; i < rows; i++) //количество повторов в высоту
    {
        for (int h = 0;h < size;h++)// количество символов в высоту
        {
            for (int j = 0; j < cols; j++) //количество повторов в ширину
            {
                for (int k = 0; k < size; k++) //количество символов в ширину
                {
                    //((i + j) & 1) ? (std::cout << ' ') : (std::cout << white);
                    //((i + j) % 2) ? (std::cout << ' ') : (std::cout << white);
                    if ((i + j) % 2) {
                        (std::cout << ' ');
                    }
                    else {
                        (std::cout << white);
                    }
                }
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    system("pause");
}