//
// Created by simon on 15.03.24.
//

#ifndef NEOMATRIX_MATRIXCHARACTER_H
#define NEOMATRIX_MATRIXCHARACTER_H

#include <ncurses.h>
#include <cstdint>

class MatrixCharacter{
private:
    inline static unsigned int printCount{};
    inline static unsigned int matrixCharacterCount{};
    char32_t m_character{};
    int m_original_offset{};
    int m_speed{};
    int m_x{};
    int m_y_start{};
    int m_y_end{};
    int m_current_line_length{1};
    int m_max_line_length{};
    std::mutex& _m;

    // private member functions
    void printCharacter();
    char32_t iterateCharacter(char32_t ) const;
    void moveDown();

public:
    MatrixCharacter(std::mutex& mutex_pointer, int y,int x, int offset, int max_line_length = 6): _m{mutex_pointer}, m_character{static_cast<char32_t>(offset)}, m_original_offset{offset}, m_x{x}, m_y_end{y}, m_max_line_length{max_line_length} {};

    // public member functions
    void loop();
};

#endif //NEOMATRIX_MATRIXCHARACTER_H
