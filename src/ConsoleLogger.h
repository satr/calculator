/*
 * ConsoleLogger.h
 *
 *  Created on: Jul 6, 2014
 *      Author: user1
 */

#ifndef CONSOLELOGGER_H_
#define CONSOLELOGGER_H_

#include "ILogger.h"

class ConsoleLogger: public virtual ILogger {
public:
    virtual void logDebug(const std::string message);
    virtual void logInfo(const std::string message);
    virtual void logError(const std::string message);
    virtual void logError(const std::string title, const std::string message);
};

#endif /* CONSOLELOGGER_H_ */
