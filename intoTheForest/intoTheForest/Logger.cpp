#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <mutex>

#include "Logger.h"
#include <iostream>
#include <fstream>
#include <ctime>

Logger* Logger::instance = nullptr;
std::mutex Logger::mtx;

Logger::Logger() {}

Logger* Logger::getInstance() {
    std::lock_guard<std::mutex> lock(mtx);
    if (!instance) {
        instance = new Logger();
    }
    return instance;
}

Logger* Logger::log(const std::string& toWrite) {
    std::ofstream logFile;
    logFile.open("consoleApp.log", std::ios_base::app); //Can change name of log file here 

    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    char buffer[80];

    strftime(buffer, sizeof(buffer), "%H:%M:%S", &ltm);
    std::string currentTime = buffer;

    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &ltm);
    std::string currentDate = buffer;

    //logFile << "\nLog Entry : ";
    logFile << currentTime << " " << currentDate;
    logFile << "  :";
    logFile << "  :" << toWrite << std::endl;

    logFile.close();
    return instance;
}







/*
class Logger {
private:
    static Logger* instance;
    static std::mutex mtx;

    Logger() {}

public:
    static Logger* getInstance() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!instance) {
            instance = new Logger();
        }
        return instance;
    }

    Logger* log(const std::string& toWrite) {
        std::ofstream logFile;
        logFile.open("Logger.log", std::ios_base::app); //Can change name of log file here 

        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);

        char buffer[80];

        strftime(buffer, sizeof(buffer), "%H:%M:%S", &ltm);
        std::string currentTime = buffer;

        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &ltm);
        std::string currentDate = buffer;

        logFile << "\nLog Entry : ";
        logFile << currentTime << " " << currentDate << std::endl;
        logFile << "  :" << std::endl;
        logFile << "  :" << toWrite << std::endl;
        logFile << "-------------------------------" << std::endl;

        logFile.close();
        return instance;
    }
};

Logger* Logger::instance = nullptr;
std::mutex Logger::mtx;
*/
