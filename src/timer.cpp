#include "timer.hpp"
/**
 * @brief use this for executing specific code at a specific time
 * @note you only can use this function once per loop (otherwise you will have unexpected behaviour)
 * @note if you want to trigger more than one functions, you have to declare more FunctionTrigger objects
 * @return true
 */
auto timer::cyclic(const uint32_t targetTime) -> bool
{
    if (mUsage == objectUsage::NONE)
        mUsage = objectUsage::CYCLIC_MODE;

    if (mUsage != objectUsage::CYCLIC_MODE)
    {
        if (Serial)
            Serial.println("Timer object is already in use: " + String(static_cast<int>(mUsage)));
        return false;
    }

    uint32_t millisTemp = millis() - mTimestamp;

    if (millisTemp >= targetTime)
    {
        mTimestamp += targetTime;
        return true;
    }
    else
        return false;
}
/**
 * @brief
 *
 * @param targetTime
 * @param reset
 * @return true
 * @return false
 */
auto timer::delayOn(const uint32_t targetTime, const bool active) -> bool
{
    if (mUsage == objectUsage::NONE)
        mUsage = objectUsage::DELAY_MODE;

    if (mUsage != objectUsage::DELAY_MODE)
    {
        if (Serial)
            Serial.println("Timer object is already in use: " + String(static_cast<int>(mUsage)));
        return false;
    }

    if (!active)
    {
        mTimestamp = millis();
        return false;
    }

    uint32_t millisTemp = millis() - mTimestamp;
    if (millisTemp >= targetTime)
    {
        return true;
    }
    else
        return false;
}