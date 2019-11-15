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
    void  callToDb(std::string stm);

    // Modify methods
    void addEnrollee(int id, std::string f_name, std::string s_name, int score, int spec);
    void addPersonalInfo(int id, int pass, std::string date, std::string place, std::string addr);
    void addSpec(int id, std::string spec, int bp, int spp, int math, int physics, int bio, int chem);
    void addDocs(int id, bool atestat, bool pass, bool med_form);
    void addExamScore(int id, int math, int phy, int bio, int chem, int his, int rus,  int en);
    void addAllEnrolleeInfo(int id, std::string f_name, std::string s_name, int score, int spec,
                            int pass, std::string date, std::string place, std::string addr,
                            bool atestat, bool pass_cpy, bool med_form,
                            int math, int phy, int bio, int chem, int his, int rus, int en);

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
