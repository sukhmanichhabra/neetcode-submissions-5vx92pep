class Solution {
public:
 bool isNStraightHand(vector<int>& hand, int sz) {
    int n =hand.size();
    unordered_map<int,int>mp;
    for(auto it:hand){
        mp[it]++;
    }
    sort(hand.begin(), hand.end());
    for(int i=0;i<n;i++){
        if(mp.find(hand[i])==mp.end())continue;
        int cnt =0;
        int cur=hand[i];
        
        while(cnt<sz && mp.find(cur)!=mp.end()){
            mp[cur]--;
            if(mp[cur]==0)mp.erase(cur);
            cnt++;
            cur++;
        }
        if(cnt!=sz)return false;
    }
   if(mp.empty()) return true;
   return false;
 }
    
};