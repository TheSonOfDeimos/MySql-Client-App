#include "enrolleetable.h"

EnrolleeTable::EnrolleeTable(QWidget* parent)
    : QWidget(parent)
{
    layout_ = new QHBoxLayout(this);
    vbl_ = new QVBoxLayout(this);
    setLayout(layout_);

    table_ = new QTableWidget(this);


    update_button_ = new QPushButton("Update", this);
    add_enrollee_button_ = new QPushButton("Add", this);
    spec_select_box_ = new QComboBox(this);

    vbl_ -> addWidget(add_enrollee_button_);
    vbl_ -> addWidget(update_button_);
    vbl_ -> addWidget(spec_select_box_);
    layout_ -> addWidget(table_);
    layout_ -> addLayout(vbl_);

    connect(spec_select_box_, SIGNAL(currentIndexChanged(int)), this, SLOT(update()));
    connect(update_button_, SIGNAL(clicked()), this, SLOT(update()));
    connect(add_enrollee_button_, SIGNAL(clicked()), this, SLOT(addEnrolleeDlg()));
    connect(table_, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(showPersanalInfoDlg(QTableWidgetItem*)));
}

void EnrolleeTable::init()
{
    table_ -> setSortingEnabled(false);
    table_ -> setColumnCount(5);
    table_ -> setHorizontalHeaderLabels({"ID", "First name", "Second name", "Speciality", "Exam score"});

    auto res = db_handler_ -> queryToDb("SELECT * FROM mydb.specialisation_list ORDER BY specialisation");

    spec_list_.clear();
    spec_select_box_->clear();
    while (res -> next())
    {
        spec_list_.push_back(std::make_pair(res -> getInt(1), res -> getString(2).asStdString()));
        spec_select_box_ -> addItem(QString::fromUtf8(spec_list_.back().second.c_str()));
    }
}

void EnrolleeTable::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;
}

void EnrolleeTable::update()
{
    table_ -> setSortingEnabled(false);
    auto res = db_handler_ -> selectEnrolleBySpec(spec_list_.at(spec_select_box_ -> currentIndex()).first);
    table_ -> setRowCount(0);
    while(res -> next())
    {
        table_->setRowCount(table_ -> rowCount() + 1);

        QTableWidgetItem* el1 = new QTableWidgetItem;
        el1 -> setData(Qt::EditRole, res -> getInt(1));
        table_ -> setItem(table_ -> rowCount() - 1, 0, el1);
        table_ -> setItem(table_ -> rowCount() - 1, 1, new QTableWidgetItem(QString::fromUtf8(res -> getString(2).asStdString().c_str())));
        table_ -> setItem(table_ -> rowCount() - 1, 2, new QTableWidgetItem(QString::fromUtf8(res -> getString(3).asStdString().c_str())));

        QTableWidgetItem* el2 = new QTableWidgetItem;
        el2 -> setData(Qt::EditRole, res -> getInt(4));
        table_ -> setItem(table_ -> rowCount() - 1, 3, el2);

        QTableWidgetItem* el3 = new QTableWidgetItem;
        el3 -> setData(Qt::EditRole, res -> getInt(5));
        table_ -> setItem(table_ -> rowCount() - 1, 4, el3);
    }

    table_ -> setSortingEnabled(true);

}

void EnrolleeTable::addEnrolleeDlg()
{
    add_enrolle_widget_ = new AddEnrolleeWidget(this);
    add_enrolle_widget_ -> setDbHandler(db_handler_);
    add_enrolle_widget_ -> setVisible(1);
    //add_enrolle_widget_ -> show();
}

void EnrolleeTable::showPersanalInfoDlg(QTableWidgetItem *item)
{
    auto sender = QObject::sender();
    auto id = reinterpret_cast< QTableWidget* >(sender) -> item(item -> row(), 0);
    persanal_info_widget_ = new PersanalInfoWidget(nullptr, std::stoi(id->text().toStdString()));
    persanal_info_widget_ -> setDbHandler(db_handler_);
    persanal_info_widget_ -> show();
}
