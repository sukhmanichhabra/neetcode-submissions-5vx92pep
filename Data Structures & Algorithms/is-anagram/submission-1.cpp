class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,int>mp;
        for(auto it :s){
            mp[it]++;
        }
        for(auto it:t){
            if(mp.find(it)==mp.end()){
                return false;
            }
            else{
                mp[it]--;
                if(mp[it]==0)mp.erase(it);
            }
        }
        return true;
    }
};
