
#ifndef MEMORY_HPP
#define MEMORY_HPP
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <random>

using uint = unsigned int; // skraca pisanie

class game{
    std::vector<std::vector<std::string>> list_p;
    /* lista haseł wraz z poziomami trudnosci 1-latwy 2-sredni 3-trudny */



    int diff_lv=0; // ustawiany poziom trudnosci (bazowo easy zeby zapobiec bugom)
    std::vector<int> p_length;


public:
    game(); //konstruktor

    void fill_list(); // do wypelniania listy w memory.cpp
    int get_level(); // zwraca poziom trudnosci
    void set_level(int n); // funkcja ustawiania trudnosci
    uint pass_count(uint n) const; // zwraca ilosc hasel w kategori (potrzebne do losowania)

    std::string get_pass();



};
#endif //MEMORY_HPP
