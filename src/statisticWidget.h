#ifndef STATISTICWIDGET_H
#define STATISTICWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include "dbmaneger.h"
#include "potentioalStudentsWidget.h"

class StatisticWidget : public QWidget
{
    Q_OBJECT
public:
    StatisticWidget(QWidget* parent);

    void setDbHandler(DbManeger* handl);

public slots:
        void init();
        void update();
        void showStudentWidget();

private:
    QTableWidget* table_;
    QComboBox* spec_select_box_;
    QGridLayout* layout_;

    DbManeger* db_handler_;
    std::vector< std::pair< int, std::string > > spec_list_;

    PotentioalStudentsWidget* student_widget_;
    QPushButton* show_student_widget_;

};

#endif // STATISTICWIDGET_H
