#ifndef ADDENROLLEEWIDGET_H
#define ADDENROLLEEWIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QDialog>
#include <QTableWidget>
#include <QComboBox>
#include <QCheckBox>
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

    QLineEdit* id_le_;
    QLineEdit* f_name_le_;
    QLineEdit* s_name_le_;
    QLineEdit* score_le_;
    QLineEdit* spec_le_;
    QLineEdit* pass_le_;
    QLineEdit* date_of_birth_le_;
    QLineEdit* place_of_birth_le_;
    QLineEdit* address_le_;

    QLineEdit* math_le_;
    QLineEdit* physics_le_;
    QLineEdit* bio_le_;
    QLineEdit* chem_le_;
    QLineEdit* his_le_;
    QLineEdit* rus_le_;
    QLineEdit* en_le_;

    QComboBox* atestat_box_;

    QCheckBox* passport_copy_radio_;
    QCheckBox* med_form_radio_;

    DbManeger* db_handler_;
};

#endif // ADDENROLLEEWIDGET_H
