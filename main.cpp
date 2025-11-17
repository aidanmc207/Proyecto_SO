#include "firstView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FirstView w;
    w.show();

    return a.exec();
}
