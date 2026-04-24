class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if (m > n) return false;

        vector<int> mp(26, 0);

        // Count frequency of s1
        for (char c : s1) {
            mp[c - 'a']++;
        }

        int cnt = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            // Include current character
            if (--mp[s2[r] - 'a'] >= 0) {
                cnt++;
            }

            // Shrink window if size > m
            if (r - l + 1 > m) {
                if (++mp[s2[l] - 'a'] > 0) {
                    cnt--;
                }
                l++;
            }

            // Check if valid permutation
            if (cnt == m) return true;
        }

        return false;
    }
};