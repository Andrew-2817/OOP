#include <iostream>

int main() {
    int n;

    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> n;

    // Проверка на корректность ввода
    if (n <= 0) {
        std::cout << "Количество элементов должно быть положительным." << std::endl;
        return 1;
    }

    // Выделение памяти под массив
    int* array = new int[n];

    // Заполнение массива
    for (int i = 0; i < n; ++i) {
        std::cout << "Введите элемент " << i + 1 << ": ";
        std::cin >> array[i];
    }

    // Вывод содержимого массива и адресов
    std::cout << "\nСодержимое массива:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Элемент [" << i << "] = " << array[i] 
                  << ", Адрес: " << &array[i]
                  << ", Расстояние от начала массива: " << (&array[i] - array) << std::endl;
    }

    // Адрес начала массива
    std::cout << "\nАдрес начала массива: " << array << std::endl;

    // Освобождение выделенной памяти
    delete[] array;

    return 0;
}}
