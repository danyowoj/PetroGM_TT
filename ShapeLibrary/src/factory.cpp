#include "../include/shapes.h"
#include <sstream>
#include <unordered_map>

Shape *ShapeFactory::createShape(const std::string &line)
{
    std::istringstream iss(line);
    std::string type;
    if (!(iss >> type))
        return nullptr;

    for (auto &c : type)
        c = std::tolower(c);

    if (type == "point")
    {
        double x, y;
        if (iss >> x >> y)
            return new Point(x, y);
    }
    else if (type == "line")
    {
        double x1, y1, x2, y2;
        if (iss >> x1 >> y1 >> x2 >> y2)
            return new Line(x1, y1, x2, y2);
    }
    else if (type == "rect")
    {
        double x1, y1, x2, y2;
        if (iss >> x1 >> y1 >> x2 >> y2)
            return new Rect(x1, y1, x2, y2);
    }
    else if (type == "square")
    {
        double x, y, s;
        if (iss >> x >> y >> s)
            return new Square(x, y, s);
    }
    else if (type == "rhomb")
    {
        double x, y, h, w;
        if (iss >> x >> y >> h >> w)
            return new Rhomb(x, y, h, w);
    }
    else if (type == "circle")
    {
        double x, y, r;
        if (iss >> x >> y >> r)
            return new Circle(x, y, r);
    }

    return nullptr;
}
