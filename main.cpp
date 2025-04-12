#include <iostream>
#include "memory.hpp"

int main() {
    game game;
    //testy funkcji obecnych
    std::cout << game.get_level() << std::endl; // domyslny 0
    game.set_level(1); // to bedziemy sie pozniej bawic implementacje
    std::cout << game.get_level() << std::endl; // teraz 1

    std::cout << game.get_pass() << std::endl; // powinno sie losowac z poziomu medium



    return 0;


}