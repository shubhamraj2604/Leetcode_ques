class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> s;
        for(auto c:obstacles){
            s.insert({c[0] , c[1]});
        }

        int curr_x = 0 , curr_y = 0;
        int direction = 1;    // 1 -> N , 2->E , 3 -> S , 4 -> W 
        int maxdist = 0;
        for(auto c:commands){
           if(c == -2){
                 direction = direction - 1;
                if(direction <= 0){
                    direction = 4;
                }
            }else if(c == -1){
                 direction = (direction + 1) % 4;
                 if(direction == 0){
                    direction = 4;
                 }
            }else{
                 for(int step = 0 ; step < c ; step++){

                  int new_x = curr_x , new_y = curr_y;
                  if(direction == 1){
                    new_y++;
                  }else if(direction == 2){
                     new_x++;
                  }else if(direction == 3){
                    new_y--;
                  }else{
                    new_x--;
                  }
                  
                  if(s.count({new_x , new_y })){
                    break;
                  }
                     curr_x = new_x;
                     curr_y = new_y;
                   
                 maxdist = max(maxdist  , ((curr_x * curr_x) + (curr_y * curr_y)));
                 }
                 }
        }

        return maxdist;
    }
};