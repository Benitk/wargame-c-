#pragma once

#include "Soldier.hpp"

class Paramedic : public Soldier{
  Paramedic();

  public:
    Paramedic(int h, int a, int p) : Soldier(h,a,p) {}
    Paramedic(int p) : Soldier(100,0,p) {}
    ~Paramedic(){}
    void ability (const std::pair<int,int> source, std::vector<std::vector<Soldier*>>& b) override{
    int player_num = b[source.first][source.second]->get_player();
    for(int i = source.first-1; i <= source.first+1; i++){
        for(int j = source.second-1; j <= source.second+1; j++){
          if((i >= 0 && i < b.size()) && (j >= 0 && j < b[0].size())){
                if(b[i][j] != nullptr && (i != source.first || j != source.second) 
                                    && b[i][j]->get_player() == player_num)
                    b[i][j]->set_healthBar(b[i][j]->get_healthstats());
          }
        }
    }
  }
};