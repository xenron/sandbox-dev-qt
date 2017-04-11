#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    widget.show();

    int x = widget.x();
    int y = widget.y();

    QRect geometry = widget.geometry();
    QRect frame = widget.frameGeometry();

    return a.exec();
}

