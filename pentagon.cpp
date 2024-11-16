#include "pentagon.h"

Figure::Point Pentagon::getCenter() const {
    Figure::Point center = {0, 0};
    for (int i = 0; i < 5; ++i) {
        center.x += vertices[i].x;
        center.y += vertices[i].y;
    }
    center.x /= 5.0;
    center.y /= 5.0;
    return center;
}

double Pentagon::getArea() const {
    double area = 0;
    for (int i = 0; i < 5; ++i) {
        int j = (i + 1) % 5;
        area += vertices[i].x * vertices[j].y;
        area -= vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        std::copy(other.vertices, other.vertices + 5, vertices);
    }
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        std::copy(other.vertices, other.vertices + 5, vertices);
    }
    return *this;
}

Figure& Pentagon::operator=(const Figure& other) {
    if (const Pentagon* p = dynamic_cast<const Pentagon*>(&other)) {
        *this = *p;
    }
    return *this;
}

Figure& Pentagon::operator=(Figure&& other) noexcept {
    if (Pentagon* p = dynamic_cast<Pentagon*>(&other)) {
        *this = std::move(*p);
    }
    return *this;
}

bool Pentagon::operator==(const Figure& other) const {
    if (const Pentagon* p = dynamic_cast<const Pentagon*>(&other)) {
        for (int i = 0; i < 5; ++i) {
            if (vertices[i].x != p->vertices[i].x || 
                vertices[i].y != p->vertices[i].y)
                return false;
        }
        return true;
    }
    return false;
}

std::istream& operator>>(std::istream& is, Pentagon& pentagon) {
    for (int i = 0; i < 5; ++i) {
        is >> pentagon.vertices[i].x >> pentagon.vertices[i].y;
    }
    return is;
}

void Pentagon::print(std::ostream& os) const {
    for (int i = 0; i < 5; ++i) {
        os << "(" 
           << vertices[i].x << ", " 
           << vertices[i].y << ")\n";
    }
}