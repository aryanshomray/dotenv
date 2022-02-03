#ifndef DOTENV_LIBRARY_H
#define DOTENV_LIBRARY_H

#include <string>


class dotenv{
public:
    dotenv();
    explicit dotenv(const std::string& path);

    dotenv(const std::string &path, bool overwrite);

    [[maybe_unused]] static void strip(std::string &line);
    static bool isComment(const std::string &line);
};

#endif //DOTENV_LIBRARY_H
