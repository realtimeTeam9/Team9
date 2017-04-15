#include <window.h>

#include <QApplication>


int main(int argc, char *argv[])
{

        QApplication app(argc, argv);

        Window window;
        window.showMaximized();

        window.startTimer(4);

        return app.exec();

}

