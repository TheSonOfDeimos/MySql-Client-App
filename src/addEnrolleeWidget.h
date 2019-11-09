#ifndef ADDENROLLEEWIDGET_H
#define ADDENROLLEEWIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QDialog>
#include "dbmaneger.h"

class AddEnrolleeWidget : public QDialog
{
    Q_OBJECT
public:
    AddEnrolleeWidget(QWidget* parent);
    ~AddEnrolleeWidget() = default;

    void setDbHandler(DbManeger* handl);
    void init();

public slots:
    void query();

private:
    QPushButton* ok_button_;
    QPushButton* cancel_button_;

    QLabel* id_label_;
    QLabel* f_name_label_;
    QLabel* s_name_label_;
    QLabel* score_label_;
    QLabel* spec_label_;
    QLabel* pass_label_;
    QLabel* date_of_birth_label_;
    QLabel* place_of_birth_label_;
    QLabel* address_label_;

    QLineEdit* id_le_;
    QLineEdit* f_name_le_;
    QLineEdit* s_name_le_;
    QLineEdit* score_le_;
    QLineEdit* spec_le_;
    QLineEdit* pass_le_;
    QLineEdit* date_of_birth_le_;
    QLineEdit* place_of_birth_le_;
    QLineEdit* address_le_;

    QGridLayout* gl_;

    DbManeger* db_handler_;
};

#endif // ADDENROLLEEWIDGET_H
