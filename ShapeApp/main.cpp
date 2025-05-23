#include "shapes.h"
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    // Проверка: ожидаем, что имя входного файла передано как аргумент
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file.txt>" << std::endl;
        return 1;
    }

    const char *filename = argv[1];
    std::ifstream infile(filename);
    if (!infile.is_open())
    {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return 1;
    }

    std::vector<Shape *> shapes;
    std::string line;
    size_t lineNumber = 0;
    while (std::getline(infile, line))
    {
        lineNumber++;
        // Пропускаем пустые строки
        if (line.find_first_not_of(" \t\r\n") == std::string::npos)
        {
            continue;
        }

        Shape *shp = ShapeFactory::createShape(line);
        if (shp != nullptr)
        {
            shapes.push_back(shp);
        }
        else
        {
            std::cerr << "Warning: cannot parse line " << lineNumber << ": \""
                      << line << "\"" << std::endl;
        }
    }

    for (const Shape *shape : shapes)
    {
        shape->Draw();
        std::cout << std::endl;
    }

    // Освобождаем память
    for (Shape *shp : shapes)
    {
        delete shp;
    }
    shapes.clear();

    return 0;
}
