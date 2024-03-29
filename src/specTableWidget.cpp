#include "specTableWidget.h"


SpecTableWidget::SpecTableWidget(QWidget *parent)
 : QWidget(parent)
{
    gl_ = new QGridLayout(this);
    vbl_ = new QVBoxLayout(this);

    table_ = new QTableWidget(this);
    add_spec_button_ = new QPushButton("Add speciality", this);
    update_button_ = new QPushButton("Update", this);

    vbl_ -> addWidget(add_spec_button_);
    vbl_ -> addWidget(update_button_);
    gl_ -> addWidget(table_, 0, 0);
    gl_ -> addLayout(vbl_, 0, 1);

    setLayout(gl_);

    connect(add_spec_button_, SIGNAL(clicked()), this, SLOT(addSpec()));
    connect(update_button_, SIGNAL(clicked()), this, SLOT(update()));
}

void SpecTableWidget::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;
}

void SpecTableWidget::init()
{
    table_ -> setColumnCount(4);
    table_ -> setHorizontalHeaderLabels({"Speciality ID", "Speciality", "Budget places", "Self paid places"});
    update();

    if (db_handler_ -> getRole() == DbManeger::ENROLLEE || db_handler_ -> getRole() == DbManeger::LOGINADMIN || db_handler_ -> getRole() == DbManeger::OFFICER) {
        add_spec_button_ -> hide();
    }
}

void SpecTableWidget::addSpec()
{
    if (db_handler_ -> getRole() == DbManeger::ENROLLEE || db_handler_ -> getRole() == DbManeger::LOGINADMIN || db_handler_ -> getRole() == DbManeger::OFFICER) {
        return;
    }

    add_spec_widget_ = new AddSpecWidget(nullptr);
    add_spec_widget_ -> setDbHandler(db_handler_);
    add_spec_widget_ -> show();
}

void SpecTableWidget::update()
{
    table_ -> setSortingEnabled(false);
    auto res = db_handler_ -> queryToDb("SELECT * FROM mydb.specialisation_list ORDER BY specialisation");
    table_ -> setRowCount(0);
    while (res -> next())
    {
        table_->setRowCount(table_ -> rowCount() + 1);
        QTableWidgetItem* el1 = new QTableWidgetItem;
        el1 -> setData(Qt::EditRole, res -> getInt(1));
        table_ -> setItem(table_ -> rowCount() - 1, 0, el1);

        table_ -> setItem(table_ -> rowCount() - 1, 1, new QTableWidgetItem(QString::fromUtf8(res -> getString(2).asStdString().c_str())));

        QTableWidgetItem* el2 = new QTableWidgetItem;
        el2 -> setData(Qt::EditRole, res -> getInt(3));
        table_ -> setItem(table_ -> rowCount() - 1, 2, el2);

        QTableWidgetItem* el3 = new QTableWidgetItem;
        el3 -> setData(Qt::EditRole, res -> getInt(4));
        table_ -> setItem(table_ -> rowCount() - 1, 3, el3);
    }
    table_ -> setSortingEnabled(true);

}
