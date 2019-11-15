#include "statisticWidget.h"

StatisticWidget::StatisticWidget(QWidget *parent)
    : QWidget(parent)
{
    layout_ = new QHBoxLayout(this);
    table_ = new QTableWidget(this);
    spec_select_box_ = new QComboBox(this);

    layout_ -> addWidget(table_);
    layout_ -> addWidget(spec_select_box_);

    setLayout(layout_);

    connect(spec_select_box_, SIGNAL(currentIndexChanged(int)), this, SLOT(update()));
}

void StatisticWidget::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;
}

void StatisticWidget::init()
{
    table_ -> setSortingEnabled(false);
    table_ -> setColumnCount(5);
    table_ -> setHorizontalHeaderLabels({"Total applications", "Average exam score", "Max exam score", "Min exam score", "Number of original atestats"});

    auto res = db_handler_ -> queryToDb("SELECT * FROM mydb.specialisation_list ORDER BY specialisation");

    spec_list_.clear();
    spec_select_box_->clear();
    while (res -> next())
    {
        spec_list_.push_back(std::make_pair(res -> getInt(1), res -> getString(2).asStdString()));
        spec_select_box_ -> addItem(QString::fromUtf8(spec_list_.back().second.c_str()));
    }
}

void StatisticWidget::update()
{
    std::string str = "select ( select count(spec_num) from enrollee_information \
                        \nWHERE spec_num = " + std::to_string(spec_list_.at(spec_select_box_ -> currentIndex()).first) + ") as enrollees_count , \
                        \n( select AVG(exam_score) from enrollee_information where spec_num = " + std::to_string(spec_list_.at(spec_select_box_ -> currentIndex()).first) + ")  as average_score , \
                        \n( select MAX(exam_score) from enrollee_information where spec_num = " + std::to_string(spec_list_.at(spec_select_box_ -> currentIndex()).first) + ")  max_score , \
                        \n( select MIN(exam_score) from enrollee_information where spec_num = " + std::to_string(spec_list_.at(spec_select_box_ -> currentIndex()).first) + ")  as min_score , \
                        \n( select COUNT(atestat) from mydb.enrollee_doc_list \
                        \ninner join enrollee_information on enrollee_doc_list.id  = enrollee_information.id \
                        \nWHERE (atestat = 1 AND enrollee_information.spec_num = " + std::to_string(spec_list_.at(spec_select_box_ -> currentIndex()).first) + "))  as num_of_orig_atestat";

    auto res = db_handler_ -> queryToDb(str);
    table_ -> setRowCount(0);
    while(res -> next())
    {
        table_->setRowCount(table_ -> rowCount() + 1);
        table_ -> setItem(table_ -> rowCount() - 1, 0, new QTableWidgetItem(QString::fromUtf8(res -> getString(1).asStdString().c_str())));
        table_ -> setItem(table_ -> rowCount() - 1, 1, new QTableWidgetItem(QString::fromUtf8(res -> getString(2).asStdString().c_str())));
        table_ -> setItem(table_ -> rowCount() - 1, 2, new QTableWidgetItem(QString::fromUtf8(res -> getString(3).asStdString().c_str())));
        table_ -> setItem(table_ -> rowCount() - 1, 3, new QTableWidgetItem(QString::fromUtf8(res -> getString(4).asStdString().c_str())));
        table_ -> setItem(table_ -> rowCount() - 1, 4, new QTableWidgetItem(QString::fromUtf8(res -> getString(5).asStdString().c_str())));
    }

}
