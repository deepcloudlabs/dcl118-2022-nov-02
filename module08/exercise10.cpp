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
                "select * from employees limit 10"
        );
        sql::ResultSet *resultSet = prepStatement->executeQuery();
        resultSet->first();
        do{
            cout << resultSet->getString("identity")
                 << "\t"
                 << resultSet->getString("fullname")
                 << "\t"
                 << resultSet->getString("salary")
                 << endl;
        } while (resultSet->next());
    }catch (sql::SQLException &e){
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}