#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QComboBox>
#include <QLineEdit>

class MainWindow : public QMainWindow {
public:
    MainWindow() {
        // Создаем центральный виджет и layout
        auto *centralWidget = new QWidget;
        auto *layout = new QVBoxLayout;
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        // Создаем кнопку
        auto *button = new QPushButton("Нажать");
        layout->addWidget(button);

        // Создаем список
        auto *listWidget = new QListWidget;
        listWidget->addItems({"Элемент 1", "Элемент 2", "Элемент 3"});
        listWidget->setAccessibleName("Какой-то список");
        layout->addWidget(listWidget);

        // Создаем комбобокс
        auto *comboBox = new QComboBox;
        comboBox->addItems({"Вариант 1", "Вариант 2", "Вариант 3"});
        comboBox->setAccessibleName("Какой-то комбобокс");
        layout->addWidget(comboBox);

        // Создаем текстовое поле
        auto *lineEdit = new QLineEdit;
        layout->addWidget(lineEdit);
        lineEdit->setAccessibleName("Какое-то текстовое поле");

        // Подключаем сигнал нажатия кнопки
        connect(button, &QPushButton::clicked, [=]() {
            // Пример обработки нажатия кнопки
            QString text = lineEdit->text();
            QString comboText = comboBox->currentText();
            listWidget->addItem(text + " - " + comboText);
        });
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    MainWindow window;
    window.resize(400, 300);
    window.setWindowTitle("Пример приложения");
    window.show();
    
    return app.exec();
}
