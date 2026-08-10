class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i, int j, string &s, string &p) {
        if(j==p.size()){
            return i==s.size();
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool matched=false;
        if(i<s.size() && (s[i]==p[j] || p[j]=='.')){
            matched=true;
        }
        if(j+1<p.size() && p[j+1]=='*'){
            bool take=(matched && solve(i+1,j,s,p));
            bool not_take= solve(i,j+2,s,p);
            return dp[i][j]=take || not_take;
        }
        return dp[i][j]=(matched && solve(i+1,j+1,s,p));

    }

    bool isMatch(string s, string p) {
        dp.assign(s.length()+1,vector<int>(p.length(),-1));
        return solve(0, 0, s, p);
    }
};