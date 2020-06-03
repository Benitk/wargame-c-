#pragma once

#include "Soldier.hpp"

class Sniper : public Soldier{
  Sniper();

  public:
      Sniper(int h, int a, int p) : Soldier(h,a,p) {}
      Sniper(int p) : Soldier(100,50,p) {}
      ~Sniper(){}
      void ability (const std::pair<int,int> source, std::vector<std::vector<Soldier*>>& b) override{
        int player_num = b[source.first][source.second]->get_player();
        int iMostHp = -1;
        int jMostHp = -1;
        uint Max = 0;
        for(int i = 0; i < b.size(); i++){
          for(int j = 0; j < b[0].size(); j++){
              if(b[i][j] != nullptr && (i != source.first || j != source.second) 
                                    && b[i][j]->get_player() != player_num){
                if(b[i][j]->get_healthBar() > Max){
                  Max = b[i][j]->get_healthBar();
                  iMostHp = i;
                  jMostHp = j;
                }
            }
          }
        } 
        // if - checking validtion
        if(iMostHp != -1 && jMostHp != -1){  
          b[iMostHp][jMostHp]->set_healthBar(b[iMostHp][jMostHp]->get_healthBar()-b[source.first][source.second]->get_abilitystats());
          // remove solider from board
          if(b[iMostHp][jMostHp]->get_healthBar() <= 0){

          delete b[iMostHp][jMostHp];
          b[iMostHp][jMostHp] = nullptr;
        }
      }
    }
};