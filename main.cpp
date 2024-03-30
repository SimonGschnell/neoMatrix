#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "MatrixCharacter.h"
#include <ncurses.h>
#include "helpers.h"
#include <memory>
#include <mutex>
#include <thread>
#include <cstdint>

std::mutex _m;

void testPrint(int y, int x,char32_t text, int time){
    std::unique_lock<std::mutex> lock(_m);
    mvprintw(y,x,"%c",text);
    refresh();
    lock.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds (200));

}

void testLoop(int y, int x,char32_t text, int time){
    for(std::size_t index{0}; index < 100 ; index++){
        testPrint(y, x, (char32_t)(160+index), time);
    }

}

int main() {

    // Initialize ncurses
    initscr();
    raw(); // takes special characters as raw characters
    cbreak(); // allows the user to end the programm with ctrl + c
    noecho(); // does not output keystrokes from the user to the screen
    /*
    // Print some text
    printw("Hello, world!");

    // Move cursor to specific position
    mvprintw(1,4,"a");
    refresh();
    sleep(2);
    mvprintw(1,4,"b");
    refresh();
    sleep(2);
    mvprintw(1,4,"c");
    refresh();
    sleep(2);
    // Print spaces to overwrite characters at the specific position
    printw("x"); // Overwrite 6 characters

    // Refresh the screen
    refresh();

    WINDOW *win {newwin(10,20,10,10)};
    refresh();
    sleep(2);
    box(win,0,0);
    wrefresh(win);
    sleep(2);
    mvwprintw(win,1,1,"inside Window");
    wrefresh(win);*/

    //
    std::vector<MatrixCharacter> matrixCharacters{};
    std::vector<std::thread> pool{};
    //

    // test with single thread
    /*MatrixCharacter mc_thread{0,0,helpers::random_number(1,5)};
    std::thread t =mc_thread.spawn();
    t.join();*/



    /*for(int x{0}; x< 100 ; x++ ){
    //48,57
        MatrixCharacter& mc {matrixCharacters.emplace_back(_m,helpers::random_number(0,25),x,helpers::random_number(48,100), helpers::random_number(1,25))};
        pool.emplace_back(&MatrixCharacter::loop,mc);
    }*/
    int x{};
    int y{};
    getmaxyx(stdscr,y,x);

    mvprintw(41,100,"%s","this is a test");
    mvprintw(1,1,"x: %d y: %d",x,y);
    refresh();




    for(auto& th : pool){
           th.join();
    }

    //std::cout << "Hello, World!" << std::endl;
    //system("../fetch.sh > ../fetch.txt");





    // Wait for user input
    getch();

    // End ncurses
    endwin();

    return 0;
}
