//
// Created by simon on 15.03.24.
//

#ifndef NEOMATRIX_MATRIXCHARACTER_H
#define NEOMATRIX_MATRIXCHARACTER_H

#include <ncurses.h>

class MatrixCharacter{
private:
    char m_character{};
    int m_speed{};
    int m_pos_x{};
    int m_pos_y{};
    int m_counter{};

    // private member functions

public:
    MatrixCharacter(int y,int x, int speed): m_speed{speed}, m_pos_x{x}, m_pos_y{y} {};

    // public member functions
    std::thread spawn();
    void printCharacter();
};

#endif //NEOMATRIX_MATRIXCHARACTER_H
