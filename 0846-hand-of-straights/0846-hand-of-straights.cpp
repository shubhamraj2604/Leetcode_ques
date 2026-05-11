class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)return false;
        priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;
        map<int,int>m;
        for(auto c:hand){
           m[c]++;
        }

        for(auto c:m){
            pq.push({c.first , c.second});
        }

        // while(!m.empty()){
        //     int start = m.begin()->first;

        //     for(int i=0;i<groupSize;i++){
        //          int card = start + i;

        //          if(!m.count(card)){
        //             return false;
        //          }

        //          m[card]--;
        //          if(m[card] == 0){
        //             m.erase(card);
        //          }
        //     }
        // }
        
        while(!pq.empty()){
            int top = pq.top().first;
            
            for(int i=0;i<groupSize;i++){
                int card = top + i;

                if(!m.count(card))return false;

                m[card]--;
                if(m[card]==0){
                   if(card != pq.top().first){
                    return false;
                   }
                   pq.pop();
                   m.erase(card);
                }
            }
        }
        return true;
    }
};