#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>

using namespace std;

int main() {
    sql::Driver *driver;
    driver = get_driver_instance();
    auto connection = driver->connect("tcp://127.0.0.1:3306","root","Secret_123");
    connection->setSchema("crm");

    sql::PreparedStatement *queryStatement = connection->prepareStatement(
            "select * from customers "
               "limit 0,10"
               );
    auto resultSet = queryStatement->executeQuery();
    while (resultSet->next()){
        cout << resultSet->getString("id") << "\t"
             << resultSet->getString("fullname") << "\t"
             << resultSet->getString("email") << "\t"
             << resultSet->getInt("birth_year") << endl;
    }
    delete queryStatement;
    delete connection;
    return 0;
}