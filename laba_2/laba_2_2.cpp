#include <iostream>
#include <string>

using namespace std;

class Sales {
protected:
    float salesData[3]; 

public:
    Sales() {
        for (int i = 0; i < 3; ++i) {
            salesData[i] = 0.0;
        }
    }

    void getSalesData() {
        for (int i = 0; i < 3; ++i) {
            cout << "Введите общую стоимость проданных книг за месяц " << (i + 1) << ": ";
            cin >> salesData[i];
        }
        cin.ignore(); // Игнорируем символ новой строки после ввода
    }

    void putSalesData() const {
        for (int i = 0; i < 3; ++i) {
            cout << "Продажи за месяц " << (i + 1) << ": " << salesData[i] << endl;
        }
    }
};

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
        cin.ignore(); // Игнорируем символ новой строки после ввода цены
    }

    virtual void putdata() const {
        cout << "Название: " << title << ", Цена: " << price << endl;
    }
};

class Book : public Publication, public Sales {
private:
    int num_pages;

public:
    Book(string t = "", float p = 0.0, int pages = 0) 
        : Publication(t, p), Sales(), num_pages(pages) {}

    void getdata() override {
        Publication::getdata(); // Получаем данные из родительского класса
        cout << "Введите количество страниц в книге: ";
        cin >> num_pages;
        cin.ignore(); // Игнорируем символ новой строки
        getSalesData(); // Получаем данные о продажах
    }

    void putdata() const override {
        Publication::putdata(); // Выводим данные из родительского класса
        cout << "Количество страниц: " << num_pages << endl;
        putSalesData(); // Выводим данные о продажах
    }
};

class Audio : public Publication, public Sales {
private:
    int duration;

public:
    Audio(string t = "", float p = 0.0, int d = 0) 
        : Publication(t, p), Sales(), duration(d) {}

    void getdata() override {
        Publication::getdata(); // Получаем данные из родительского класса
        cout << "Введите время записи книги в минутах: ";
        cin >> duration;
        cin.ignore(); // Игнорируем символ новой строки
        getSalesData(); // Получаем данные о продажах
    }

    void putdata() const override {
        Publication::putdata(); // Выводим данные из родительского класса
        cout << "Время записи: " << duration << " минут" << endl;
        putSalesData(); // Выводим данные о продажах
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
