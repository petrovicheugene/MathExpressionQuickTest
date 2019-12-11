//===========================================
#include "MainWindow.h"

#include "ZDashBoardPane.h"
#include "ZMathExpressionHandler.h"
#include "ZVariableTableModel.h"


#include <QApplication>
#include <QSettings>
//===========================================
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    setWindowTitle(qApp->applicationDisplayName());

    zh_createComponents();
    zh_createConnections();
    zh_restoreSettings();
}
//===========================================
MainWindow::~MainWindow()
{
    zh_saveSettings();
}
//===========================================
void MainWindow::zh_createComponents()
{
    zv_dashBoardPane = new ZDashBoardPane(this);
    setCentralWidget(zv_dashBoardPane);

    zv_mathExpressionHandler = new ZMathExpressionHandler(this);
    zv_variableTableModel = new ZVariableTableModel(this);
}
//===========================================
void MainWindow::zh_createConnections()
{
    zv_dashBoardPane->zp_connectToVariableModel(zv_variableTableModel);
}
//===========================================
void MainWindow::zh_restoreSettings()
{
    QSettings settings;
    if (!this->objectName().isEmpty())
    {
        settings.beginGroup(objectName());
    }

    restoreGeometry(settings.value("geometry").toByteArray());

    while (!settings.group().isEmpty())
    {
        settings.endGroup();
    }
}
//===========================================
void MainWindow::zh_saveSettings() const
{
    QSettings settings;
    if (!this->objectName().isEmpty())
    {
        settings.beginGroup(objectName());
    }

    settings.setValue("geometry", saveGeometry());

    while (!settings.group().isEmpty())
    {
        settings.endGroup();
    }
}
