#include "dbmaneger.h"

DbManeger::DbManeger(QObject* parent)
{

}

void DbManeger::connect(std::string host, std::string user, std::string pass)
{
    try {
        driver_ = get_driver_instance();
        //connection_handl_ = std::shared_ptr< sql::Connection >(driver_->connect(host, user, pass));
        connection_handl_ = std::shared_ptr< sql::Connection >(driver_->connect("127.0.0.1:3306", "root", "qkbn-Lev"));
        std::clog << "[ OK ] Connected to data base with "  << host << " " << user << "\n";
    } catch (sql::SQLException &e) {
        std::cerr << "[ ER ] " << e.what() << "\n";
    }
}

void DbManeger::setShema(std::string shema)
{
    try {
        //connection_handl_ -> setSchema(shema);
        connection_handl_ -> setSchema("mydb");
        std::clog << "[ OK ] Set shema "  << shema << "\n";
    } catch (sql::SQLException &e) {
        std::cerr << "[ ER ] " << e.what() << "\n";
    }
}

std::shared_ptr< sql::ResultSet > DbManeger::queryToDb(std::string stm)
{
    try
    {
        connection_handl_ -> reconnect();
        stmt_ = std::shared_ptr< sql::Statement >(connection_handl_->createStatement());
        res_ = std::shared_ptr< sql::ResultSet >(stmt_->executeQuery(stm));
        std::clog << "[ OK ] Query proceseed "  << stm << "\n";
        return res_;
    } catch (sql::SQLException& e) {
        std::cerr << "[ ER ] " << e.what() << "\n";
    }
}

void DbManeger::addEnrollee(int id, std::string f_name, std::string s_name, int score, int spec)
{
    std::string str = "CALL mydb.add_enrollee_info(" + std::to_string(id) + ", '" + f_name + "', '" + s_name +
            "', " + std::to_string(score) + ", " + std::to_string(spec) + ")";
    try {
        stmt_ = std::shared_ptr< sql::Statement >(connection_handl_->createStatement());
        stmt_->execute(str);
        std::clog << "[ OK ] Query proceseed "  << str << "\n";
    } catch (sql::SQLException& e) {
        std::cerr << "[ ER ] " << e.what() << "\n";
    }
}

void DbManeger::addPersonalInfo(int id, int pass, std::string date, std::string place, std::string addr)
{
    std::string str = "CALL mydb.add_enrolle_private(" + std::to_string(id) + ", " + std::to_string(pass)  + ", '" + date  + "', '" + place  + "', '" + addr + "')";
    try {
        stmt_ = std::shared_ptr< sql::Statement >(connection_handl_->createStatement());
        stmt_->execute(str);
        std::clog << "[ OK ] Query proceseed "  << str << "\n";
    } catch (sql::SQLException& e) {
        std::cerr << "[ ER ] " << e.what() << "\n";
    }
}

std::shared_ptr< sql::ResultSet > DbManeger::selectEnrolleBySpec(int spec)
{
    std::string str = "select * from mydb.enrollee_information WHERE spec_num=" + std::to_string(spec) + "\nORDER BY second_name";
    return queryToDb(str);
}
