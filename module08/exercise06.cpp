#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>

using namespace std;

int main() {
    sql::Driver *driver;
    driver = get_driver_instance();
    auto connection = driver->connect("tcp://127.0.0.1:3306","root","Secret_123");
    connection->setSchema("world");
    connection->setTransactionIsolation(sql::enum_transaction_isolation::TRANSACTION_REPEATABLE_READ);
    sql::PreparedStatement *queryStatement = connection->prepareStatement(
            "select co.name as country_name, ci.name as capital_name from Country co, City ci where co.capital = ci.id order by co.name"
               );
    auto resultSet = queryStatement->executeQuery();
    while (resultSet->next()){
        cout << resultSet->getString("country_name") << "\t"
             << resultSet->getString("capital_name") << endl;
    }
    delete queryStatement;
    delete connection;
    return 0;
}