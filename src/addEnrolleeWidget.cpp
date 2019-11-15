#include "addEnrolleeWidget.h"
#include <QHeaderView>

AddEnrolleeWidget::AddEnrolleeWidget(QWidget *parent)
    : QDialog(parent)
{
    init();

    connect(ok_button_, SIGNAL(clicked()), this, SLOT(query()));
    connect(cancel_button_, SIGNAL(clicked()), this, SLOT(close()));

}


void AddEnrolleeWidget::init()
{
    QGridLayout* gl_ = new QGridLayout(this);
    ok_button_ = new QPushButton("Ok", this);
    cancel_button_ = new QPushButton("Cancel", this);

    id_le_ = new QLineEdit(this);
    f_name_le_ = new QLineEdit(this);
    s_name_le_  = new QLineEdit(this);
    score_le_ = new QLineEdit(this);
    spec_le_ = new QLineEdit(this);
    pass_le_ = new QLineEdit(this);
    date_of_birth_le_ = new QLineEdit(this);
    place_of_birth_le_ = new QLineEdit(this);
    address_le_ = new QLineEdit(this);
    math_le_ = new QLineEdit(this);
    physics_le_ = new QLineEdit(this);
    bio_le_ = new QLineEdit(this);
    chem_le_ = new QLineEdit(this);
    his_le_ = new QLineEdit(this);
    rus_le_ = new QLineEdit(this);
    en_le_ = new QLineEdit(this);

    atestat_box_ = new QComboBox(this);
    atestat_box_ -> addItem("Copy");
    atestat_box_ -> addItem("Original");

    passport_copy_radio_ = new QCheckBox(this);
    med_form_radio_ = new QCheckBox(this);

    gl_ -> addWidget(new QLabel("ID", this), 0, 0);
    gl_ -> addWidget(new QLabel("First name", this), 1, 0);
    gl_ -> addWidget(new QLabel("Second name", this), 2, 0);
    gl_ -> addWidget(new QLabel("Exam score", this), 3, 0);
    gl_ -> addWidget(new QLabel("Speciality №", this), 4, 0);

    gl_ -> addWidget(id_le_, 0, 1);
    gl_ -> addWidget(f_name_le_, 1, 1);
    gl_ -> addWidget(s_name_le_, 2, 1);
    gl_ -> addWidget(score_le_, 3, 1);
    gl_ -> addWidget(spec_le_, 4, 1);

    gl_ -> addWidget(new QLabel("Passport №", this), 0, 2);
    gl_ -> addWidget(new QLabel("Date of birth\n(YYYY-MM-DD)", this), 1, 2);
    gl_ -> addWidget(new QLabel("Place of birth", this), 2, 2);
    gl_ -> addWidget(new QLabel("Address", this), 3, 2);

    gl_ -> addWidget(pass_le_, 0, 3);
    gl_ -> addWidget(date_of_birth_le_, 1, 3);
    gl_ -> addWidget(place_of_birth_le_, 2, 3);
    gl_ -> addWidget(address_le_, 3, 3);

    gl_ -> addWidget(new QLabel("Atestat", this), 0, 4);
    gl_ -> addWidget(new QLabel("Passport", this), 1, 4);
    gl_ -> addWidget(new QLabel("Medical form", this), 2, 4);

    gl_ -> addWidget(atestat_box_, 0, 5);
    gl_ -> addWidget(passport_copy_radio_, 1, 5);
    gl_ -> addWidget(med_form_radio_, 2, 5);

    gl_ ->addWidget(new QLabel("Math", this), 0, 6);
    gl_ ->addWidget(new QLabel("Physics", this), 1, 6);
    gl_ ->addWidget(new QLabel("Biology", this), 2, 6);
    gl_ ->addWidget(new QLabel("Chemestry", this), 3, 6);
    gl_ ->addWidget(new QLabel("History", this), 4, 6);
    gl_ ->addWidget(new QLabel("Russian", this), 5, 6);
    gl_ ->addWidget(new QLabel("English", this), 6, 6);

    gl_ -> addWidget(math_le_, 0, 7);
    gl_ -> addWidget(physics_le_, 1, 7);
    gl_ -> addWidget(bio_le_, 2, 7);
    gl_ -> addWidget(chem_le_, 3, 7);
    gl_ -> addWidget(his_le_, 4, 7);
    gl_ -> addWidget(rus_le_, 5, 7);
    gl_ -> addWidget(en_le_, 6, 7);


    auto hb = new QHBoxLayout(this);
    hb -> addWidget(cancel_button_);
    hb -> addWidget(ok_button_);
    gl_ -> addItem(hb, 7,  7);

    setLayout(gl_);


}

void AddEnrolleeWidget::query()
{
    db_handler_ -> addAllEnrolleeInfo(id_le_ -> text().toInt(), f_name_le_ -> text().toStdString(), s_name_le_ -> text().toStdString(), score_le_ -> text().toInt(), spec_le_ -> text().toInt(),
                                      pass_le_ -> text().toInt(), date_of_birth_le_ -> text().toStdString(), place_of_birth_le_ -> text().toStdString(), address_le_ -> text().toStdString(),
                                      atestat_box_ -> currentIndex(), passport_copy_radio_ -> checkState(), med_form_radio_ -> checkState(),
                                      math_le_ -> text().toInt(), physics_le_ -> text().toInt(), bio_le_ -> text().toInt(), chem_le_ -> text().toInt(), his_le_ -> text().toInt(), rus_le_ -> text().toInt(), en_le_ -> text().toInt()
                                      );
    close();
}

void AddEnrolleeWidget::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;
}
