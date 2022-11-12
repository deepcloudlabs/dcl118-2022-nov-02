#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>

using namespace std;

int main() {
    sql::Driver *driver;
    driver = get_driver_instance();
    auto connection = driver->connect("tcp://127.0.0.1:3306","root","Secret_123");
    connection->setSchema("crm");

    sql::PreparedStatement *dmlStatement = connection->prepareStatement(
            "insert into customers(id,fullname,email,birth_year) "
               "values "
               "('11111111110', 'jack bauer', 'jack@example.com', 1956),"
               "('11111111113', 'james sawyer', 'james@example.com', 1984)"
               );
    auto rowsInserted = dmlStatement->executeUpdate();
    cout <<  rowsInserted << " row(s) are inserted." << endl;
    delete dmlStatement;
    delete connection;
    return 0;
}