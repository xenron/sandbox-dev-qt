#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *widget = new QWidget(0, Qt::Dialog | Qt::FramelessWindowHint);
    widget->setWindowTitle("我是widget");

    QLabel *label = new QLabel(0, Qt::SplashScreen | Qt::WindowStaysOnTopHint);
    label->setWindowTitle("我是label");
    label->setText("我是一个窗口");
    label->resize(180, 20);

    QLabel *label2 = new QLabel(widget);
    label2->setText("我不是独立的窗口，是widget的子部件");
    label2->resize(250, 20);

    label->show();
    widget->show();

    int ret = a.exec();
    delete label;
    delete widget;

    return ret;
}

