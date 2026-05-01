class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        int maxi =0+nums[0];
        for(int i=1;i<n;i++){
            if(maxi<i)return false;
            maxi=max(
                i+nums[i], maxi
            );
        }
return true;
    }
};
