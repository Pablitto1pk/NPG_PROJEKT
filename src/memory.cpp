#include "memory.hpp"



game::game() { //konstruktor
   fill_list();

}

void game::fill_list() {
   list_p.resize(3); // nie usuwajcie tego bron boze, 30min walczylem z problemem z pamiecia

   list_p[0] = {"ez1","ez2","ez3"};
   list_p[1] = {"m1","m2","m3"};
   list_p[2] = {"h1","h2","h3"};
}
int game::get_level() {
   return diff_lv;
}
void game::set_level(int n) {
   diff_lv = n;
}

uint game::pass_count(uint n) const {
  switch (n) {
     case 0:
        return list_p[0].size();
     case 1:
        return list_p[1].size();
     case 2:
        return list_p[2].size();
     default:
        return 0;
  }
}

std::string game::get_pass() {
   uint lv = uint(get_level());
   if (lv < 0 || lv >= list_p.size()) { // zabezpieczenie gdyby lv przekroczyl ilosc naszych poziomow trudnosci
      return "";
   }
   if (pass_count(lv) <= 0) { // zabezpieczenie gdyby bylo 0 haseł
      return "";
   }

   std::random_device rnd;  // generator liczb losowych
   std::mt19937 gen(rnd()); // generator Mersenne Twister
   std::uniform_int_distribution<> distrib(0, pass_count(lv) - 1);

   return list_p[lv][distrib(gen)];
}

