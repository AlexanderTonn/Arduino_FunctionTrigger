#include "funcTrigger.hpp"
/**
 * @brief use this for executing specific code at a specific time
 * @note you only can use this function once per loop (otherwise you will have unexpected behaviour)
 * @note if you want to trigger more than one functions, you have to declare more FunctionTrigger objects
 * @return true 
 */
auto FunctionTrigger::functionTrigger(const uint32_t targetTime) -> bool
{
    uint16_t millisTemp = millis() - mTimestamp;

    if (millisTemp >= targetTime)
    {
        mTimestamp += targetTime;
        return true;
    }
    else
        return false;
}