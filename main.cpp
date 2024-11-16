#include <iostream>
#include <vector>
#include <memory>
#include "hexagon.h"
#include "octagon.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;

    auto hexagon = std::make_unique<Hexagon>();
    std::cout << "Введите координаты 6 вершин шестиугольника (x y):\n";
    std::cin >> *hexagon;
    figures.push_back(std::move(hexagon));

    auto octagon = std::make_unique<Octagon>();
    std::cout << "Введите координаты 8 вершин восьмиугольника (x y):\n";
    std::cin >> *octagon;
    figures.push_back(std::move(octagon));

    std::cout << "\n1. Геометрические центры фигур:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        auto center = figures[i]->getCenter();
        std::cout << "Фигура " << i + 1 << ": (" 
                 << center.x << ", " << center.y << ")\n";
    }

    std::cout << "\n2. Координаты вершин фигур:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Фигура " << i + 1 << ":\n" << *figures[i];
    }

    std::cout << "\n3. Площади фигур:\n";
    double totalArea = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        double area = static_cast<double>(*figures[i]);
        std::cout << "Фигура " << i + 1 << ": " << area << "\n";
        totalArea += area;
    }
    std::cout << "Общая площадь: " << totalArea << "\n";

    std::cout << "\n4. Удаление фигуры по индексу\n";
    size_t index = 0;
    figures.erase(figures.begin() + index);
    std::cout << "Фигура " << index + 1 << " удалена\n";

    return 0;
}