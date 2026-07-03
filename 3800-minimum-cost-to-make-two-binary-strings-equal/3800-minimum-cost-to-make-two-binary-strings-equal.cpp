class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
         int c01 = 0;
         int c10 = 0;
         for(int i=0;i<s.size();i++){
            if(s[i] == '0' && t[i] == '1'){
                c01++;
            }else if(s[i] == '1' && t[i] == '0'){
                c10++;
            }
         }
         
         long long ans = 0;
    //      int maxi = max(c01 , c10);
         
    //      int mini = min(c01 , c10);

    //      ans+=min({2LL * mini * flipCost , 1LL * mini * swapCost});

    //      maxi-=mini;

    //      ans+= min(1LL * (crossCost + swapCost) * (maxi/2) , 2LL * flipCost * (maxi/2));
         

    //      if(maxi % 2 == 1){
    //         ans+=1LL * flipCost;
    //      }


            // i have two choices
            //flip or swap
            // flip means i will have all of them 10 
            //swap
            if(2LL * flipCost > 1LL * swapCost){
                //swap
                int mini = min(c01 , c10);
                int maxi = max(c01 , c10);
                ans+=1LL * mini * swapCost;
                maxi-=mini;

                if((swapCost + crossCost) < 2LL * flipCost){
                    //cross
                     ans+=(swapCost + crossCost) * 1LL * (maxi/2);
                    // if any left after cross then flip
                     if(maxi % 2 == 1){
                        //flip
                        ans+=flipCost;
                     }
                }else{
                    //if flip is better than cross then take this
                    ans+=1LL*maxi*flipCost;
                }
                
            }else{
                //flip is better than swap + remaining operation then this
                ans+=1LL * (c01 + c10) * flipCost;
            }

         return ans;
    
    }
};