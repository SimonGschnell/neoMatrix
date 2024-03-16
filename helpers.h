//
// Created by simon on 16.03.24.
//

#ifndef NEOMATRIX_HELPERS_H
#define NEOMATRIX_HELPERS_H
#include <random>
#include <mutex>
namespace helpers {

    void sleep(int seconds);
    inline std::random_device rd;  // Obtain a random seed from the operating system
    inline std::mt19937 gen{rd()}; // Standard mersenne_twister_engine seeded with rd()
    int8_t random_number(int start,int end);

    // global mutex
    inline std::mutex g_mutex;

} // helpers

#endif //NEOMATRIX_HELPERS_H
