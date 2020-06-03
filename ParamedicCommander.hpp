#pragma once

#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic{
  ParamedicCommander();

  public:
      ParamedicCommander  (int p) : Paramedic(200,0,p) {}
      ~ParamedicCommander (){}
      void ability (const std::pair<int,int> source, std::vector<std::vector<Soldier*>>& b) override{
        int player_num = b[source.first][source.second]->get_player();
        Paramedic::ability(source, b);
        for(int i = 0; i < b.size(); i++){
          for(int j = 0; j < b[0].size(); j++){
              if(b[i][j] != nullptr && (i != source.first || j != source.second) && b[i][j]->get_player() == player_num){
                if(Paramedic* s = dynamic_cast<Paramedic*>(b[i][j])){
                  b[i][j]->ability({i,j},b);
                }
              }
          }  
        }
      }
};