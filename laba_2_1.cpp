#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication(string t = "", float p = 0.0) : title(t), price(p) {}

    virtual void getdata() {
        cout << "Введите название публикации: ";
        getline(cin, title);
        cout << "Введите цену публикации: ";
        cin >> price;
        cin.ignore(); // игнорируем символ новой строки после ввода цены
    }

    virtual void putdata() const {
        cout << "Название: " << title << ", Цена: " << price << endl;
    }
};

class Book : public Publication {
private:
    int num_pages;

public:
    Book(string t = "", float p = 0.0, int pages = 0) : Publication(t, p), num_pages(pages) {}

    void getdata() override {
        Publication::getdata(); // Получаем данные из родительского класса
        cout << "Введите количество страниц в книге: ";
        cin >> num_pages;
        cin.ignore(); // игнорируем символ новой строки
    }

    void putdata() const override {
        Publication::putdata(); // Выводим данные из родительского класса
        cout << "Количество страниц: " << num_pages << endl;
    }
};

class Audio : public Publication {
private:
    int duration;

public:
    Audio(string t = "", float p = 0.0, int d = 0) : Publication(t, p), duration(d) {}

    void getdata() override {
        Publication::getdata(); // Получаем данные из родительского класса
        cout << "Введите время записи книги в минутах: ";
        cin >> duration;
        cin.ignore(); // игнорируем символ новой строки
    }

    void putdata() const override {
        Publication::putdata(); // Выводим данные из родительского класса
        cout << "Время записи: " << duration << " минут" << endl;
    }
};

int main() {
    Book book;
    book.getdata();
    book.putdata();

    Audio audio;
    audio.getdata();
    audio.putdata();

    return 0;
}
