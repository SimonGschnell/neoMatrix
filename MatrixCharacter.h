//
// Created by simon on 15.03.24.
//

#ifndef NEOMATRIX_MATRIXCHARACTER_H
#define NEOMATRIX_MATRIXCHARACTER_H

#include <cstdint>
#include <functional>
#include <ncurses.h>

class MatrixCharacter {
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
  std::mutex &_m;
  int m_screen_x{};
  int m_screen_y{};

  // private member functions
  void printCharacter();

  char32_t iterateCharacter(char32_t) const;

  void moveDown();

public:
  MatrixCharacter(std::mutex &mutex_pointer, int y, int x, int offset,
                  int speed, int max_line_length = 6,
                  int screen_y = 0, int screen_x = 0)
      : _m{mutex_pointer}, m_character{static_cast<char32_t>(offset)},
        m_original_offset{offset}, m_x{x}, m_y_end{y}, m_speed{speed},
        m_max_line_length{max_line_length}, m_screen_x{screen_x},
        m_screen_y{screen_y}{};

  // public member functions
  void loop();
};

#endif // NEOMATRIX_MATRIXCHARACTER_H
