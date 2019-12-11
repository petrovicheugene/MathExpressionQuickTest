//===========================================
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//===========================================
#include <QMainWindow>
//===========================================
class ZDashBoardPane;
class ZMathExpressionHandler;
class QAbstractTableModel;
//===========================================
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //VARS
    ZDashBoardPane* zv_dashBoardPane;
    ZMathExpressionHandler* zv_mathExpressionHandler;
    QAbstractTableModel* zv_variableTableModel;

    //FUNCS
    void zh_createComponents();
    void zh_createConnections();
    void zh_restoreSettings();
    void zh_saveSettings() const;


};
//===========================================
#endif // MAINWINDOW_H
