//
// Created by simon on 15.03.24.
//
#include <thread>
#include <iostream>
#include <chrono>
#include <ncurses.h>
#include "MatrixCharacter.h"
#include "helpers.h"
#include <mutex>
#include <cmath>
#include <string>
#include <limits.h>

char32_t MatrixCharacter::iterateCharacter(char32_t current) const{
    if(((int)current) >= 100 ){
        return (char32_t)m_original_offset;
    }
    else{
        return ((int)current)+1;
    }
}

void MatrixCharacter::moveDown(){
// after printing a value to the screen the character is going down the y axis
    m_y_end++;
    m_current_line_length++;
    if(m_current_line_length > m_max_line_length ){
        std::unique_lock<std::mutex> lock(_m);
        mvprintw(m_y_start, m_x, "%c", ' ');
        m_y_start++;
        // also randomly change two other characters in the chain
       if(m_current_line_length> 4){
          //int8_t random1 =helpers::random_number(m_y_start,m_y_end);
          //int8_t random2 =helpers::random_number(m_y_start,m_y_end);
          mvprintw(11, m_x, "%c", (char32_t)(((int)m_character)-2));
          mvprintw(22, m_x, "%c", (char32_t)(((int)m_character)+3));
          mvprintw(33, m_x, "%c", (char32_t)(((int)m_character)+6));

        }
        lock.unlock();
    }




}

void MatrixCharacter::printCharacter() {

    std::unique_lock<std::mutex> lock(_m);
    //TODO: change printing character
    mvprintw(m_y_end, m_x, "%c", m_character);
    MatrixCharacter::printCount++;
    if(MatrixCharacter::printCount >= std::numeric_limits<unsigned int>::max()){
        MatrixCharacter::printCount=0;
    }
    if(MatrixCharacter::matrixCharacterCount > 100){
        if((MatrixCharacter::printCount % 5) == 0){
            refresh();
        }
    }else{
        refresh();
    }
    lock.unlock();
    MatrixCharacter::moveDown();
    m_character = iterateCharacter(m_character);
    std::this_thread::sleep_for(std::chrono::milliseconds (m_speed));

}

void MatrixCharacter::loop() {

    for(int index{0}; index < 2000 ; index++){
        // restart printing from the first row when y is greater equal screen y
        if(m_y_start >= m_screen_y){
          m_y_start=0;
        }
        if(m_y_end >= m_screen_y){
          m_y_end=0;
        }
        printCharacter();
    }
}




