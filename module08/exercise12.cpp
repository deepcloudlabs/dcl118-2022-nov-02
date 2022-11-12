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
                "delete from employees where salary > 50000"
        );
        auto employeesFired = prepStatement->executeUpdate();
        cout << employeesFired << " employees are fired!" << endl;
    }catch (sql::SQLException &e){
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}