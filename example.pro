TEMPLATE = app
QT += widgets
CONFIG += c++17

# Указываем путь к директории с исходниками
SOURCES += src/main.cpp

# Настраиваем путь к директории сборки
DESTDIR = $$PWD/build/bin

# Указываем имя исполняемого файла
TARGET = example
