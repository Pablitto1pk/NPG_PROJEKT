#include "memory.hpp"



game::game() { //konstruktor
   fill_list();

}

void game::fill_list() {
   list_p.resize(3); // nie usuwajcie tego bron boze, 30min walczylem z problemem z pamiecia

   list_p[0] = {"skibidi","mkap","jo9s","tash", "womp","duse","hdni","weiu","meow","aeid","erfj","qyau", "uedn", "xqwu",
   "xnwe", "woei", "ower","bfgr", "cbew","sylus","gojo","bvus","asod","tcnt","soro"};
   list_p[1] = {"wpmr3","ncw3u","cber8","uryg4","k2asr","c3gpr","mqxf0","woie5", "coe4d", "qxmo3", "vfio8", "nc0we", "pweo3", "nfcu3",
   "nv3si", "awie3", "3urdn", "qo3ir", "nx9wo", "x2drn", "4xiwr", "nrbf8", "xb7w6", "xn237", "yr4fe"};
   list_p[2] = {"437r6q","mx3ur9","fjw0q2", "47rr9d", "cnmh94", "cn947q", "f938dw", "irj93q", "gw8res", "nw48wp", "rydiq2", "iureh3",
   "49tjwq", "b273der", "ngowi4", "lek4tr", "3498th", "MFR4c0","IUSD39", "HU34dw", "uWNo3w", "EIb2sr", "c2TY7q", "YHwb2f", "SYgoRa"};
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

