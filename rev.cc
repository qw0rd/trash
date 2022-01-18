#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    json j{{"name", "David"}, {"age", 20}};
    std::cout << to_string(j) << "\n";
}
