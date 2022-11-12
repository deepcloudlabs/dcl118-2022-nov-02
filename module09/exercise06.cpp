#include <iostream>

#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;

int main(int, char**) {


    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};

    auto db = conn["world"];

    auto cursor = db["countries1"].find({});

    for (auto&& doc : db["countries1"].find(document {} << "continent" << "Asia" << finalize) ) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
}
