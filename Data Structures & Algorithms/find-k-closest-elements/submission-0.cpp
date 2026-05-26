class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
       //priority_queue<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++){
            int y=abs(arr[i]-x);
            pq.push({y,i});
            
        }
         vector<int>ans;
        while(k--){
            auto [no , z]=pq.top();
            pq.pop();
            ans.push_back(arr[z]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};