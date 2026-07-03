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
         int maxi = max(c01 , c10);
         
         int mini = min(c01 , c10);

         ans+=min({2LL * mini * flipCost , 1LL * mini * swapCost});

         maxi-=mini;

         ans+= min(1LL * (crossCost + swapCost) * (maxi/2) , 2LL * flipCost * (maxi/2));
         

         if(maxi % 2 == 1){
            ans+=1LL * flipCost;
         }

         return ans;
    }
};