//
// Created by simon on 15.03.24.
//

#ifndef NEOMATRIX_MATRIXCHARACTER_H
#define NEOMATRIX_MATRIXCHARACTER_H
#include <random>

class MatrixCharacter{
private:
    char m_character{};
    int m_speed{};
    int m_counter{};
    std::random_device rd;  // Obtain a random seed from the operating system
    std::mt19937 gen{rd()}; // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis{0, 9}; // Define a distribution (e.g., uniform integer distribution)
public:
    MatrixCharacter(int speed): m_speed{speed} {};
    void printCharacter();
    std::thread spawn();
};

#endif //NEOMATRIX_MATRIXCHARACTER_H
