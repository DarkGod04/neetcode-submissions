class Solution {
public:
    // vector<vector<int>>t;
    // int solve(string s1,string s2,int i,int j){
    //     if(i>=s1.length() || j>=s2.length()) return 0;
    //     if(t[i][j]!=-1) return t[i][j];
    //     if(s1[i]==s2[j]) return 1+solve(s1,s2,i+1,j+1);
    //     return t[i][j]=max(solve(s1,s2,i,j+1),solve(s1,s2,i+1,j));
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
