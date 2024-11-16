#include "hexagon.h"

Figure::Point Hexagon::getCenter() const {
    Figure::Point center = {0, 0};
    for (int i = 0; i < 6; ++i) {
        center.x += vertices[i].x;
        center.y += vertices[i].y;
    }
    center.x /= 6.0;
    center.y /= 6.0;
    return center;
}

double Hexagon::getArea() const {
    double area = 0;
    for (int i = 0; i < 6; ++i) {
        int j = (i + 1) % 6;
        area += vertices[i].x * vertices[j].y;
        area -= vertices[j].x * vertices[i].y;
    }
    return std::abs(area) / 2.0;
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        std::copy(other.vertices, other.vertices + 6, vertices);
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        std::copy(other.vertices, other.vertices + 6, vertices);
    }
    return *this;
}

Figure& Hexagon::operator=(const Figure& other) {
    if (const Hexagon* h = dynamic_cast<const Hexagon*>(&other)) {
        *this = *h;
    }
    return *this;
}

Figure& Hexagon::operator=(Figure&& other) noexcept {
    if (Hexagon* h = dynamic_cast<Hexagon*>(&other)) {
        *this = std::move(*h);
    }
    return *this;
}

bool Hexagon::operator==(const Figure& other) const {
    if (const Hexagon* h = dynamic_cast<const Hexagon*>(&other)) {
        for (int i = 0; i < 6; ++i) {
            if (vertices[i].x != h->vertices[i].x || 
                vertices[i].y != h->vertices[i].y)
                return false;
        }
        return true;
    }
    return false;
}

std::istream& operator>>(std::istream& is, Hexagon& hexagon) {
    for (int i = 0; i < 6; ++i) {
        is >> hexagon.vertices[i].x >> hexagon.vertices[i].y;
    }
    return is;
}

void Hexagon::print(std::ostream& os) const {
    for (int i = 0; i < 6; ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")\n";
    }
}