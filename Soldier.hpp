#pragma once

#include <iostream>
#include <exception>

class Soldier{
  uint health_bar;
  uint health_stats;
  uint ability_stats;
  uint player;

  Soldier();
  
  public:
      Soldier(uint h, uint a, uint p) : health_bar(h), health_stats(h), ability_stats(a), player(p){}

      uint get_healthBar() const { return health_bar;}
      uint get_healthstats() const{ return health_stats;}
      uint get_abilitystats() const{ return ability_stats;}
      uint get_player() const { return player;}

      void set_healthBar(uint new_health){health_bar = new_health;}

      virtual ~Soldier(){}
      virtual void ability(const std::pair<int,int> source, std::vector<std::vector<Soldier*>>& b) = 0; 
};