#include <iostream>
#include <bsoncxx/json.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/client.hpp>

int main() {
    mongocxx::instance inst{};
    mongocxx::client connection{mongocxx::uri{}};
    auto crmdb = connection["world"];
    auto countries = crmdb["countries1"];
    for (auto&& doc : countries.find(
            // {indepYear: {$gte: 1970}}
            bsoncxx::builder::stream::document{} << "indepYear" << bsoncxx::builder::stream::open_document
                                                 << "$gte" << 1970
                                                 << bsoncxx::builder::stream::close_document
             << bsoncxx::builder::stream::finalize)
    ){
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
    return 0;
}