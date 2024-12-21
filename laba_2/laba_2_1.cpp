#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

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
        cin.ignore(); // игнорируем символ новой строки после ввода цены
    }

    virtual void putdata() const {
        cout << "title: " << title << ", price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int num_pages;

public:
    Book(string t = "", float p = 0.0, int pages = 0) : Publication(t, p), num_pages(pages) {}

    void getdata() override {
        Publication::getdata(); // Получаем данные из родительского класса
        cout << "Enter the number of pages in the book: ";
        cin >> num_pages;
        cin.ignore(); // игнорируем символ новой строки
    }

    void putdata() const override {
        Publication::putdata(); // Выводим данные из родительского класса
        cout << "number of pages: " << num_pages << endl;
    }
};

class Audio : public Publication {
private:
    int duration;

public:
    Audio(string t = "", float p = 0.0, int d = 0) : Publication(t, p), duration(d) {}

    void getdata() override {
        Publication::getdata(); // Получаем данные из родительского класса
        cout << "Enter the book recording time in minutes: ";
        cin >> duration;
        cin.ignore(); // игнорируем символ новой строки
    }

    void putdata() const override {
        Publication::putdata(); // Выводим данные из родительского класса
        cout << "recording time: " << duration << " minutes" << endl;
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
