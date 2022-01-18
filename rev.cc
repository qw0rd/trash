#include <iostream>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

using json = nlohmann::json;


struct user {
    std::string login;
    int id;
    std::string node_id;
    std::string url;
    int followers;
    int following;
};

void from_json(const json& j, user& u)
{
    j.at("login").get_to(u.login);
    j.at("id").get_to(u.id);
    j.at("node_id").get_to(u.node_id);
    j.at("url").get_to(u.url);
    j.at("followers").get_to(u.followers);
    j.at("following").get_to(u.following);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Usage: hain [shithub_username]\n";
        return 2;
    }
    
    std::string url = "https://api.github.com/users/";
    url.append(argv[1]);

    cpr::Response r = cpr::Get(cpr::Url{url});

    if (r.status_code != 200) {
        return 2;
    }

    json obj = json::parse(r.text);
    auto u = obj.get<user>();

    std::cout << "User-info\n";
    std::cout << "Login: " << u.login << "\n";
    std::cout << "ID: " << u.id << "\n";
    std::cout << "NODE ID: " << u.node_id << "\n";
    std::cout << "URL: " << u.url << "\n";
    std::cout << "FOLLOWERS: " << u.followers << "\n";
    std::cout << "FOLLOWING: " << u.following << "\n";

}
