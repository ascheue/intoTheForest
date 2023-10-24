#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <mutex>

class Logger {
private:
    static Logger* instance;
    static std::mutex mtx;

    Logger();

public:
    static Logger* getInstance();
    Logger* log(const std::string& toWrite);
};

#endif  // LOGGER_H
