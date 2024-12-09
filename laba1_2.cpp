#include <iostream>
#include <vector>
#include <string>
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
            throw std::invalid_argument("Имя автора и название книги не могут быть пустыми.");
        }
    }
    // Метод для получения типа книги
    std::string getType() const {
        return type;
    }
    // Метод для отображения информации о книге
    void display() const {
        std::cout << "Автор: " << author << ", Название: " << title << ", Тип: " << type << std::endl;
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
            std::cout << "Библиотека пуста." << std::endl;
            return;
        }
        std::cout << "Книги в библиотеке:" << std::endl;
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
            if (book.getType() == "Художественная") {
                artisticCount++;
            } else if (book.getType() == "Техническая") {
                technicalCount++;
            }
        }
        // Использование switch для вывода результатов
        std::cout << "Количество книг по типу:" << std::endl;
        switch (artisticCount) {
            case 0:
                std::cout << "Художественная литература: Нет книг" << std::endl;
                break;
            default:
                std::cout << "Художественная литература: " << artisticCount << " книг" << std::endl;
                break;
        }
        switch (technicalCount) {
            case 0:
                std::cout << "Техническая литература: Нет книг" << std::endl;
                break;
            default:
                std::cout << "Техническая литература: " << technicalCount << " книг" << std::endl;
                break;
        }
    }
};
int main() {
    Library library;
    std::string author, title, type;
    while (true) {
        std::cout << "Введите имя автора (или 'exit' для выхода): ";
        getline(std::cin, author);
        if (author == "exit") break;
        std::cout << "Введите название книги: ";
        getline(std::cin, title);
        if (title.empty()) continue; // Повторить ввод, если название пустое

        std::cout << "Введите тип книги (Художественная/Техническая): ";
        getline(std::cin, type);
        if (type != "Художественная" && type != "Техническая") {
            std::cout << "Неверный тип книги. Попробуйте снова." << std::endl;
            continue; // Повторить ввод, если тип неверный
        }
        try {
            // Добавление книги в библиотеку
            library.addBook(Book(author, title, type));
        } catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }
    // Отображение всех книг
    library.displayBooks();
    // Подсчет и вывод количества книг по типу
    library.countBooksByType();
    return 0;
}
