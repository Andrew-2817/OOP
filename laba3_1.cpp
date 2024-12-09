#include <iostream>
#include <vector>
#include <memory>

// Базовый класс - деталь
class Detail {
protected:
    std::string name;

    // Защищенный конструктор
    Detail(const std::string& name) : name(name) {}

public:
    virtual ~Detail() = default;
    
    virtual void info() const {
        std::cout << "Detail: " << name << std::endl;
    }
};

// Производный класс - сборка
class Assembly : public Detail {
private:
    std::vector<std::shared_ptr<Detail>> components;

public:
    // Защищенный конструктор
    Assembly(const std::string& name) : Detail(name) {}

    void addComponent(std::shared_ptr<Detail> component) {
        components.push_back(component);
    }

    void info() const override {
        std::cout << "Assembly: " << name << std::endl;
        std::cout << "Components:" << std::endl;
        for (const auto& component : components) {
            component->info();
        }
    }
};

// Шаблонная дружественная функция для добавления объекта в контейнер
template <typename T>
void addToStorage(std::vector<std::shared_ptr<Detail>>& storage, const std::string& name) {
    static_assert(std::is_base_of<Detail, T>::value, "T must be derived from Detail");
    storage.push_back(std::make_shared<T>(name));
}

int main() {
    std::vector<std::shared_ptr<Detail>> storage;

    // Создание деталей и сборок
    addToStorage<Detail>(storage, "Gear");
    addToStorage<Assembly>(storage, "Engine Assembly");
    addToStorage<Detail>(storage, "Bolt");
    addToStorage<Detail>(storage, "Screw");

    // Добавление компонентов в сборку
    dynamic_cast<Assembly*>(storage[1].get())->addComponent(storage[0]); // Adding Gear to Engine Assembly
    dynamic_cast<Assembly*>(storage[1].get())->addComponent(storage[2]); // Adding Bolt to Engine Assembly
    dynamic_cast<Assembly*>(storage[1].get())->addComponent(storage[3]); // Adding Screw to Engine Assembly

    // Вывод информации о всех деталях и сборках
    std::cout << "Stored details and assemblies:\n" << std::endl;
    for (const auto& item : storage) {
        item->info();
    }

    return 0;
}
