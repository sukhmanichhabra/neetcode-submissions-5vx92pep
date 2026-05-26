class Solution {
public:
    int jump(vector<int>& nums) {
        int n =nums.size();
        int maxi =0;
        int cur=0;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            maxi =max(i+nums[i],maxi);
if(cur==i){
    cur=maxi;
    cnt++;
}
        }
        return cnt;
    }
};
