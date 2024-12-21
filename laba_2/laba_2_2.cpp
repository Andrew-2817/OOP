#include <iostream>
#include <string>
#include <cstdio>

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
            cout << "Enter the total cost of books sold per month " << (i + 1) << ": ";
            cin >> salesData[i];
        }
        cin.ignore(); // Игнорируем символ новой строки после ввода
    }

    void putSalesData() const {
        for (int i = 0; i < 3; ++i) {
            cout << "Monthly sales " << (i + 1) << ": " << salesData[i] << endl;
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
        cout << "Enter the title of the publication: ";
        getline(cin, title);
        cout << "Enter the publication price: ";
        cin >> price;
        cin.ignore(); // Игнорируем символ новой строки после ввода цены
    }

    virtual void putdata() const {
        cout << "Name: " << title << ", Price: " << price << endl;
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
        cout << "Enter the number of pages in the book: ";
        cin >> num_pages;
        cin.ignore(); // Игнорируем символ новой строки
        getSalesData(); // Получаем данные о продажах
    }

    void putdata() const override {
        Publication::putdata(); // Выводим данные из родительского класса
        cout << "Number of pages: " << num_pages << endl;
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
        cout << "Enter the book recording time in minutes: ";
        cin >> duration;
        cin.ignore(); // Игнорируем символ новой строки
        getSalesData(); // Получаем данные о продажах
    }

    void putdata() const override {
        Publication::putdata(); // Выводим данные из родительского класса
        cout << "recording time: " << duration << " minutes" << endl;
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

    system("pause");
}
