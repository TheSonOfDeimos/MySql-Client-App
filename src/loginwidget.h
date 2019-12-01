#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <string>
#include "dbmaneger.h"
#include "registerWidget.h"

class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    LoginWidget(QWidget* parent);

    void setDbHandler(DbManeger* handl);

    std::string getHost();
    std::string getUser();
    std::string getPassword();
    std::string getDbName();

public slots:
    void connectToDb();
    void showRegisterUser();

signals:
    void connected_signal();

private:
    QGridLayout* grid_layout_;
    QPushButton* button_connect_;
    QPushButton* button_register_;
    QLineEdit* host_line_edit_;
    QLineEdit* user_line_edit_;
    QLineEdit* password_line_edit_;
    QLineEdit* db_name_line_edit_;

    DbManeger* db_handler_;
    RegisterWidget* register_dlg_;

};
#endif // LOGINWIDGET_H
