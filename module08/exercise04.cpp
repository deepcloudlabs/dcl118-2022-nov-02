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
            "update customers "
               "set email = concat(email,'.tr')"
               );
    auto rowsUpdated = dmlStatement->executeUpdate();
    cout <<  rowsUpdated << " row(s) are updated." << endl;
    delete dmlStatement;
    delete connection;
    return 0;
}