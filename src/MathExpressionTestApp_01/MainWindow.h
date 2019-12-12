//===========================================
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//===========================================
#include <QMainWindow>
//===========================================
class ZDashBoardPane;
class ZMathExpressionHandler;
class ZVariableTableModel;
//===========================================
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:

    void zh_calculateExpression(const QString& expression) const;
    void zh_handleError(const QString& errorString,
                        int errorTokenStartPosition,
                        int errorTokenEndPosition);

private:
    //VARS
    ZDashBoardPane* zv_dashBoardPane;
    ZMathExpressionHandler* zv_mathExpressionHandler;
    ZVariableTableModel* zv_variableTableModel;

    //FUNCS
    void zh_createComponents();
    void zh_createConnections();
    void zh_restoreSettings();
    void zh_saveSettings() const;
};
//===========================================
#endif // MAINWINDOW_H
