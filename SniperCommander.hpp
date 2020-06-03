#pragma once

#include "Sniper.hpp"

class SniperCommander : public Sniper{
  SniperCommander ();

  public:
      SniperCommander  (int p) : Sniper(120,100,p) {}
      ~SniperCommander (){}
      void ability (const std::pair<int,int> source, std::vector<std::vector<Soldier*>>& b) override{
        int player_num = b[source.first][source.second]->get_player();
        Sniper::ability(source, b);

        for(int i = 0; i < b.size(); i++){
          for(int j = 0; j < b[0].size(); j++){
              if(b[i][j] != nullptr && b[i][j]->get_player() == player_num && (i != source.first || j != source.second)){
                if(Sniper* s = dynamic_cast<Sniper*>(b[i][j]))
                  b[i][j]->ability({i,j},b);
              }
          }
        }  
      }
};