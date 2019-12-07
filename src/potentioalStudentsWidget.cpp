#include "potentioalStudentsWidget.h"
#include <QHBoxLayout>
#include <QLabel>
PotentioalStudentsWidget::PotentioalStudentsWidget(QWidget *parent, int spec_num)
    : QWidget(parent),
      spec_num_(spec_num)
{
    init();
    connect(ok_button_, SIGNAL(clicked()), this, SLOT(close()));
    connect(budget_order_check_, SIGNAL(stateChanged(int)), this, SLOT(update()));
    connect(selfpaid_order_check_ , SIGNAL(stateChanged(int)), this, SLOT(update()));

}

 void PotentioalStudentsWidget::init()
 {
     gl_ = new QGridLayout(this);
     ok_button_ = new QPushButton("Ok", this);
     budget_order_check_ = new QCheckBox(this);
     budget_order_check_ -> setCheckState(Qt::Checked);
     selfpaid_order_check_ = new QCheckBox(this);
     selfpaid_order_check_ -> setCheckState(Qt::Checked);



     table_ = new QTableWidget(this);
     table_ -> setSortingEnabled(false);
     table_ -> setColumnCount(5);
     table_ -> setHorizontalHeaderLabels({"ID", "First name", "Second name", "Speciality", "Exam score"});

     gl_ -> addWidget(table_, 0, 0);
     gl_ -> addWidget(new QLabel("Budget places", this), 0, 1);
     gl_ -> addWidget(new QLabel("Self paid places", this), 1, 1);
     gl_ -> addWidget(budget_order_check_, 0, 2);
     gl_ -> addWidget(selfpaid_order_check_, 1, 2);
     gl_ -> addWidget(ok_button_, 2, 2);

     setLayout(gl_);

 }

void PotentioalStudentsWidget::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;
    update();
}

void PotentioalStudentsWidget::update()
{
    auto res = db_handler_ -> selectPotentioalStudents(spec_num_);

    int counter = 0;
    if (budget_order_check_ -> checkState()) {
        auto res = db_handler_->selectBudgetPlaces(spec_num_);
        while (res -> next())
        {
            counter += res -> getInt(1);
        }
    }

    if (selfpaid_order_check_ -> checkState()) {
        auto res = db_handler_->selectSelfPaid(spec_num_);
        while (res -> next())
        {
            counter += res -> getInt(1);
        }
    }

    table_ -> setSortingEnabled(false);
    table_ -> setRowCount(0);
    while(res -> next())
    {
        if (counter != 0) {
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
        counter--;
    }

    table_ -> setSortingEnabled(true);

}
