#include <iostream>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

int main() {
    int x = 3, y = 5;
    int z = x + y;
    x++;
    mongocxx::instance inst{};
    mongocxx::client connection{mongocxx::uri{}};
    auto crmdb = connection["crmdb"];
    auto customers = crmdb["customers"];

    auto builder = bsoncxx::builder::stream::document{};
    auto jack = builder << "_id" << "11111111112"
                        << "fullname" << "kate austen"
                        << "email" << "kate@example.com"
                        << "birth_year" << 1986
                        << bsoncxx::builder::stream::finalize;

    auto result = customers.insert_one(jack.view());
    return 0;
}