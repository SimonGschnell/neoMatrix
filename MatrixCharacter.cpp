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
#include <string>
void MatrixCharacter::printCharacter() {
    helpers::g_mutex.lock();
    std::string s {"started"+std::to_string(m_pos_x)};
    char asdf[]{s[0],s[s.size()-1]};
    mvprintw(m_pos_x+1,0,"%s",asdf);
    helpers::g_mutex.unlock();
    int count{0};

    while (count < 10){
        //random character
        m_character =helpers::random_number(48,57);

        // aquire mutex
        helpers::g_mutex.lock();

        // print the character
        mvprintw(m_pos_y,m_pos_x, "%c", m_character);//std::to_string(m_pos_x)[0]



        refresh();
        // release mutex
        helpers::g_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count++;

    }
}

std::thread MatrixCharacter::spawn() {
    std::thread myTread(&MatrixCharacter::printCharacter, this);
    return myTread;
}