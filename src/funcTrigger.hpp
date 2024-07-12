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

#ifndef FUNCTION_TRIGGER_HPP
#define FUNCTION_TRIGGER_HPP

#include <Arduino.h>

class FunctionTrigger
{
    private: 
    uint32_t mTimestamp = 0; 

    public: 
    auto functionTrigger(const uint32_t ) -> bool;
};

#endif // FUNCTION_TRIGGER_HPP