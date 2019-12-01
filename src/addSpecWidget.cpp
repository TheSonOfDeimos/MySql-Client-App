#include "addSpecWidget.h"

AddSpecWidget::AddSpecWidget(QWidget *parent)
    : QWidget(parent)
{
    init();

    connect(ok_button_, SIGNAL(clicked()), this, SLOT(query()));
    connect(cancel_button_, SIGNAL(clicked()), this, SLOT(close()));
}

void AddSpecWidget::init()
{
    ok_button_ = new QPushButton("Ok", this);
    cancel_button_ = new QPushButton("Cancel", this);

    spec_num_le_ = new QLineEdit(this);
    spec_le_ = new QLineEdit(this);
    b_places_le_ = new QLineEdit(this);
    sp_places_le_ = new QLineEdit(this);
    math_le_ = new QLineEdit(this);
    physics_le_ = new QLineEdit(this);
    bio_le_ = new QLineEdit(this);
    chem_le_ = new QLineEdit(this);
    his_le_ = new QLineEdit(this);
    rus_le_ = new QLineEdit(this);
    en_le_ = new QLineEdit(this);

    QGridLayout* gl_ = new QGridLayout(this);

    gl_ -> addWidget(new QLabel("Speciality ID", this), 0, 0);
    gl_ -> addWidget(new QLabel("Speciality", this), 1, 0);
    gl_ -> addWidget(new QLabel("Buddget places", this), 2, 0);
    gl_ -> addWidget(new QLabel("Self paid places", this), 3, 0);

    gl_ -> addWidget(spec_num_le_, 0, 1);
    gl_ -> addWidget(spec_le_, 1, 1);
    gl_ -> addWidget(b_places_le_, 2, 1);
    gl_ -> addWidget(sp_places_le_, 3, 1);

    gl_ ->addWidget(new QLabel("Math", this), 0, 3);
    gl_ ->addWidget(new QLabel("Physics", this), 1, 3);
    gl_ ->addWidget(new QLabel("Biology", this), 2, 3);
    gl_ ->addWidget(new QLabel("Chemestry", this), 3, 3);
    gl_ ->addWidget(new QLabel("History", this), 4, 3);
    gl_ ->addWidget(new QLabel("Russian", this), 5, 3);
    gl_ ->addWidget(new QLabel("English", this), 6, 3);

    gl_ -> addWidget(math_le_, 0, 4);
    gl_ -> addWidget(physics_le_, 1, 4);
    gl_ -> addWidget(bio_le_, 2, 4);
    gl_ -> addWidget(chem_le_, 3, 4);
    gl_ -> addWidget(his_le_, 4, 4);
    gl_ -> addWidget(rus_le_, 5, 4);
    gl_ -> addWidget(en_le_, 6, 4);

    auto hb = new QHBoxLayout(this);
    hb -> addWidget(cancel_button_);
    hb -> addWidget(ok_button_);
    gl_ -> addItem(hb, 7, 4);

    setLayout(gl_);
}

void AddSpecWidget::query()
{

    db_handler_ -> addSpec(spec_num_le_ -> text().toInt(), spec_le_ -> text().toStdString(), b_places_le_ -> text().toInt(), sp_places_le_ -> text().toInt(), 10, 10, 10, 10, 1, 1, 1);
    db_handler_ -> addExamScore(spec_num_le_ -> text().toInt(), math_le_ -> text().toInt(), physics_le_ -> text().toInt(),
                                bio_le_ -> text().toInt(), chem_le_ -> text().toInt(),
                                his_le_ -> text().toInt(), rus_le_ -> text().toInt(),
                                en_le_ -> text().toInt());

    close();
}

void AddSpecWidget::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;
}
