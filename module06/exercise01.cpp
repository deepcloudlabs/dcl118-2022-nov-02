#include "city.h"
#include "country.h"
#include "world-util.h"

#include <iostream>
#include <memory>
#include <set>
#include <parallel/numeric>

using namespace std;
using namespace world;

std::map<int, std::shared_ptr<world::city>> cities;
std::map<std::string, std::shared_ptr<world::country>> countries;

int main() {
    create_world();
    set<string> continents;
    // external loop
    for (auto &a_country: countries) {
        continents.insert(a_country.second->continent);
    }
    for (auto &continent : continents){
        cout << continent << ", ";
    }
    cout << endl;
    // functional programming
    auto kitalar = accumulate(
      countries.begin(),
      countries.end(),
      set<string>(),
      [&](set<string> &conts,pair<const std::string, std::shared_ptr<world::country>> &a_country)
         -> set<string>& {
          conts.insert(a_country.second->continent);
          return conts;
      });
    return 0;
}