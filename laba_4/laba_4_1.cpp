#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>

// Базовый класс для ошибок
class Error {
public:
    virtual const char* what() const noexcept = 0;
};

// Ошибка в программе
class PointerError : public Error {
public:
    const char* what() const noexcept override {
        return "Ошибка: некорректный указатель!";
    }
};

// Ошибка работы со списком
class ListError : public Error {
public:
    const char* what() const noexcept override {
        return "Ошибка: проблема с работой со списком!";
    }
};

// Недопустимый индекс
class InvalidIndexError : public Error {
public:
    const char* what() const noexcept override {
        return "Ошибка: недопустимый индекс!";
    }
};

// Список переполнен
class ListOverflowError : public Error {
public:
    const char* what() const noexcept override {
        return "Ошибка: список переполнен!";
    }
};

// Шаблонный класс для хранения массива указателей
template<typename T>
class PointerArray {
private:
    std::vector<T*> pointers;

public:
    void add(T* ptr) {
        if (pointers.size() >= 100) { // Ограничиваем размер массива
            throw ListOverflowError();
        }
        pointers.push_back(ptr);
    }

    T* operator[](std::size_t index) {
        if (index < 0 || index >= pointers.size()) {
            throw InvalidIndexError();
        }
        return pointers[index];
    }

    std::size_t size() const {
        return pointers.size();
    }
};

// Пример класса с помощью которого будем работать
class Sample {
public:
    void display() const {
        std::cout << "Объект Sample" << std::endl;
    }
};

int main() {
    try {
        PointerArray<Sample> arr;

        // Добавление объектов в массив
        for (int i = 0; i < 5; ++i) {
            arr.add(new Sample());
        }

        // Использование перегруженного оператора []
        for (std::size_t i = 0; i < arr.size(); ++i) {
            arr[i]->display();
        }

        // Проверка на ошибку с недопустимым индексом
        arr[5]; // Это вызовет InvalidIndexError

    } catch (const Error& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Стандартная ошибка: " << e.what() << std::endl;
    }

    return 0;
}