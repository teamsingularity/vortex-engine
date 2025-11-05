#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <defines.hpp>
#include <string>
#include <vector>

/**
 * @brief Logger system.
 */
class VORTEXAPI Logger
{
public:
    /**
     * @brief Log an info message.
     * @param text Message text.
     */
    static void info(std::string text);

    /**
     * @brief Log a warning message.
     * @param text Message text.
     */
    static void warn(std::string text);

    /**
     * @brief Log an error message.
     * @param text Message text.
     */
    static void error(std::string text);

    /**
     * @brief Log an error message and destroy engine.
     * @param text Message text.
     */
    static void critical(std::string text);

    /**
     * @brief Clear logs collection.
     */
    static void clear();

    /**
     * @brief A logs collection.
     */
    static std::vector<std::string> logs;
};

#endif //LOGGER_HPP