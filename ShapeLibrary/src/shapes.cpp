#include "../include/shapes.h"

// ---------------- Point ----------------
Point::Point(double x, double y) : x_(x), y_(y) {}

void Point::Draw() const
{
    std::cout << "Point at (" << x_ << ", " << y_ << ")\n";
    Perimeter();
    Area();
}

void Point::Perimeter() const
{
    std::cout << "Perimeter: 0.000\n";
}

void Point::Area() const
{
    std::cout << "Area: 0.000\n";
}

// ---------------- Line ----------------
Line::Line(double x1, double y1, double x2, double y2)
    : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}

void Line::Draw() const
{
    std::cout << "Line from (" << x1_ << ", " << y1_ << ") to (" << x2_ << ", " << y2_ << ")\n";
    Perimeter();
    Area();
}

void Line::Perimeter() const
{
    double length = std::hypot(x2_ - x1_, y2_ - y1_);
    std::cout << "Perimeter: " << std::fixed << std::setprecision(3) << length << "\n";
}

void Line::Area() const
{
    std::cout << "Area: 0.000\n";
}

// ---------------- Rect ----------------
Rect::Rect(double x1, double y1, double x2, double y2)
    : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}

void Rect::Draw() const
{
    std::cout << "Rect with corners (" << x1_ << ", " << y1_ << ") and ("
              << x2_ << ", " << y2_ << ")\n";
    Perimeter();
    Area();
}

void Rect::Perimeter() const
{
    double w = std::abs(x2_ - x1_), h = std::abs(y2_ - y1_);
    std::cout << "Perimeter: " << std::fixed << std::setprecision(3) << 2 * (w + h) << "\n";
}

void Rect::Area() const
{
    double w = std::abs(x2_ - x1_), h = std::abs(y2_ - y1_);
    std::cout << "Area: " << std::fixed << std::setprecision(3) << w * h << "\n";
}

// ---------------- Square ----------------
Square::Square(double x, double y, double side)
    : x_(x), y_(y), side_(side) {}

void Square::Draw() const
{
    std::cout << "Square at (" << x_ << ", " << y_ << "), side = " << side_ << "\n";
    Perimeter();
    Area();
}

void Square::Perimeter() const
{
    std::cout << "Perimeter: " << std::fixed << std::setprecision(3) << 4 * side_ << "\n";
}

void Square::Area() const
{
    std::cout << "Area: " << std::fixed << std::setprecision(3) << side_ * side_ << "\n";
}

// ---------------- Rhomb ----------------
Rhomb::Rhomb(double x, double y, double h, double w)
    : x_(x), y_(y), h_(h), w_(w) {}

void Rhomb::Draw() const
{
    std::cout << "Rhomb at (" << x_ << ", " << y_ << "), height = " << h_ << ", width = " << w_ << "\n";
    Perimeter();
    Area();
}

void Rhomb::Perimeter() const
{
    double side = std::hypot(h_ / 2, w_ / 2);
    std::cout << "Perimeter: " << std::fixed << std::setprecision(3) << 4 * side << "\n";
}

void Rhomb::Area() const
{
    std::cout << "Area: " << std::fixed << std::setprecision(3) << (h_ * w_) / 2 << "\n";
}

// ---------------- Circle ----------------
Circle::Circle(double x, double y, double r)
    : x_(x), y_(y), r_(r) {}

void Circle::Draw() const
{
    std::cout << "Circle at (" << x_ << ", " << y_ << "), radius = " << r_ << "\n";
    Perimeter();
    Area();
}

void Circle::Perimeter() const
{
    std::cout << "Perimeter: " << std::fixed << std::setprecision(3) << 2 * M_PI * r_ << "\n";
}

void Circle::Area() const
{
    std::cout << "Area: " << std::fixed << std::setprecision(3) << M_PI * r_ * r_ << "\n";
}
