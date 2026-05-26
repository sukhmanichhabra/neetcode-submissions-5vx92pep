class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n =bills.size();
       
        int f=0;
        int t=0;

        for(auto it:bills){
            if(it==5){
                f++;
            }
            else if(it==10){
                if(f<1)return false;
                f--;
                t++;
            }
            else{
                if(f>2){
f-=3;

                }
                else if(t>0 && f>0){
t--;
f--;
                }
                else {
                 return    false;
                }
            }
        }
        return true;
    }
};