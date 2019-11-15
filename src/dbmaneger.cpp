#include "dbmaneger.h"

DbManeger::DbManeger(QObject* parent)
{

}

void DbManeger::connect(std::string host, std::string user, std::string pass)
{
    try {
        driver_ = get_driver_instance();
        //connection_handl_ = std::shared_ptr< sql::Connection >(driver_->connect(host, user, pass));
        connection_handl_ = std::shared_ptr< sql::Connection >(driver_->connect("127.0.0.1:3306", "root", "xmg2-Lev"));
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

void  DbManeger::callToDb(std::string stm)
{
    try {
        stmt_ = std::shared_ptr< sql::Statement >(connection_handl_->createStatement());
        stmt_->execute(stm);
        std::clog << "[ OK ] Query proceseed "  << stm << "\n";
    } catch (sql::SQLException& e) {
        std::cerr << "[ ER ] " << e.what() << "\n";
    }
}

void DbManeger::addEnrollee(int id, std::string f_name, std::string s_name, int score, int spec)
{
    std::string str = "CALL mydb.add_enrollee_info(" + std::to_string(id) + ", '" + f_name + "', '" + s_name +
            "', " + std::to_string(score) + ", " + std::to_string(spec) + ")";

    callToDb(str);
}

void DbManeger::addPersonalInfo(int id, int pass, std::string date, std::string place, std::string addr)
{
    std::string str = "CALL mydb.add_enrolle_private(" + std::to_string(id) + ", " + std::to_string(pass)  + ", '" + date  + "', '" + place  + "', '" + addr + "')";
    callToDb(str);
}

void DbManeger::addSpec(int id, std::string spec, int bp, int spp, int math, int physics, int bio, int chem)
{
    std::string str = "CALL mydb.add_new_spec(" + std::to_string(id) + ", '" + spec + "', " +
            std::to_string(bp) + ", " + std::to_string(spp) + ", " + std::to_string(math) + ", " +
            std::to_string(physics) + ", + " + std::to_string(bio) + ", " + std::to_string(chem) + ")";
   callToDb(str);
}

std::string const boolToString(bool b)
{
  return b ? "true" : "false";
}

void DbManeger::addDocs(int id, bool atestat, bool pass, bool med_form)
{
    std::string str = "CALL mydb.add_doc_list(" +  std::to_string(id) + "," + boolToString(atestat) + "," +  boolToString(pass) + "," + boolToString(med_form) + ")";
    callToDb(str);
}

void DbManeger::addExamScore(int id, int math, int phy, int bio, int chem, int his, int rus, int en)
{
    std::string str = "call mydb.add_score(" + std::to_string(id) + "," +  std::to_string(math) + "," +
            std::to_string(phy) + "," + std::to_string(bio) + "," + std::to_string(chem) + "," +
            std::to_string(his) + "," + std::to_string(rus) + "," + std::to_string(en) + ")";
    callToDb(str);

}

void DbManeger::addAllEnrolleeInfo(int id, std::string f_name, std::string s_name, int score, int spec,
                        int pass, std::string date, std::string place, std::string addr,
                        bool atestat, bool pass_cpy, bool med_form,
                        int math, int phy, int bio, int chem, int his, int rus, int en)
{
    std::string str = "CALL mydb.add_all_enrollee_info(" +
            std::to_string(id) + ", '" + f_name + "', '" + s_name + "', " + std::to_string(score) + ", " + std::to_string(spec) + ", " +
            std::to_string(pass)  + ", '" + date  + "', '" + place  + "', '" + addr + "', " +
            boolToString(atestat) + "," +  boolToString(pass_cpy) + "," + boolToString(med_form) + ", " +
            std::to_string(math) + "," + std::to_string(phy) + "," + std::to_string(bio) + "," + std::to_string(chem) + "," + std::to_string(his) + "," + std::to_string(rus) + "," + std::to_string(en) +
            ")";
     callToDb(str);

}

std::shared_ptr< sql::ResultSet > DbManeger::selectEnrolleBySpec(int spec)
{
    std::string str = "SELECT * FROM mydb.enrollee_information WHERE spec_num=" + std::to_string(spec) + "\nORDER BY second_name";
    return queryToDb(str);
}
