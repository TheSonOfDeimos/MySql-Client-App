#ifndef STATISTICWIDGET_H
#define STATISTICWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include "dbmaneger.h"

class StatisticWidget : public QWidget
{
    Q_OBJECT
public:
    StatisticWidget(QWidget* parent);

    void setDbHandler(DbManeger* handl);

public slots:
        void init();
        void update();

private:
    QTableWidget* table_;
    QComboBox* spec_select_box_;
    QHBoxLayout* layout_;

    DbManeger* db_handler_;
    std::vector< std::pair< int, std::string > > spec_list_;

};

#endif // STATISTICWIDGET_H
