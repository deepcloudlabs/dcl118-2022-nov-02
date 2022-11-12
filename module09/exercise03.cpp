#include <iostream>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

int main() {
    mongocxx::instance inst{};
    mongocxx::client connection{mongocxx::uri{}};
    auto crmdb = connection["crmdb"];
    auto customers = crmdb["customers"];
    auto result = customers.delete_many(
            bsoncxx::builder::stream::document{}
                    << "birth_year" << bsoncxx::builder::stream::open_document
                    << "$lt" << 1990
                    << bsoncxx::builder::stream::close_document
                    << bsoncxx::builder::stream::finalize);
    return 0;
}