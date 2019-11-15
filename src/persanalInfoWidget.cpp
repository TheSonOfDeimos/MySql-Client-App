#include "personalInfoWidget.h"

PersanalInfoWidget::PersanalInfoWidget(QWidget* parent, int id)
    : QWidget(parent)
{
    id_ = id;
    init();

    connect(ok_button_, SIGNAL(clicked()), this, SLOT(query()));
    connect(cancel_button_, SIGNAL(clicked()), this, SLOT(close()));
}

void PersanalInfoWidget::init()
{
    ok_button_ = new QPushButton("Ok", this);
    cancel_button_ = new QPushButton("Cancel", this);
    gl_ = new QGridLayout(this);

    id_le_ = new QLineEdit;
    f_name_le_ = new QLineEdit;
    s_name_le_ = new QLineEdit;
    score_le_ = new QLineEdit;
    spec_num_le_ = new QLineEdit;
    spec_le_ = new QLineEdit;
    addres_le_ = new QLineEdit;
    passport_le_ = new QLineEdit;
    p_of_b_le_ = new QLineEdit;
    d_of_b_le_ = new QLineEdit;
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


    gl_ -> addWidget(new QLabel("First name", this), 1, 0);
    gl_ -> addWidget(new QLabel("Second name", this), 2, 0);
    gl_ -> addWidget(new QLabel("Exam score", this), 3, 0);
    gl_ -> addWidget(new QLabel("Speciality №", this), 4, 0);

    gl_ -> addWidget(new QLabel("Passport №", this), 1, 2);
    gl_ -> addWidget(new QLabel("Addres", this), 2, 2);
    gl_ -> addWidget(new QLabel("Date of birth\n(YYYY-MM-DD)", this), 3, 2);
    gl_ -> addWidget(new QLabel("Place of birth", this), 4, 2);

    gl_ -> addWidget(f_name_le_, 1, 1);
    gl_ -> addWidget(s_name_le_, 2, 1);
    gl_ -> addWidget(score_le_, 3, 1);
    gl_ -> addWidget(spec_num_le_, 4, 1);

    gl_ -> addWidget(passport_le_, 1, 3);
    gl_ -> addWidget(addres_le_, 2, 3);
    gl_ -> addWidget(d_of_b_le_, 3, 3);
    gl_ -> addWidget(p_of_b_le_, 4, 3);

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

    QHBoxLayout* hbl = new QHBoxLayout(this);
    hbl -> addWidget(cancel_button_);
    hbl -> addWidget(ok_button_);
    gl_ -> addLayout(hbl, 8, 7);

    setLayout(gl_);
}

void PersanalInfoWidget::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;


    QString f_name;
    QString s_name;
    QString total_score;
    QString spec_num;
    QString spec;
    QString id;
    QString passport;
    QString date_of_birth;
    QString place_of_birth;
    QString address;
    QString math;
    QString phy;
    QString bio;
    QString chem;
    QString his;
    QString rus;
    QString en;
    QString atestat;
    QString pass_copy;
    QString med_form;


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
        spec_num = QString::fromUtf8(res -> getString(4).asStdString().c_str());
        total_score = QString::fromUtf8(res -> getString(5).asStdString().c_str());
    }

    str = "SELECT * FROM mydb.specialisation_list \nWHERE spec_num =" + std::to_string(spec_num.toInt());
    res = db_handler_ -> queryToDb(str);
    while (res -> next())
    {
        spec = QString::fromUtf8(res -> getString(2).asStdString().c_str());
    }

    str = "SELECT * FROM mydb.exam_list \nWHERE id = " + std::to_string(id_);
    res = db_handler_ -> queryToDb(str);
    while (res -> next())
    {
        math = QString::fromUtf8(res -> getString(2).asStdString().c_str());
        phy = QString::fromUtf8(res -> getString(3).asStdString().c_str());
        bio = QString::fromUtf8(res -> getString(4).asStdString().c_str());
        chem = QString::fromUtf8(res -> getString(5).asStdString().c_str());
        his = QString::fromUtf8(res -> getString(6).asStdString().c_str());
        rus = QString::fromUtf8(res -> getString(7).asStdString().c_str());
        en = QString::fromUtf8(res -> getString(8).asStdString().c_str());
    }

    str = "SELECT * FROM mydb.enrollee_doc_list \nWHERE id = " + std::to_string(id_);
    res = db_handler_ -> queryToDb(str);
    while (res -> next())
    {
        atestat = QString::fromUtf8(res -> getString(2).asStdString().c_str());
        pass_copy = QString::fromUtf8(res -> getString(3).asStdString().c_str());
        med_form = QString::fromUtf8(res -> getString(4).asStdString().c_str());
    }



    gl_ -> addWidget(new QLabel("ID: " + id, this), 0, 0);

    id_le_ -> insert(id);
    f_name_le_ -> insert(f_name);
    s_name_le_ -> insert(s_name);
    score_le_ -> insert(total_score);
    spec_num_le_ -> insert(spec_num);
    spec_le_ -> insert(spec);
    addres_le_ -> insert(address);
    passport_le_ -> insert(passport);
    p_of_b_le_ -> insert(place_of_birth);
    d_of_b_le_ -> insert(date_of_birth);

    math_le_ -> insert(math);
    physics_le_ -> insert(phy);
    bio_le_ -> insert(bio);
    chem_le_ -> insert(chem);
    his_le_ -> insert(his);
    rus_le_ -> insert(rus);
    en_le_ -> insert(en);

    atestat_box_ -> setCurrentIndex(atestat.toInt());
    passport_copy_radio_ -> setCheckState(pass_copy.toInt() == 1 ? Qt::Checked : Qt::Unchecked);
    med_form_radio_ -> setCheckState(med_form.toInt() == 1 ? Qt::Checked : Qt::Unchecked);


}

void PersanalInfoWidget::query()
{
    db_handler_ -> addAllEnrolleeInfo(id_le_ -> text().toInt(), f_name_le_ -> text().toStdString(), s_name_le_ -> text().toStdString(), score_le_ -> text().toInt(), spec_num_le_ -> text().toInt(),
                                      passport_le_ -> text().toInt(), d_of_b_le_ -> text().toStdString(), p_of_b_le_ -> text().toStdString(), addres_le_ -> text().toStdString(),
                                      atestat_box_ -> currentIndex(), passport_copy_radio_ -> checkState(), med_form_radio_ -> checkState(),
                                      math_le_ -> text().toInt(), physics_le_ -> text().toInt(), bio_le_ -> text().toInt(), chem_le_ -> text().toInt(), his_le_ -> text().toInt(), rus_le_ -> text().toInt(), en_le_ -> text().toInt()
                                      );

    close();
}
