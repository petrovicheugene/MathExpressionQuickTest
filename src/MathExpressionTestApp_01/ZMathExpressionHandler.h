//===================================================
#ifndef ZEQUATIONHANDLER_H
#define ZEQUATIONHANDLER_H
//===================================================
#include <QChar>
#include <QObject>
#include <QPair>
#include <QSet>
#include <QVector>
//===================================================
class ZMathExpressionHandler : public QObject
{
    Q_OBJECT
public:
    explicit ZMathExpressionHandler(QObject* parent = 0);

signals:

    void zs_requestVariableValue(const QString& token, double& value, bool& bRes) const;
    void zs_errorReport(const QString& errorString,
                        int errorTokenStartPosition,
                        int errorTokenEndPosition) const;

public slots:

    void zp_defineHighLights(const QString& equation,
                             int cursorPos,
                             QVector<QPair<int, bool>>& highlightedSymbolVector);

    bool zp_checkEquation(const QString& equation,
                          int cursorPos,
                          QVector<QPair<int, bool>>& highlightedSymbolVector);
    bool zp_calculateEquation(const QString& equation, double& result);

protected:
    // VARS

    enum TokenType
    {
        TT_NULL,
        TT_ERROR,
        TT_DOUBLE,
        TT_VARIABLE,
        TT_DELIMITER,
        TT_OPERATOR,
        TT_INTEGER,
        TT_CELL
    } zv_tokenType;

    QVector<QPair<QChar, QChar>> zv_pairSymbolVector;
    QSet<QChar> zv_delimiterSet;
    QSet<QString> zv_operatorSet;

    int zv_charPosition;       // parsing pos in equation
    int zv_tokenStartPosition; // for error report
    int zv_tokenEndPosition;   //  for error report

    QString zv_token;
    QString zv_equation;

    // FUNCS

    void zh_findBracketForward(QChar bracketSymbol,
                               const QString& equation,
                               int pos,
                               QPair<int, bool>& highlight);
    void zh_findBracketBackward(QChar bracketSymbol,
                                const QString& equation,
                                int pos,
                                QPair<int, bool>& highlight);

    bool zh_getToken();
    bool zh_addOrSubtract(double& result);
    bool zh_multiplyOrDevide(double& result);
    bool zh_power(double& result);
    bool zh_unaryOperation(double& result);
    bool zh_recognizeBrackets(double& result);
    bool zh_variableValue(double& result);
    void zh_handleError(int error);
};
//===================================================
#endif // ZEQUATIONHANDLER_H
