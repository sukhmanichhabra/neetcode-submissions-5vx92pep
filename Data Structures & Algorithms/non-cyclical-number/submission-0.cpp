class Solution {
public:
    int cal(int n){
        int sum = 0;
        while(n > 0){
            int rem = n % 10;
            n /= 10;
            sum += rem * rem;
        }
        return sum;
    }

    bool isHappy(int x) {
        unordered_set<int> mp;

        while(x != 1 && mp.find(x) == mp.end()) {
            mp.insert(x);
            x = cal(x);
        }

        return x == 1;
    }
};