#pragma once

#include <iostream>
#include <exception>

class Soldier{
  int health_bar;
  int health_stats;
  int ability_stats;
  int player;

  Soldier();
  
  public:
      Soldier(int h, int a, int p) : health_bar(h), health_stats(h), ability_stats(a), player(p){}

      int get_healthBar() const { return health_bar;}
      int get_healthstats() const{ return health_stats;}
      int get_abilitystats() const{ return ability_stats;}
      int get_player() const { return player;}

      void set_healthBar(int new_health){health_bar = new_health;}

      virtual ~Soldier(){}
      virtual void ability(const std::pair<int,int> source, std::vector<std::vector<Soldier*>>& b) = 0; 
};