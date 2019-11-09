#ifndef PERSANALINFODLG_H
#define PERSANALINFODLG_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTableWidget>
#include "dbmaneger.h"

class PersanalInfoWidget : public QWidget
{
    Q_OBJECT
public:
    PersanalInfoWidget(QWidget* parent, int id);

    void init();
    void setDbHandler(DbManeger* handl);

private:
    std::vector< QLabel > label_vec_;

    QGridLayout* gl_;
    DbManeger* db_handler_;
    int id_;


};

#endif // PERSANALINFODLG_H
