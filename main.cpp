#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "MatrixCharacter.h"
#include <ncurses.h>
#include "helpers.h"
#include <memory>

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


    std::vector<std::unique_ptr<std::thread>> pool{};

    // test with single thread
    /*MatrixCharacter mc_thread{0,0,helpers::random_number(1,5)};
    std::thread t =mc_thread.spawn();
    t.join();*/

    for(int i{0}; i< 3 ; i++ ){

        pool.push_back(std::make_unique<std::thread>(MatrixCharacter{0,i,helpers::random_number(1,5)}.spawn()));
    }


    for(auto& th : pool){
           th->join();
    }

    //std::cout << "Hello, World!" << std::endl;
    //system("../fetch.sh > ../fetch.txt");





    // Wait for user input
    getch();

    // End ncurses
    endwin();

    return 0;
}
