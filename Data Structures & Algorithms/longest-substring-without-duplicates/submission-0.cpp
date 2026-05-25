class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>mp;
       int l=0;
       int n =s.size();
int r=0;
int ans=0;
while(r<n){
    while(mp.contains(s[r])){
        mp.erase(s[l]);
        l++;
    }
ans=max(ans,r-l+1);
mp.insert(s[r]);
r++;
}
return ans;
    }
};
