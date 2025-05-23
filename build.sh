#!/bin/bash

# Пути к папкам
PROJECT_DIR="$(dirname "$(realpath "$0")")"
SHAPE_LIB_DIR="$PROJECT_DIR/ShapeLibrary"
SHAPE_APP_DIR="$PROJECT_DIR/ShapeApp"

# 1. Сборка библиотеки (.so)
echo "🔧 Building the library..."
cd "$SHAPE_LIB_DIR/src" || exit 1
g++ -c -fPIC -I../include shapes.cpp factory.cpp || exit 1
g++ -shared -o libShapeLibrary.so shapes.o factory.o || exit 1

# Создаем папку lib, если её нет
mkdir -p "$SHAPE_LIB_DIR/lib"
mv libShapeLibrary.so "$SHAPE_LIB_DIR/lib/" || exit 1

# 2. Компиляция основной программы
echo "🔧 Building the app..."
cd "$SHAPE_APP_DIR" || exit 1
g++ main.cpp -o ShapeApp -I"$SHAPE_LIB_DIR/include" -L"$SHAPE_LIB_DIR/lib" -lShapeLibrary || exit 1

echo "✅ Build complete! Launch ./run.sh"
