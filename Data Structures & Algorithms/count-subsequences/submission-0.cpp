class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int k , string &s, string &t){
        if(k==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][k]!=-1)  return dp[i][k];
        if(s[i]==t[k]){
            return dp[i][k]=solve(i+1,k+1,s,t)+solve(i+1,k,s,t);
        }
        return dp[i][k]=solve(i+1,k,s,t);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(0,0,s,t);
    }
};
