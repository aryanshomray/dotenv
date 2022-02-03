#ifndef DOTENV_LIBRARY_H
#define DOTENV_LIBRARY_H

#include <string>


class dotenv{
private:
    std::string path;
    bool overwrite;

public:
    dotenv();
    explicit dotenv(const std::string& path);

    dotenv(const std::string &path, bool overwrite);

    static void strip(std::string &line);
    static bool isComment(const std::string &line);
    void load();
};

#endif //DOTENV_LIBRARY_H
