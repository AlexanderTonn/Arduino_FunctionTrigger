/**
 * @file funcTrigger.hpp
 * @author Alexander Tonn 
 * @brief 
 * @version 1.0
 * @date 2024-07-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <Arduino.h>

class timer
{
    private: 
    uint32_t mTimestamp = 0; 

    enum class objectUsage
    {
        NONE,
        CYCLIC_MODE,
        DELAY_MODE
    };
    objectUsage mUsage = objectUsage::NONE; //Flag for blocking other functions if one time functions is used in this object

    public: 
    auto cyclic(const uint32_t ) -> bool;
    auto delayOn(const uint32_t, const bool) -> bool;
};

#endif // TIMER_HPP