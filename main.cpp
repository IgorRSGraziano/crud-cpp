#include <iostream>
#include <mysql/mysql.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct mysql_config
{
    string host;
    string user;
    string password;
    string database;
    string port;
} config;

vector<string> split(const string &s, char delim)
{
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }

    return result;
}

void read_config_file()
{
    ifstream file("conn.cfg");
    std::map<string, string> map;
    if (file.is_open())
    {
        while (file.good())
        {
            string line;
            getline(file, line);
            vector<string> tokens = split(line, '=');
            if (!tokens.size() == 2)
                continue;
            map[tokens[0]] = tokens[1];
        }
    };
    config.database = map["DATABASE"];
    config.host = map["HOST"];
    config.port = map["PORT"];
    config.user = map["USER"];
    config.password = map["PASSWORD"];
}

int main()
{
    string test = "test";
    string *ref = &test;
    read_config_file();
    cout << config.database;
    MYSQL *conn;

    return 0;
}