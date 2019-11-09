#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
}

MainWindow::~MainWindow()
{

}

void  MainWindow::init()
{

    tab_ = new QTabWidget(this);

    db_handler_ = new DbManeger(this);

    login_widget_ = new LoginWidget(this);
    login_widget_ -> setDbHandler(db_handler_);

    enrollee_table_ = new EnrolleeTable(this);

    connect(login_widget_, SIGNAL(connected_signal()), enrollee_table_, SLOT(init()));
    enrollee_table_ -> setDbHandler(db_handler_);

    tab_ -> addTab(login_widget_, "Log in");
    tab_ -> addTab(enrollee_table_, "Main table");
    setCentralWidget(tab_);


}

