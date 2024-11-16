#pragma once
#include "figure.h"
#include <cmath>

class Pentagon : public Figure {
private:
    Point vertices[5];

public:
    Pentagon() = default;
    
    Point getCenter() const override;
    double getArea() const override;
    
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) noexcept override;
    bool operator==(const Figure& other) const override;
    
    friend std::istream& operator>>(std::istream& is, Pentagon& pentagon);
    friend std::ostream& operator<<(std::ostream& os, const Pentagon& pentagon);

    void print(std::ostream& os) const override;
};