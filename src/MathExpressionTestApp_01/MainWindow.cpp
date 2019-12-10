//===========================================
#include "MainWindow.h"

#include <QApplication>
//===========================================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(qApp->applicationDisplayName());

}
//===========================================
MainWindow::~MainWindow()
{
}
//===========================================

