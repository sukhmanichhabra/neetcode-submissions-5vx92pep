class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;

        int l = 0;

        for (int r = 0; r < nums.size(); r++) {

            // keep window size <= k
            if (r - l > k) {
                window.erase(nums[l]);
                l++;
            }

            // duplicate found inside window
            if (window.count(nums[r])) {
                return true;
            }

            window.insert(nums[r]);
        }

        return false;
    }
};