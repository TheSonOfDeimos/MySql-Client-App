#ifndef PERSANALINFODLG_H
#define PERSANALINFODLG_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include "dbmaneger.h"

class PersanalInfoWidget : public QWidget
{
    Q_OBJECT
public:
    PersanalInfoWidget(QWidget* parent, int id);

    void init();
    void setDbHandler(DbManeger* handl);

public slots:
    void query();

private:
    std::vector< QLabel > label_vec_;

    QGridLayout* gl_;
    QPushButton* ok_button_;
    QPushButton* cancel_button_;

    QLineEdit* id_le_;
    QLineEdit* f_name_le_;
    QLineEdit* s_name_le_;
    QLineEdit* score_le_;
    QLineEdit* spec_num_le_;
    QLineEdit* spec_le_;
    QLineEdit* addres_le_;
    QLineEdit* passport_le_;
    QLineEdit* p_of_b_le_;
    QLineEdit* d_of_b_le_;

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
    int id_;


};

#endif // PERSANALINFODLG_H
