class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_map<int,int>m;
        for(auto c:nums){
            mini = min(mini , c);
            maxi = max(maxi , c);
            m[c]++;
        }
        
        vector<int>ans;
        for(int i=mini ; i<=maxi ;i++){
            if(!m.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};