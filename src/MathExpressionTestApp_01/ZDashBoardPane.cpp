//===========================================
#include "ZDashBoardPane.h"

#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QPixmap>
#include <QPushButton>
#include <QSettings>
#include <QTableView>
#include <QTextEdit>
#include <QVBoxLayout>

//===========================================
ZDashBoardPane::ZDashBoardPane(QWidget* parent) : QWidget(parent)
{
    zh_createComponents();
    zh_createConnections();
    zh_restoreSettings();
}
//===========================================
ZDashBoardPane::~ZDashBoardPane()
{
    zh_saveSettings();
}
//===========================================
void ZDashBoardPane::zh_createComponents()
{
    QVBoxLayout* mainLayout = new QVBoxLayout;
    setLayout(mainLayout);

    // variables
    QLabel* label = new QLabel(this);
    label->setText(zh_createCaption("Variables:"));
    mainLayout->addWidget(label);

    zv_variablesTableView = new QTableView(this);
    mainLayout->addWidget(zv_variablesTableView);
    label->setBuddy(zv_variablesTableView);

    QHBoxLayout* addRemoveButtonLayout = new QHBoxLayout;
    addRemoveButtonLayout->setMargin(0);
    addRemoveButtonLayout->addStretch();
    mainLayout->addLayout(addRemoveButtonLayout);

    zv_addVariableButton = new QPushButton(this);
    // create icon from QLabel
    QLabel buttonLabel;
    buttonLabel.setText(zh_createCaption("Add"));
    QPixmap pixmap = buttonLabel.grab();
    zv_addVariableButton->setIcon(QIcon(pixmap));
    addRemoveButtonLayout->addWidget(zv_addVariableButton);

    zv_removeVariableButton = new QPushButton(this);
    // create icon from QLabel
    buttonLabel.setText(zh_createCaption("Remove"));
    pixmap = buttonLabel.grab();
    zv_removeVariableButton->setIcon(QIcon(pixmap));
    addRemoveButtonLayout->addWidget(zv_removeVariableButton);

    // expression
    label = new QLabel(this);
    label->setText(zh_createCaption("Expression:"));
    mainLayout->addWidget(label);

    QHBoxLayout* expLayout = new QHBoxLayout;
    expLayout->setMargin(0);
    mainLayout->addLayout(expLayout);

    zv_expressionLineEdit = new QLineEdit(this);
    expLayout->addWidget(zv_expressionLineEdit);
    zv_goButton = new QPushButton(this);
    // create icon from QLabel
    buttonLabel.setText(zh_createCaption("Go!"));
    pixmap = buttonLabel.grab();
    zv_goButton->setIcon(QIcon(pixmap));

    expLayout->addWidget(zv_goButton);
    label->setBuddy(zv_expressionLineEdit);

    // output
    label = new QLabel(this);
    label->setText(zh_createCaption("Output:"));
    mainLayout->addWidget(label);

    zv_outputTextEdit = new QTextEdit(this);
    mainLayout->addWidget(zv_outputTextEdit);
    label->setBuddy(zv_outputTextEdit);

    QHBoxLayout* clearButtonLayout = new QHBoxLayout;
    clearButtonLayout->setMargin(0);
    clearButtonLayout->addStretch();
    mainLayout->addLayout(clearButtonLayout);

    zv_clearOutputButton = new QPushButton(this);
    buttonLabel.setText(zh_createCaption("Clear"));
    pixmap = buttonLabel.grab();
    zv_clearOutputButton->setIcon(QIcon(pixmap));
    clearButtonLayout->addWidget(zv_clearOutputButton);
}
//===========================================
void ZDashBoardPane::zh_createConnections()
{
    connect(zv_addVariableButton,
            &QPushButton::clicked,
            this,
            &ZDashBoardPane::zh_onAddVariableButtonClick);
    connect(zv_removeVariableButton,
            &QPushButton::clicked,
            this,
            &ZDashBoardPane::zh_onRemoveVariableButtonClick);
}
//===========================================
QString ZDashBoardPane::zh_createCaption(const QString& caption) const
{
    return QString("<font color=darkGreen><b>%1</b></font>").arg(caption);
}
//===========================================
void ZDashBoardPane::zh_restoreSettings()
{
    QSettings settings;
    if (!this->objectName().isEmpty())
    {
        settings.beginGroup(objectName());
    }

    restoreGeometry(settings.value("maingeometry").toByteArray());

    while (!settings.group().isEmpty())
    {
        settings.endGroup();
    }
}
//===========================================
void ZDashBoardPane::zh_saveSettings() const
{
    QSettings settings;
    if (!this->objectName().isEmpty())
    {
        settings.beginGroup(objectName());
    }

    settings.setValue("maingeometry", saveGeometry());

    while (!settings.group().isEmpty())
    {
        settings.endGroup();
    }
}
//===========================================
void ZDashBoardPane::zp_connectToVariableModel(QAbstractTableModel* model)
{
    zv_variablesTableView->setModel(model);
    zv_variablesTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}
//===========================================
void ZDashBoardPane::zh_onAddVariableButtonClick()
{
    QAbstractTableModel* model = static_cast<QAbstractTableModel*>(zv_variablesTableView->model());
    if (!model)
    {
        return;
    }

    int newRow = model->rowCount();
    if (!model->insertRow(newRow))
    {
        return;
    }

    QModelIndex newIndex = model->index(newRow, 0);
    if (!newIndex.isValid())
    {
        return;
    }

    zv_variablesTableView->scrollTo(newIndex);
    zv_variablesTableView->edit(newIndex);
}
//===========================================
void ZDashBoardPane::zh_onRemoveVariableButtonClick()
{
    QAbstractTableModel* model = static_cast<QAbstractTableModel*>(zv_variablesTableView->model());
    if (!model)
    {
        return;
    }

    QModelIndexList selectedIndexeList = zv_variablesTableView->selectionModel()->selectedRows();
    QList<int> rowList;
    foreach (QModelIndex index, selectedIndexeList)
    {
        if (!rowList.contains(index.row()))
        {
            rowList << index.row();
        }
    }

    std::sort(rowList.begin(), rowList.end());

    for (int i = rowList.count() - 1; i >= 0; --i)
    {
        model->removeRow(rowList.at(i));
    }
}
//===========================================
