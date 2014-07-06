/*
 * ConsoleLogger.cpp
 *
 *  Created on: Jul 6, 2014
 *      Author: user1
 */

#include "ConsoleLogger.h"

void ConsoleLogger::logDebug(const std::string message) {
    logInfo(message);
}

void ConsoleLogger::logInfo(const std::string message) {
    std::cout << message << std::endl;
}

void ConsoleLogger::logError(const std::string message) {
    std::cerr << message << std::endl;
}

void ConsoleLogger::logError(const std::string title, const std::string message) {
    std::cerr << title << ": " << message << std::endl;
}
