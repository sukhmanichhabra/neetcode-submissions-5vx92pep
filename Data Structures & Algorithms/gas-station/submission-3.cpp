class Solution {
public:
    bool can(vector<int>& gas, vector<int>& cost, int st) {
        int n = gas.size();
        int tank = 0;

        for (int cnt = 0; cnt < n; cnt++) {
            int index = (st + cnt) % n;

            tank += gas[index];
            tank -= cost[index];

            if (tank < 0) return false;
        }

        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        for (int i = 0; i < n; i++) {
            if (can(gas, cost, i)) {
                return i;
            }
        }

        return -1;
    }
};