#pragma once

#include "FootSoldier.hpp"

class FootCommander  : public FootSoldier{
  FootCommander ();

  public:
      FootCommander (int p) : FootSoldier(150,20,p) {}
      ~FootCommander(){}

      void ability (const std::pair<int,int> source, std::vector<std::vector<Soldier*>>& b) override{
        int player_num = b[source.first][source.second]->get_player();
        FootSoldier::ability(source, b);
        for(int i = 0; i < b.size(); i++){
          for(int j = 0; j < b[0].size(); j++){
              if(b[i][j] != nullptr && b[i][j]->get_player() == player_num && (i != source.first || j != source.second)){
                if(FootSoldier* s = dynamic_cast<FootSoldier*>(b[i][j])){
                  std::pair<int,int> curr = {i,j};
                  b[i][j]->ability(curr,b);
                }
              }
          }
        }
      }   
};