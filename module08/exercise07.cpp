#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>

using namespace std;

int main() {
    sql::Driver *driver;
    driver = get_driver_instance();
    auto connection = driver->connect("tcp://127.0.0.1:3306","root","Secret_123");
    connection->setSchema("crm");
    connection->setAutoCommit(false);
    connection->setTransactionIsolation(sql::enum_transaction_isolation::TRANSACTION_READ_COMMITTED);
    // Flat Model: start transaction/commit/rollback/savepoint/rollbackToSavepoint
    try{
        sql::PreparedStatement *dmlStatement = connection->prepareStatement(
                "insert into customers(id,fullname,email,birth_year) "
                "values "
                "('11111111115', 'ben linus', 'ben.linus@example.com', 1956)"
        );
        auto rowsInserted = dmlStatement->executeUpdate();
        cout <<  rowsInserted << " row(s) are inserted." << endl;
        connection->commit();
        delete dmlStatement;
    }catch(sql::SQLException &e){
        cerr << "Error has occured: " << e.what() << endl;
        connection->rollback();
    }
    delete connection;
    return 0;
}