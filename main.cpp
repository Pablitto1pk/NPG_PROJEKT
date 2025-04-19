#include <QApplication>
#include "UI.h" // sam interfejs


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    MyWindow window;
    window.show();

    return app.exec();
}