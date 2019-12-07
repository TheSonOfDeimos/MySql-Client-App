#ifndef POTENTIOALSTUDENTSWIDGET_H
#define POTENTIOALSTUDENTSWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QCheckBox>
#include "dbmaneger.h"

class PotentioalStudentsWidget : public QWidget
{
    Q_OBJECT
public:
    PotentioalStudentsWidget(QWidget* parent, int spec_num);

    void init();
    void setDbHandler(DbManeger* handl);

public slots:
    void update();

private:
    DbManeger* db_handler_;
    QGridLayout* gl_;
    QTableWidget* table_;
    QPushButton* ok_button_;
    QCheckBox* budget_order_check_;
    QCheckBox* selfpaid_order_check_;

    int spec_num_;
};

#endif // POTENTIOALSTUDENTSWIDGET_H
