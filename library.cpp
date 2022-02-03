#include "library.h"

#include <fstream>
#include <boost/algorithm/string.hpp>

dotenv::dotenv():dotenv("./.env") {}

dotenv::dotenv(const std::string &path):dotenv(path, false) {}

dotenv::dotenv(const std::string& path, bool overwrite) {
    std::ifstream envVar(path);
    std::string line;

    while(getline(envVar, line)){
        if(!line.length())continue;
        boost::trim(line);
        if (isComment(line))[[unlikely]]continue;
        std::vector<char *>res;
        boost::split(res, line, boost::is_any_of("="));
        if (res.size()==1){
            setenv(res[0], "", overwrite);
        }else if(res.size()==2)[[likely]]{
            setenv(res[0], res[1], overwrite);
        }else{

        }
    }
}

[[maybe_unused]] void dotenv::strip(std::string &line) {
     boost::trim(line);
}

bool dotenv::isComment(const std::string& line) {
    if(!line.length()) return true;
    if(line[0]=='#')return true;
    return false;
}

