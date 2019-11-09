#include "addEnrolleeWidget.h"

AddEnrolleeWidget::AddEnrolleeWidget(QWidget *parent)
    : QDialog(parent)
{
    init();

    connect(ok_button_, SIGNAL(clicked()), this, SLOT(query()));
    connect(cancel_button_, SIGNAL(clicked()), this, SLOT(close()));

}


void AddEnrolleeWidget::init()
{
    ok_button_ = new QPushButton("Ok", this);
    cancel_button_ = new QPushButton("Cancel", this);

    id_label_ = new QLabel("ID", this);
    f_name_label_ = new QLabel("First name", this);
    s_name_label_ = new QLabel("Second name", this);
    score_label_ = new QLabel("Exam score", this);
    spec_label_ = new QLabel("Speciality №", this);
    pass_label_ = new QLabel("Passport №", this);
    date_of_birth_label_ = new QLabel("Date of birth\n(YYYY-MM-DD)", this);
    place_of_birth_label_ = new QLabel("Place of birth", this);
    address_label_ = new QLabel("Address", this);

    id_le_ = new QLineEdit(this);
    f_name_le_ = new QLineEdit(this);
    s_name_le_  = new QLineEdit(this);
    score_le_ = new QLineEdit(this);
    spec_le_ = new QLineEdit(this);
    pass_le_ = new QLineEdit(this);
    date_of_birth_le_ = new QLineEdit(this);
    place_of_birth_le_ = new QLineEdit(this);
    address_le_ = new QLineEdit(this);

    QGridLayout* gl_ = new QGridLayout(this);

    gl_ -> addWidget(id_label_, 0, 0);
    gl_ -> addWidget(f_name_label_, 1, 0);
    gl_ -> addWidget(s_name_label_, 2, 0);
    gl_ -> addWidget(score_label_, 3, 0);
    gl_ -> addWidget(spec_label_, 4, 0);

    gl_ -> addWidget(id_le_, 0, 1);
    gl_ -> addWidget(f_name_le_, 1, 1);
    gl_ -> addWidget(s_name_le_, 2, 1);
    gl_ -> addWidget(score_le_, 3, 1);
    gl_ -> addWidget(spec_le_, 4, 1);

    gl_ -> addWidget(pass_label_, 0, 2);
    gl_ -> addWidget(date_of_birth_label_, 1, 2);
    gl_ -> addWidget(place_of_birth_label_, 2, 2);
    gl_ -> addWidget(address_label_, 3, 2);

    gl_ -> addWidget(pass_le_, 0, 3);
    gl_ -> addWidget(date_of_birth_le_, 1, 3);
    gl_ -> addWidget(place_of_birth_le_, 2, 3);
    gl_ -> addWidget(address_le_, 3, 3);

    auto hb = new QHBoxLayout(this);
    hb -> addWidget(cancel_button_);
    hb -> addWidget(ok_button_);
    gl_ -> addItem(hb, 5, 3);

    setLayout(gl_);


}

void AddEnrolleeWidget::query()
{
    db_handler_ -> addEnrollee(id_le_ -> text().toInt(), f_name_le_ -> text().toStdString(),
                               s_name_le_ -> text().toStdString(), score_le_ -> text().toInt(),
                               spec_le_ -> text().toInt());

    db_handler_ -> addPersonalInfo(id_le_ -> text().toInt(), pass_le_ -> text().toInt(),
                                   date_of_birth_le_ -> text().toStdString(), place_of_birth_le_ -> text().toStdString(),
                                   address_le_ -> text().toStdString());
    close();
}

void AddEnrolleeWidget::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;
}
