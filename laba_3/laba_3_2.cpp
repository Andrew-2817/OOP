#include <iostream>
#include <vector>
#include <memory>

// Базовый класс - транспортное средство
class Vehicle {
protected:
    std::string make;
    std::string model;

    // Защищенный конструктор
    Vehicle(const std::string& make, const std::string& model) 
        : make(make), model(model) {}

public:
    virtual ~Vehicle() = default;

    virtual void info() const {
        std::cout << "Vehicle Make: " << make << ", Model: " << model << std::endl;
    }
};

// Производный класс - легковой автомобиль
class Car : public Vehicle {
public:
    Car(const std::string& make, const std::string& model)
        : Vehicle(make, model) {}

    void info() const override {
        std::cout << "Car Make: " << make << ", Model: " << model << std::endl;
    }
};

// Производный класс - грузовик
class Truck : public Vehicle {
public:
    Truck(const std::string& make, const std::string& model)
        : Vehicle(make, model) {}

    void info() const override {
        std::cout << "Truck Make: " << make << ", Model: " << model << std::endl;
    }
};

// Производный класс - мотоцикл
class Motorcycle : public Vehicle {
public:
    Motorcycle(const std::string& make, const std::string& model)
        : Vehicle(make, model) {}

    void info() const override {
        std::cout << "Motorcycle Make: " << make << ", Model: " << model << std::endl;
    }
};

// Шаблонная функция для добавления объекта в гараж
template <typename T>
void addToGarage(std::vector<std::shared_ptr<Vehicle>>& garage, const std::string& make, const std::string& model) {
    static_assert(std::is_base_of<Vehicle, T>::value, "T must be derived from Vehicle");
    garage.push_back(std::make_shared<T>(make, model));
}

int main() {
    std::vector<std::shared_ptr<Vehicle>> garage;

    // Добавление различных транспортных средств в гараж
    addToGarage<Car>(garage, "Toyota", "Camry");
    addToGarage<Truck>(garage, "Ford", "F-150");
    addToGarage<Motorcycle>(garage, "Harley-Davidson", "Sportster");

    // Вывод информации о всех транспортных средствах в гараже
    std::cout << "Vehicles in the garage:\n" << std::endl;
    for (const auto& vehicle : garage) {
        vehicle->info();
    }

    return 0;
}
