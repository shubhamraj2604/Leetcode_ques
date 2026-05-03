class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>m;
       stack<int>s;

       
       vector<int>ans;
       for(int i=nums2.size() - 1;i>=0;i--){
          while(!s.empty() && nums2[s.top()] <= nums2[i]){
               s.pop();
          }

          if(!s.empty()){
              m[nums2[i]] = nums2[s.top()];
          }else{
            m[nums2[i]] = -1;
          }

          s.push(i);
       }


       for(auto c:nums1){
         ans.push_back(m[c]);
       }

       return ans;
    }
};
