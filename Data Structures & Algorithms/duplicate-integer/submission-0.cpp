class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>mp;
        for(auto it:nums){
            if(mp.find(it)!=mp.end()){
                return true;
            }
            mp.insert(it);
        }
        return false;
    }
};