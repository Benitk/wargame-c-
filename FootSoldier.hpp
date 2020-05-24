#pragma once

#include "Soldier.hpp"

class FootSoldier : public Soldier {
  FootSoldier();

  public:
      FootSoldier(uint h, uint a, uint p) : Soldier(h,a,p) {}
      FootSoldier(uint p) : Soldier(100,10,p) {}
      ~FootSoldier(){}
      
      void ability (const std::pair<int,int> source, std::vector<std::vector<Soldier*>>& b) override{
        int player_num = b[source.first][source.second]->get_player();
        for(int i = source.first-1; i <= source.first+1; i++){
          for(int j = source.second-1; j <= source.second+1; j++){
            if((i >= 0 && i < b.size()) && (j >= 0 && b[0].size())){
            //try{
              // dmg solider
              if(b[i][j] != nullptr && (i != source.first || j != source.second) 
                                    && b[i][j]->get_player() != player_num){
                b[i][j]->set_healthBar(b[i][j]->get_healthBar()-b[source.first][source.second]->get_abilitystats());
              
                // remove solider from board
                if(b[i][j]->get_healthBar() <= 0){
                  delete b[i][j];
                  b[i][j] = nullptr;
                }
              }
          //  }
            // catch(std::exception& e){
            // }
            }
        }
      }

    }
};