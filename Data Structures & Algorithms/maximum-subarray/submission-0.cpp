class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();
        int sum=0;
        int maxi =-1;
        for(int i=0;i<n;i++){
             sum+=nums[i];
             if(sum<0){
                sum=0;
             }
             else if (sum>maxi){
                maxi =sum;
             }
        }
return maxi;
    }
};
