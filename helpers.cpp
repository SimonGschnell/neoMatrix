//
// Created by simon on 16.03.24.
//
#include <thread>
#include <chrono>
#include "helpers.h"
#include <cstdint>

namespace helpers {

    void sleep(int seconds){
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
    }
    int8_t random_number(int start,int end){
        std::uniform_int_distribution<> dis{start, end}; // Define a distribution (e.g., uniform integer distribution)
        return dis(gen);
    }
} // helpers