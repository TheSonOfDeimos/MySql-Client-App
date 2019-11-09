#ifndef ENROLLEETABLE_H
#define ENROLLEETABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QString>
#include <QComboBox>
#include <QDialog>
#include "personalInfoWidget.h"
#include "dbmaneger.h"
#include "addEnrolleeWidget.h"

class EnrolleeTable : public QWidget
{
    Q_OBJECT
public:
    EnrolleeTable(QWidget* parent);
    void setDbHandler(DbManeger* handl);

public slots:
    void init();
    void update();
    void addEnrolleeDlg();
    void showPersanalInfoDlg(QTableWidgetItem *item);

private:

    QTableWidget* table_;

    QVBoxLayout* vbl_;
    QHBoxLayout* layout_;

    QPushButton* update_button_;
    QPushButton* add_enrollee_button_;

    QComboBox* spec_select_box_;

    DbManeger* db_handler_;
    AddEnrolleeWidget* add_enrolle_widget_;
    PersanalInfoWidget* persanal_info_widget_;

    std::vector< std::pair< int, std::string > > spec_list_;


};

#endif // ENROLLEETABLE_H
