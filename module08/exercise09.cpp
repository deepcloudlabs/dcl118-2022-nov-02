#include <iostream>
#include <cppconn/driver.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
using namespace std;
// Flat Model: 1 Connection at most 1 TX
// ANSI SQL Standard
// begin
// commit
// rollback

// no isolation:
// set session transaction isolation level read uncommitted;

// set session transaction isolation level read committed;
// set session transaction isolation level repeatable read;
// set session transaction isolation level serializable;
// select @@tx_isolation;

int main() {
    sql::Driver *driver;
    sql::Connection *con;
    try {
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306","root","Secret_123");
        con->setTransactionIsolation(sql::enum_transaction_isolation::TRANSACTION_READ_COMMITTED);
        con->setSchema("test");
        // start transaction
        con->setAutoCommit(false);
       // execute DML sql statements
        sql::PreparedStatement *prepStatement = con->prepareStatement(
                "insert into employees values( '100', 'Jack Bauer', 30000),( '200', 'Kate Austen', 40000)"
        );
        auto rowsAdded = prepStatement->executeUpdate();
        cout << rowsAdded << " row(s) are inserted!" << endl;
        con->commit();
    }catch (sql::SQLException &e){
        con->rollback();
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}