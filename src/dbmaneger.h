#ifndef DBMANEGER_H
#define DBMANEGER_H

#include <QApplication>
#include <mysql.h>
#include <iostream>
#include <QObject>
#include <string>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <string>

class DbManeger
{
public:
    DbManeger(QObject* parent);

    void connect(std::string host, std::string user, std::string pass);
    void setShema(std::string shema);
    std::shared_ptr< sql::ResultSet > queryToDb(std::string stm);

    // Modify methods
    void addEnrollee(int id, std::string f_name, std::string s_name, int score, int spec);
    void addPersonalInfo(int id, int pass, std::string date, std::string place, std::string addr);

    // View methods
    std::shared_ptr< sql::ResultSet > selectEnrolleBySpec(int spec);


private:
    std::shared_ptr< sql::Connection > connection_handl_;
    sql::Driver* driver_;

    //tmp
    std::shared_ptr< sql::Statement > stmt_;
    std::shared_ptr< sql::ResultSet > res_;
};
#endif // DBMANEGER_H
