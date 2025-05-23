#ifndef SHAPES_H
#define SHAPES_H

#ifdef _WIN32
#ifdef SHAPE_EXPORTS
#define SHAPE_API __declspec(dllexport)
#else
#define SHAPE_API __declspec(dllimport)
#endif
#else
#define SHAPE_API
#endif

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

class SHAPE_API Shape
{
public:
    virtual ~Shape() {}
    virtual void Draw() const = 0;
    virtual void Perimeter() const = 0;
    virtual void Area() const = 0;
};

class SHAPE_API Point : public Shape
{
    double x_, y_;

public:
    Point(double x, double y);
    void Draw() const override;
    void Perimeter() const override;
    void Area() const override;
};

class SHAPE_API Line : public Shape
{
    double x1_, y1_, x2_, y2_;

public:
    Line(double x1, double y1, double x2, double y2);
    void Draw() const override;
    void Perimeter() const override;
    void Area() const override;
};

class SHAPE_API Rect : public Shape
{
    double x1_, y1_, x2_, y2_;

public:
    Rect(double x1, double y1, double x2, double y2);
    void Draw() const override;
    void Perimeter() const override;
    void Area() const override;
};

class SHAPE_API Square : public Shape
{
    double x_, y_, side_;

public:
    Square(double x, double y, double side);
    void Draw() const override;
    void Perimeter() const override;
    void Area() const override;
};

class SHAPE_API Rhomb : public Shape
{
    double x_, y_, h_, w_;

public:
    Rhomb(double x, double y, double h, double w);
    void Draw() const override;
    void Perimeter() const override;
    void Area() const override;
};

class SHAPE_API Circle : public Shape
{
    double x_, y_, r_;

public:
    Circle(double x, double y, double r);
    void Draw() const override;
    void Perimeter() const override;
    void Area() const override;
};

class SHAPE_API ShapeFactory
{
public:
    static Shape *createShape(const std::string &line);
};

#endif
