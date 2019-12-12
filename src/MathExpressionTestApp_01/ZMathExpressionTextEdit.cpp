//===============================================
#include "ZMathExpressionTextEdit.h"
#include <ZMathExpressionHandler.h>
#include <QFontMetrics>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QFocusEvent>
#include <QDebug>

//===============================================
ZMathExpressionTextEdit::ZMathExpressionTextEdit(bool editLineLikeFlag, QWidget *parent) :
    QTextEdit(parent)
{
    zv_singleLineFormfactor = editLineLikeFlag;
    if(editLineLikeFlag)
    {
        zp_limitHeight();
        setWordWrapMode (QTextOption::NoWrap);
        setHorizontalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
        setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Fixed);
        setAlignment(Qt::AlignVCenter);
    }

    setTabChangesFocus (true);

    zv_equationHandler = new ZMathExpressionHandler(this);

    connect(zv_equationHandler, SIGNAL(zs_requestVariableValue(const QString&,double&,bool&)),
            this, SIGNAL(zs_requestVariableValue(const QString& ,double&,bool&)));

    connect(zv_equationHandler, SIGNAL(zs_errorReport(const QString&,int, int)),
            this, SLOT(zh_onErrorReport(const QString&,int, int)));

    connect(this, SIGNAL(textChanged()), this, SLOT(zh_checkEquation()));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(zh_checkBrackets()));
}
//==================================================
void ZMathExpressionTextEdit::zp_limitHeight()
{
    QSize myEditSize = document()->size().toSize();
    setMaximumHeight(myEditSize.height());
}
//==================================================
QSize ZMathExpressionTextEdit::sizeHint() const
{
    if(zv_singleLineFormfactor)
    {
        QFontMetrics fm(font());
        int h = fm.height();
        int w = fm.width(QLatin1Char('w'));

        return QSize(w, h);
    }
    else
    {
        return QTextEdit::sizeHint();
    }
}
//==================================================
void ZMathExpressionTextEdit::keyPressEvent(QKeyEvent *e)
{
    if ((e->key () == Qt::Key_Enter) || (e->key () == Qt::Key_Return))
    {
        emit zs_enterPressed();
        //e->ignore();
        e->setAccepted(true);
    }
    else
    {
        QTextEdit::keyPressEvent (e);
    }
}
//==================================================
void ZMathExpressionTextEdit::wheelEvent(QWheelEvent *e)
{
    if(zv_singleLineFormfactor)
    {
        e->ignore();
    }
}
//==================================================
void ZMathExpressionTextEdit::focusOutEvent(QFocusEvent *e)
{
    QTextEdit::focusOutEvent(e);
}
//==================================================
void ZMathExpressionTextEdit::zh_checkBrackets()
{
    QVector<QPair<int, bool> > highlightedSymbolVector;
    zv_equationHandler->zp_defineHighLights(this->toPlainText() , this->textCursor().position(), highlightedSymbolVector);

    zh_createBracketSelections(highlightedSymbolVector);
}
//==================================================
void ZMathExpressionTextEdit::zh_onErrorReport(const QString& errorString, int errorTokenStartPosition,  int errorTokenEndPosition)
{
    emit zs_errorReport(errorString);
}
//==================================================
void ZMathExpressionTextEdit::zh_createBracketSelections(const QVector<QPair<int, bool> >& highlightedSymbolVector)
{
    QList <QTextEdit::ExtraSelection> listSelections;

    for(int i = 0; i < highlightedSymbolVector.count(); i++)
    {
        listSelections.append(zh_createBracketSelection(highlightedSymbolVector.at(i).first, highlightedSymbolVector.at(i).second));
    }
    setExtraSelections(listSelections);
}
//==================================================
QTextEdit::ExtraSelection ZMathExpressionTextEdit::zh_createBracketSelection(int position, bool bracketErrorFlag)
{
    QTextEdit::ExtraSelection selection;

    QTextCharFormat format = selection.format;
    QColor color = bracketErrorFlag? Qt::green : Qt::red;
    format.setForeground(color);

    selection.format = format;

    QTextCursor cursor = textCursor();
    cursor.setPosition(position);
    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

    selection.cursor = cursor;

    return selection;
}
//==================================================
bool ZMathExpressionTextEdit::zp_calcEquation(double& result)
{
    return zv_equationHandler->zp_calculateEquation(this->document()->toPlainText(), result);
}
//==================================================
