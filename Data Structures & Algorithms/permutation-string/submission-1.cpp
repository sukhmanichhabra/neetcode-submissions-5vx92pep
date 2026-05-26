class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m =s2.size();
        if(m<n)return false;
        int l=0;
        unordered_map<char,int>mp;
        for(auto it:s1){
            mp[it]++;
        }
  unordered_map<char,int>c;
        for(int r=0;r<m;r++){
            c[s2[r]]++;
            while(r-l+1>n){
                c[s2[l]]--;
                if( c[s2[l]]==0)c.erase(s2[l]);
                l++;
            }
            if(r-l+1==n){
                if(mp==c)return true;
            }
        }
return false;
    }
};
