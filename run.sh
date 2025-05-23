#!/bin/bash

# Пути к папкам
PROJECT_DIR="$(dirname "$(realpath "$0")")"
SHAPE_LIB_DIR="$PROJECT_DIR/ShapeLibrary"
SHAPE_APP_DIR="$PROJECT_DIR/ShapeApp"

# Проверяем, что программа скомпилирована
if [ ! -f "$SHAPE_APP_DIR/ShapeApp" ]; then
    echo "❌ Error: the program is not compiled! First, run ./build.sh."
    exit 1
fi

# Запуск программы
echo "🚀 Running the app..."
export LD_LIBRARY_PATH="$SHAPE_LIB_DIR/lib:$LD_LIBRARY_PATH"
cd "$SHAPE_APP_DIR" && ./ShapeApp ../input.txt
