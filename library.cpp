#include "library.h"

#include <fstream>
#include <boost/algorithm/string.hpp>

dotenv::dotenv():dotenv("./.env") {}

dotenv::dotenv(const std::string &path):dotenv(path, false) {}

dotenv::dotenv(const std::string& path, bool overwrite) {
    this->path = path;
    this->overwrite = overwrite;
}

void dotenv::strip(std::string &line) {
     boost::trim(line);
}

bool dotenv::isComment(const std::string& line) {
    if(!line.length()) return true;
    if(line[0]=='#')return true;
    return false;
}

void dotenv::load() {
    std::ifstream envVar(path);
    std::string line;

    while(getline(envVar, line)){
        if(!line.length())continue;
        strip(line);
        if (isComment(line))[[unlikely]]continue;
        std::vector<std::string>res;
        boost::split(res, line, boost::is_any_of("="));
        if (res.size()==1){
            strip(res[0]);
            setenv(&res[0][0], "", overwrite);
        }else if(res.size()==2)[[likely]]{
            strip(res[0]);
            strip(res[1]);
            setenv(&res[0][0], &res[1][0], overwrite);
        }
    }
}

