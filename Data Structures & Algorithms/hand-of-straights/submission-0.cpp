class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int sz) {
        int n = hand.size();
        if(n % sz != 0) return false;

        unordered_map<int,int> mp;
        for(int x : hand) mp[x]++;

        sort(hand.begin(), hand.end());  // ✅ important

        for(int x : hand){
            if(mp[x] == 0) continue;  // already used

            // try to form a group starting at x
            for(int i = 0; i < sz; i++){
                if(mp[x + i] == 0) return false;
                mp[x + i]--;
            }
        }
        return true;
    }
};