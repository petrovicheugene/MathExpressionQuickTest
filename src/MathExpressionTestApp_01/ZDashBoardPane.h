//===========================================
#ifndef ZDASHBOARDPANE_H
#define ZDASHBOARDPANE_H
//===========================================
#include <QWidget>
//===========================================
class QAbstractTableModel;
class QLineEdit;
class QPushButton;
class QTableView;
class QTextEdit;
//===========================================
class ZDashBoardPane : public QWidget
{
    Q_OBJECT
public:
    explicit ZDashBoardPane(QWidget* parent = nullptr);
    ~ZDashBoardPane();

    void zp_connectToVariableModel(QAbstractTableModel* model);


signals:

    void zg_expressionCalculationRequest(const QString& expression) const;

public slots:

    void zp_output(const QString& msg);

private slots:

    void zh_onAddVariableButtonClick();
    void zh_onRemoveVariableButtonClick();
    void zh_onGoButtonClick() const;

private:
    //VARS

    QLineEdit* zv_expressionLineEdit;
    QPushButton* zv_goButton;
    QTableView* zv_variablesTableView;
    QPushButton* zv_addVariableButton;
    QPushButton* zv_removeVariableButton;

    QTextEdit* zv_outputTextEdit;
    QPushButton* zv_clearOutputButton;

    //FUNCS
    void zh_createComponents();
    void zh_createConnections();
    QString zh_createCaption(const QString& caption) const;
    void zh_restoreSettings();
    void zh_saveSettings() const;
};
//===========================================
#endif // ZDASHBOARDPANE_H
