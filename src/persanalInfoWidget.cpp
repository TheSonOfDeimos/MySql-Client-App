#include "personalInfoWidget.h"

PersanalInfoWidget::PersanalInfoWidget(QWidget* parent, int id)
    : QWidget(parent)
{
    id_ = id;
    init();
}

void PersanalInfoWidget::init()
{
    gl_ = new QGridLayout(this);
    setLayout(gl_);
}

void PersanalInfoWidget::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;


    QString f_name;
    QString s_name;
    QString total_score;
    QString spec;
    QString id;
    QString passport;
    QString date_of_birth;
    QString place_of_birth;
    QString address;

    std::string str = "SELECT * FROM mydb.personal_enrollee_information \nWHERE id=" + std::to_string(id_);
    auto res = db_handler_ -> queryToDb(str);
    while (res -> next())
    {
        id = QString::fromUtf8(res -> getString(1).asStdString().c_str());
        passport = QString::fromUtf8(res -> getString(2).asStdString().c_str());
        date_of_birth = QString::fromUtf8(res -> getString(3).asStdString().c_str());
        place_of_birth = QString::fromUtf8(res -> getString(4).asStdString().c_str());
        address = QString::fromUtf8(res -> getString(5).asStdString().c_str());
    }

    str = "SELECT * FROM mydb.enrollee_information \nWHERE id =" + std::to_string(id_);
    res = db_handler_ -> queryToDb(str);
    while (res -> next())
    {
        f_name = QString::fromUtf8(res -> getString(2).asStdString().c_str());
        s_name = QString::fromUtf8(res -> getString(3).asStdString().c_str());
        spec = QString::fromUtf8(res -> getString(4).asStdString().c_str());
        total_score = QString::fromUtf8(res -> getString(5).asStdString().c_str());
    }

    str = "SELECT * FROM mydb.specialisation_list \nWHERE spec_num =" + std::to_string(spec.toInt());
    res = db_handler_ -> queryToDb(str);
    while (res -> next())
    {
        spec = QString::fromUtf8(res -> getString(2).asStdString().c_str()) + "  [№" + spec + "]";
    }


    gl_ -> addWidget(new QLabel("ID: " + id, this), 0, 0);
    gl_ -> addWidget(new QLabel("Name: " + f_name + " " + s_name, this), 0, 1);

    gl_ -> addWidget(new QLabel("Total score: " + total_score, this), 1, 0);
    gl_ -> addWidget(new QLabel("Speciality: " + spec, this), 1, 1);

    gl_ -> addWidget(new QLabel("Passport №: " + passport, this), 2, 0);
    gl_ -> addWidget(new QLabel("Addres: " + address, this), 2, 1);

    gl_ -> addWidget(new QLabel("Date of birth: " + date_of_birth, this), 3, 0);
    gl_ -> addWidget(new QLabel("Place of birth: " + place_of_birth, this), 4, 0);






}
