#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
using namespace std;

int main() {
    try {
        sql::Driver *driver;
        sql::Connection *con;
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306","root","Secret_123");
        con->setSchema("test");
        sql::PreparedStatement *prepStatement = con->prepareStatement(
                "create table employees ( identity varchar(11) not null, fullname varchar(32), salary float default 10000,primary key (identity)) engine=innodb"
        );
        prepStatement->executeUpdate();
    }catch (sql::SQLException &e){
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}