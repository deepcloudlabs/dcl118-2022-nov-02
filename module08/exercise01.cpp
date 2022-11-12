#include <iostream>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>


int main() {
    sql::Driver *driver;
    driver = get_driver_instance();
    auto connection = driver->connect("tcp://127.0.0.1:3306","root","Secret_123");
    connection->setSchema("crm");

    sql::Statement *ddlStatement = connection->createStatement();
    ddlStatement->execute("create table customers(id varchar(11) not null,"
                          " fullname varchar(32) not null,"
                          " email varchar(32) not null,"
                          " birth_year int(4) default 2000,"
                          " primary key(id)) "
                          " engine=innodb");
    return 0;
}