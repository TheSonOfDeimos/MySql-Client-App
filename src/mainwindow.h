#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTabWidget>
#include <string>

#include "loginwidget.h"
#include "enrolleetable.h"
#include "dbmaneger.h"
#include "specTableWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();

private:

    QTabWidget* tab_;
    LoginWidget* login_widget_;
    EnrolleeTable* enrollee_table_;
    SpecTableWidget* spec_table_;

    DbManeger* db_handler_;

};

#endif // MAINWINDOW_H
