#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
class Book {
private:
    std::string author;
    std::string title;
    std::string type; // "Художественная" или "Техническая"
public:
    // Конструктор класса
    Book(const std::string& author, const std::string& title, const std::string& type) 
        : author(author), title(title), type(type) {
        // Проверка на пустые значения
        if (author.empty() || title.empty()) {
            throw std::invalid_argument("The author's name and the book title cannot be empty.");
        }
    }
    // Метод для получения типа книги
    std::string getType() const {
        return type;
    }
    // Метод для отображения информации о книге
    void display() const {
        std::cout << "Author: " << author << ", Name: " << title << ", Type: " << type << std::endl;
    }
};
class Library {
private:
    std::vector<Book> books;
public:
    // Метод для добавления книги в библиотеку
    void addBook(const Book& book) {
        books.push_back(book);
    }
    // Метод для отображения всех книг в библиотеке
    void displayBooks() const {
        if (books.empty()) {
            std::cout << "The library is empty." << std::endl;
            return;
        }
        std::cout << "Books in the library:" << std::endl;
        for (const auto& book : books) {
            book.display();
        }
    }
    // Метод для подсчета количества художественной и технической литературы
    void countBooksByType() const {
        int artisticCount = 0;
        int technicalCount = 0;
        // Подсчет количества книг каждого типа
        for (const auto& book : books) {
            if (book.getType() == "Artistic") {
                artisticCount++;
            } else if (book.getType() == "Technical") {
                technicalCount++;
            }
        }
        // Использование switch для вывода результатов
        std::cout << "Number of books by type:" << std::endl;
        switch (artisticCount) {
            case 0:
                std::cout << "Artistic literature: No books" << std::endl;
                break;
            default:
                std::cout << "Artistic literature: " << artisticCount << " books" << std::endl;
                break;
        }
        switch (technicalCount) {
            case 0:
                std::cout << "Technical literature: No books" << std::endl;
                break;
            default:
                std::cout << "Technical literature: " << technicalCount << " books" << std::endl;
                break;
        }
    }
};
int main() {
    Library library;
    std::string author, title, type;
    while (true) {
        std::cout << "Enter the author's name (or 'exit'): ";
        getline(std::cin, author);
        if (author == "exit") break;
        std::cout << "Enter the name of the book: ";
        getline(std::cin, title);
        if (title.empty()) continue; // Повторить ввод, если название пустое

        std::cout << "Enter the type of book (Artistic/Technical): ";
        getline(std::cin, type);
        if (type != "Artistic" && type != "Technical") {
            std::cout << "Incorrect book type. Try again." << std::endl;
            continue; // Повторить ввод, если тип неверный
        }
        try {
            // Добавление книги в библиотеку
            library.addBook(Book(author, title, type));
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    // Отображение всех книг
    library.displayBooks();
    // Подсчет и вывод количества книг по типу
    library.countBooksByType();
    system("pause");
}
