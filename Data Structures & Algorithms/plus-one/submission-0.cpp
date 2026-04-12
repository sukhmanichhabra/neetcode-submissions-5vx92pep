class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        vector<int>ans;
        int n =nums.size();
int sum =nums[n-1]+1;
        int carry =sum/10;
        nums[n-1]=sum%10;
        for(int i=n-2;i>=0;i--){
sum=nums[i]+carry;
//if(sum==10)carry=1;
carry =sum/10;
nums[i]=sum%10;

        }
        if(carry==1)ans.push_back(1);
        for(auto it:nums){
            ans.push_back(it);
        }
        return ans;
    }
};

