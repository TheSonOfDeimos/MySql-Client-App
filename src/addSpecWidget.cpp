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

    QGridLayout* gl_ = new QGridLayout(this);

    gl_ -> addWidget(new QLabel("Speciality ID", this), 0, 0);
    gl_ -> addWidget(new QLabel("Speciality", this), 1, 0);
    gl_ -> addWidget(new QLabel("Buddget places", this), 2, 0);
    gl_ -> addWidget(new QLabel("Self paid places", this), 3, 0);

    gl_ -> addWidget(spec_num_le_, 0, 1);
    gl_ -> addWidget(spec_le_, 1, 1);
    gl_ -> addWidget(b_places_le_, 2, 1);
    gl_ -> addWidget(sp_places_le_, 3, 1);

    auto hb = new QHBoxLayout(this);
    hb -> addWidget(cancel_button_);
    hb -> addWidget(ok_button_);
    gl_ -> addItem(hb, 4, 1);

    setLayout(gl_);
}

void AddSpecWidget::query()
{

    db_handler_ -> addSpec(spec_num_le_ -> text().toInt(), spec_le_ -> text().toStdString(), b_places_le_ -> text().toInt(), sp_places_le_ -> text().toInt(), 10, 10, 10, 10);
    close();
}

void AddSpecWidget::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;
}
