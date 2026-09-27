class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int>m;
        for(auto c:nums){
            m[c]++;
        }

        vector<int>ans;
        while(!m.empty()){
            vector<int>temp;
            for(auto &c:m){
                ans.push_back(c.first);
                c.second--;
                if(c.second == 0){
                    temp.push_back(c.first);
                }
            }

            for(auto x:temp){
                m.erase(x);
            }
        }
        return ans;
    }
};