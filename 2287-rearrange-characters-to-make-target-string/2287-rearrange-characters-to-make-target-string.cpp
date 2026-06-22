class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int>x(26 , 0),y(26,0);
        for(auto c:target){
            x[c - 'a']++;
        }

        for(auto c:s){
            y[c - 'a']++;
        }
        
        int mini = INT_MAX;
        for(auto c:target){
            if(y[c - 'a'] == 0){
                return 0;
            }

            mini = min(mini , (y[c - 'a'] / x[c - 'a']));
        }

        return mini;
    }
};