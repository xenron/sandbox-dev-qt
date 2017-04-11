#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include <QSpinBox>
#include <QLabel>
#include <QTextEdit>
#include <QMdiSubWindow>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolButton *toolBtn = new QToolButton(this);          // 创建QToolButton
    toolBtn->setText(tr("颜色"));
    QMenu *colorMenu = new QMenu(this);                // 创建一个菜单
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolBtn->setMenu(colorMenu);                        // 添加菜单
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup); // 设置弹出模式
    ui->mainToolBar->addWidget(toolBtn);                 // 向工具栏添加QToolButton按钮

    QSpinBox *spinBox = new QSpinBox(this);             // 创建QSpinBox
    ui->mainToolBar->addWidget(spinBox);                // 向工具栏添加QSpinBox部件

    // 显示临时消息，显示2000毫秒即2秒
    ui->statusBar->showMessage(tr("欢迎使用多文档编辑器"), 2000);
    // 创建标签，设置标签样式并显示信息，然后将其以永久部件的形式添加到状态栏
    QLabel *permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.qter.org");
    ui->statusBar->addPermanentWidget(permanent);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_triggered()
{
    ui->dockWidget->show();
}



void MainWindow::on_action_N_triggered()
{
    // 新建文本编辑器部件
    QTextEdit *edit = new QTextEdit(this);
    // 使用QMdiArea类的addSubWindow()函数创建子窗口，以文本编辑器为中心部件
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("多文档编辑器子窗口"));
    child->show();

}


