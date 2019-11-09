#ifndef ADDSPECWIDGET_H
#define ADDSPECWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include "dbmaneger.h"

class AddSpecWidget : public QWidget
{
    Q_OBJECT
public:
    AddSpecWidget(QWidget *parent);

    void init();
    void setDbHandler(DbManeger* handl);

public slots:
    void query();

private:
    QPushButton* ok_button_;
    QPushButton* cancel_button_;

    QLineEdit* spec_num_le_;
    QLineEdit* spec_le_;
    QLineEdit* b_places_le_;
    QLineEdit* sp_places_le_;

    QGridLayout* gl_;

    DbManeger* db_handler_;
};

#endif // ADDSPECWIDGET_H
