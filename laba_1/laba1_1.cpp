#include <iostream>
#include <cstdio>

int main() {
    int n;

    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    // Проверка на корректность ввода
    if (n <= 0) {
        std::cout << "The number of elements must be positive." << std::endl;
        return 1;
    }

    // Выделение памяти под массив
    int* array = new int[n];

    // Заполнение массива
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter the element " << i + 1 << ": ";
        std::cin >> array[i];
    }

    // Вывод содержимого массива и адресов
    std::cout << "\nArray Contents:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Element [" << i << "] = " << array[i] 
                  << ", Address: " << &array[i]
                  << ", Distance from the beginning of the array: " << (&array[i] - array) << std::endl;
    }

    // Адрес начала массива
    std::cout << "\nAddress of the beginning of the array: " << array << std::endl;

    // Освобождение выделенной памяти
    delete[] array;

    system("pause");
}
