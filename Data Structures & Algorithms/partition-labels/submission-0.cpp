class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>end;
        
        for(int i=0;i<s.size();i++){
            end[s[i]]=i;
          
        }
vector<int>res;
int size=0;int ans =0;
for(int i=0;i<s.size();i++){
size++;
ans=max(ans,end[s[i]]);
if(i==ans){
    res.push_back(size);    
    size=0;    
}
}
return res;
    }
};
