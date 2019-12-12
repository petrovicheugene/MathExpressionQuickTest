//===============================================
#ifndef ZEQUATIONLINEEDIT_H
#define ZEQUATIONLINEEDIT_H
//===============================================
#include <QTextEdit>

//===============================================
class ZMathExpressionHandler;
//===============================================
class ZMathExpressionTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit ZMathExpressionTextEdit(bool editLineLikeFlag, QWidget* parent = 0);

    QSize sizeHint() const;
    bool zp_calcEquation(double& result);

    void zp_limitHeight();

protected:
    // VARS
    ZMathExpressionHandler* zv_equationHandler;
    bool zv_singleLineFormfactor;

    // FUNCS
    void keyPressEvent(QKeyEvent* e);
    void wheelEvent(QWheelEvent* e);
    void focusOutEvent(QFocusEvent* e);

    void zh_createBracketSelections(const QVector<QPair<int, bool>>&);
    ExtraSelection zh_createBracketSelection(int position, bool bracketErrorFlag);

signals:

    void zs_requestVariableValue(const QString&, double&, bool&);
    void zs_errorReport(const QString&);

    void zs_enterPressed();

protected slots:

    void zh_checkBrackets();
    void zh_onErrorReport(const QString&, int errorTokenStartPosition, int errorTokenEndPosition);

public slots:
};
//===============================================
#endif // ZEQUATIONLINEEDIT_H
