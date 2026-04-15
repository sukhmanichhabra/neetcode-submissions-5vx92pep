class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int maxleft = 0, maxright = 0;
        int lft = 0, rgt = n - 1;
        int cnt = 0;

        while(lft < rgt){
            if(h[lft] <= h[rgt]){
                if(h[lft] >= maxleft){
                    maxleft = h[lft];
                } else {
                    cnt += maxleft - h[lft];
                }
                lft++;  // ✅ move only left
            }
            else{
                if(h[rgt] >= maxright){
                    maxright = h[rgt];
                } else {
                    cnt += maxright - h[rgt];
                }
                rgt--;  // ✅ move only right
            }
        }
        return cnt;
    }
};