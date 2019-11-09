#ifndef SPECTABLEWIDGET_H
#define SPECTABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include "dbmaneger.h"
#include "addSpecWidget.h"

class SpecTableWidget : public QWidget
{
    Q_OBJECT
public:
    SpecTableWidget(QWidget* parent);
    void setDbHandler(DbManeger *handl);

public slots:
    void init();
    void update();
    void addSpec();

private:
    QTableWidget* table_;
    QPushButton* add_spec_button_;
    QPushButton* update_button_;

    QGridLayout* gl_;
    QVBoxLayout* vbl_;

    DbManeger* db_handler_;
    AddSpecWidget* add_spec_widget_;

};

#endif // SPECTABLEWIDGET_H
