class Solution {
public:
    vector<int> dp;

    bool solve(int i, string &s, unordered_set<string> &st) {
        if (i == s.size()) return true;

        if (dp[i] != -1)
            return dp[i];

        string temp = "";

        for (int j = i; j < s.size(); j++) {
            temp += s[j];
            if (st.count(temp)) {
                if (solve(j + 1, s, st))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        dp.assign(s.size(), -1);

        return solve(0, s, st);
    }
};