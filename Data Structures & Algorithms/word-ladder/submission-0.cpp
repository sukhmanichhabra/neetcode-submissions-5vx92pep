class Solution {
public:
    int ladderLength(string beg, string ed, vector<string>& wo) {
        unordered_set<string> st(wo.begin(), wo.end());

        if (st.find(ed) == st.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beg, 1});

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == ed) return steps;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (st.find(word) != st.end()) {
                        q.push({word, steps + 1});
                        st.erase(word); // mark visited
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};