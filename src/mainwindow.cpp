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
    spec_table_ = new SpecTableWidget(this);
    statistic_table_ = new StatisticWidget(this);



    connect(login_widget_, SIGNAL(connected_signal()), enrollee_table_, SLOT(init()));
    connect(login_widget_, SIGNAL(connected_signal()), spec_table_, SLOT(init()));
    connect(login_widget_, SIGNAL(connected_signal()), statistic_table_, SLOT(init()));

    enrollee_table_ -> setDbHandler(db_handler_);
    spec_table_ -> setDbHandler(db_handler_);
    statistic_table_ -> setDbHandler(db_handler_);

    tab_ -> addTab(login_widget_, "Log in");
    tab_ -> addTab(enrollee_table_, "Main table");
    tab_ -> addTab(spec_table_, "Specialisations");
    tab_ -> addTab(statistic_table_, "Statistic");
    setCentralWidget(tab_);
}

