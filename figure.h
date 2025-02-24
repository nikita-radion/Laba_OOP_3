#pragma once
#include <iostream>

class Figure {
protected:
    struct Point {
        double x, y;
    };

public:
    virtual ~Figure() = default;
    
    virtual Point getCenter() const = 0;
    
    virtual double getArea() const = 0;
    
    virtual bool operator==(const Figure& other) const = 0;
    virtual Figure& operator=(const Figure& other) = 0;
    virtual Figure& operator=(Figure&& other) noexcept = 0;

    virtual void print(std::ostream& os) const = 0;

    friend std::istream& operator>>(std::istream& is, Figure& fig);
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.print(os);
        return os;
    };

    operator double() const { return getArea(); }
};