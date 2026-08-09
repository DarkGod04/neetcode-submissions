class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i, int j, string &s, string &p) {

        if (j == p.size())
            return i == s.size();
        if(dp[i][j]!=-1) return dp[i][j];
        bool first_char_matched = false;

        if (i < s.size() &&
            (s[i] == p[j] || p[j] == '.')) {
            first_char_matched = true;
        }

        if (j + 1 < p.size() && p[j + 1] == '*') {

            bool not_take = solve(i, j + 2, s, p);

            bool take =
                first_char_matched &&
                solve(i + 1, j, s, p);

            return dp[i][j]=not_take || take;
        }

        return dp[i][j]=first_char_matched &&
               solve(i + 1, j + 1, s, p);
    }

    bool isMatch(string s, string p) {
        dp.assign(s.length()+1,vector<int>(p.length(),-1));
        return solve(0, 0, s, p);
    }
};