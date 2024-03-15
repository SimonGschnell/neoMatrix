//
// Created by simon on 15.03.24.
//
#include <thread>
#include <iostream>
#include <chrono>
#include "MatrixCharacter.h"
void MatrixCharacter::printCharacter() {
    int count{0};
    while (count < 10){

        // print the character
        std::cout << dis(gen) << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(m_speed));
        count++;

        // delete the old character
        std::cout << '\b';
    }
}

std::thread MatrixCharacter::spawn() {
    std::thread myTread(&MatrixCharacter::printCharacter, this);
    return myTread;
}