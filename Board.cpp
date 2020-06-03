#include "Board.hpp"
#include "Soldier.hpp"

namespace WarGame {
    Soldier*& Board::operator[](std::pair<int,int> location){
        // maybe check location first
        return board[location.first][location.second];
    }
    
    Soldier* Board::operator[](std::pair<int,int> location) const{
       return board[location.first][location.second];
    }
    
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){

      if(source.first < 0 || source.first >= nRows || source.second < 0 || source.second >= nCols)
        throw std::invalid_argument("Invalid source.");

      if(this->operator[](source) == nullptr)
        throw std::invalid_argument("Source location has no Soldier.");

      if(this->operator[](source)->get_player() != player_number)
        throw std::invalid_argument("Not your Soldier.");
        
      if(direction == MoveDIR::Left){
        if((source.second-1 < 0 || source.second-1 >= nCols) || this->operator[]({source.first,source.second-1}) != nullptr){
          throw std::invalid_argument("There is already solider in that location");
        }
        std::pair<int, int> new_s = {source.first,source.second-1};
          this->operator[](new_s) = this->operator[](source);
          this->operator[](source) = nullptr;
          this->operator[](new_s)->ability(new_s, board);
      }
      else if(direction == MoveDIR::Right){
        if((source.second+1 < 0 || source.second+1 >= nCols) || this->operator[]({source.first,source.second+1}) != nullptr){
          throw std::invalid_argument("There is already solider in that location");
        }
        std::pair<int, int> new_s = {source.first,source.second+1};
          this->operator[](new_s) = this->operator[](source);
          this->operator[](source) = nullptr;
          this->operator[](new_s)->ability(new_s, board);
      }
      else if(direction == MoveDIR::Up){
        if((source.first+1 < 0 || source.first+1 >= nRows) || this->operator[]({source.first+1,source.second}) != nullptr){
          throw std::invalid_argument("There is already solider in that location");
        }
        std::pair<int, int> new_s = {source.first+1,source.second};
        this->operator[](new_s) = this->operator[](source);
        this->operator[](source) = nullptr;
        this->operator[](new_s)->ability(new_s, board);
      }
      else if(direction == MoveDIR::Down){
        if((source.first-1 < 0 || source.first-1 >= nRows) || this->operator[]({source.first-1,source.second}) != nullptr){
          throw std::invalid_argument("There is already solider in that location");
        }
        std::pair<int, int> new_s = {source.first-1,source.second};
          this->operator[](new_s) = this->operator[](source);
          this->operator[](source) = nullptr;
          this->operator[](new_s)->ability(new_s, board);
      }
      else
        throw std::invalid_argument("Invalid direction.");
    }

    // returns true iff the board contains one or more soldiers of the given player.
    bool Board::has_soldiers(uint player_number) const{
      for(int i = 0; i <nRows; i++){
        for(int j = 0; j < nCols; j++){
          if(board[i][j] != nullptr && board[i][j]->get_player() == player_number)
            return true;
        }
      }
      return false;
    }
}
