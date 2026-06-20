class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i,int j, string &s){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=s[j]) return dp[i][j]=false;
        return dp[i][j]=solve(i+1,j-1,s);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=INT_MIN;
        dp.assign(n, vector<int>(n, -1));
        int st=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s)==true){
                    if(j-i+1>maxLen) {
                        maxLen=max(maxLen,j-i+1);
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxLen);
    }
};
