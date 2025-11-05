#include "logger.hpp"
#include <engine/engine.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>

std::vector<std::string> Logger::logs;

std::string getTime()
{
    using namespace std::chrono;

    // Get current time
    auto now = system_clock::now();

    // Convert to time_t to get calendar time (hours, minutes, seconds)
    std::time_t t = system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);

    // Extract milliseconds
    auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

    std::stringstream out;

    // Print formatted time
    out << std::put_time(&tm, "%H:%M:%S")
              << "." << std::setfill('0') << std::setw(3) << ms.count();
    
    return out.str();
}

void Logger::info(std::string text)
{
    std::stringstream log;
    log << "[INFO]     [" << getTime() << "] " << text;
    logs.push_back(log.str());
    std::cout << log.str() << std::endl;
}

void Logger::warn(std::string text)
{
    std::stringstream log;
    log << "[WARNING]  [" << getTime() << "] " << text;
    logs.push_back(log.str());
    std::cout << log.str() << std::endl;
}

void Logger::error(std::string text)
{
    std::stringstream log;
    log << "[ERROR]    [" << getTime() << "] " << text;
    logs.push_back(log.str());
    std::cout << log.str() << std::endl;
}

void Logger::critical(std::string text)
{
    std::stringstream log;
    log << "[CRITICAL] [" << getTime() << "] " << text;
    logs.push_back(log.str());
    std::cout << log.str() << std::endl;
    Engine::destroy();
}