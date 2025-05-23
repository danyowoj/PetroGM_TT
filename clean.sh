#!/bin/bash

# Путь к корню проекта
PROJECT_DIR="$(dirname "$(realpath "$0")")"

echo "🧹 Cleaning up the project..."

# Удаление объектных файлов и библиотеки
if [ -d "$PROJECT_DIR/ShapeLibrary/src" ]; then
    rm -fv "$PROJECT_DIR/ShapeLibrary/src/"*.o
    rm -fv "$PROJECT_DIR/ShapeLibrary/lib/"libShapeLibrary.so
fi

# Удаление исполняемого файла
if [ -d "$PROJECT_DIR/ShapeApp" ]; then
    rm -fv "$PROJECT_DIR/ShapeApp/ShapeApp"
fi

echo "✅ The cleaning is complete!"
