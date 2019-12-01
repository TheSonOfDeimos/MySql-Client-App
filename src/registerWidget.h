#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QComboBox>
#include "dbmaneger.h"

class RegisterWidget : public QWidget
{
    Q_OBJECT
public:
    RegisterWidget() = default;
    RegisterWidget(QWidget *parent);

    void connectToDb();

public slots:
    void registerUser();

private:
    QPushButton* register_button_;
    QPushButton* cancel_button_;

    QLineEdit* login_le_;
    QLineEdit* passw_le_;
    QLineEdit* passw_conf_le_;

    QGridLayout* gl_;

    QComboBox* role_box_;

    DbManeger* db_handler_;
};

#endif // REGISTERWIDGET_H
