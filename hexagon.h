#pragma once
#include "figure.h"
#include <cmath>

class Hexagon : public Figure {
private:
    Point vertices[6];

public:
    Hexagon() = default;
    
    Point getCenter() const override;
    double getArea() const override;
    
    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;
    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) noexcept override;
    bool operator==(const Figure& other) const override;
    
    friend std::istream& operator>>(std::istream& is, Hexagon& hexagon);
    friend std::ostream& operator<<(std::ostream& os, const Hexagon& hexagon);

    void print(std::ostream& os) const override;
};