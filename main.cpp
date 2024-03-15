#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "MatrixCharacter.h"


int main() {

    std::vector<std::thread> pool{};
    MatrixCharacter c{300};

    for(int i{0}; i< 5 ; i++ ){
        pool.emplace_back(c.spawn());
    }
    std::this_thread::sleep_for(std::chrono::seconds(20));


    std::cout << "Hello, World!" << std::endl;
    system("../fetch.sh > ../fetch.txt");
    return 0;
}
