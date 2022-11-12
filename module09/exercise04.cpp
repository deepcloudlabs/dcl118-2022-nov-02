#include <iostream>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

int main() {
    mongocxx::instance inst{};
    mongocxx::client connection{mongocxx::uri{}};
    auto crmdb = connection["crmdb"];
    auto customers = crmdb["customers"];
    auto result = customers.update_many(
            bsoncxx::builder::stream::document{}
                    << "birth_year" << bsoncxx::builder::stream::open_document
                    << "$gt" << 1970
                    << bsoncxx::builder::stream::close_document
                    << bsoncxx::builder::stream::finalize,
            bsoncxx::builder::stream::document{}
                    << "$set" << bsoncxx::builder::stream::open_document
                    << "email" << "hr@example.com"
                    << "phone" << "5555555"
                    << bsoncxx::builder::stream::close_document
                    << bsoncxx::builder::stream::finalize
                    );
    return 0;
}