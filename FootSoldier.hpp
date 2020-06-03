#pragma once

#include "Soldier.hpp"
#include<bits/stdc++.h>

class FootSoldier : public Soldier {
  FootSoldier();

  public:
      FootSoldier(int h, int a, int p) : Soldier(h,a,p) {}
      FootSoldier(int p) : Soldier(100,10,p) {}
      ~FootSoldier(){}
      
      void ability (const std::pair<int,int> source, std::vector<std::vector<Soldier*>>& b) override{
        float distance = INT_MAX;
        int iMostHp = -1;
        int jMostHp = -1;
        int player_num = b[source.first][source.second]->get_player();
        for(int i = 0; i < b.size(); i++){
          for(int j = 0; j < b[0].size(); j++){
              float d = sqrt(pow(i - source.first, 2) + pow(j - source.second, 2) * 1.0);
              if(b[i][j] != nullptr && (i != source.first || j != source.second) 
                && b[i][j]->get_player() != player_num){
                if(distance > d){
                  distance = d;
                  iMostHp = i;
                  jMostHp = j;
                  }
              }
          }
        }
              //if - checking validtion
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