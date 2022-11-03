
#include <map>
#include <string>
#include <iostream>

int main() {
    std::map<std::string, int> area_codes{
            {"ankara",           312},
            {"istanbul-anadolu", 216},
            {"istanbul-avrupa",  212}
    };
    std::cout << "ankara -> " << area_codes["ankara"] << std::endl;
    area_codes["izmir"] = 232;
    area_codes.insert(std::pair<std::string, int>("antalya", 242));
    auto antalya_pair = area_codes.find("antalya");
    if (antalya_pair == area_codes.end())
        std::cout << "Cannot find antalya" << std::endl;
    else
        std::cout << antalya_pair->second << std::endl;
    for (const auto &key_value : area_codes){
        std::cout << key_value.first << ": " << key_value.second <<std::endl;
    }
    // c++17
    for (const auto& [key, value]: area_codes){
        std::cout << key << ": " << value <<std::endl;
    }
    for (
            auto p = area_codes.begin();
            p != area_codes.end();
            p++
    ){
        std::cout << p->first << ": " << p->second <<std::endl;
    }
    return 0;
}
