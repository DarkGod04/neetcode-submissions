class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j , string word1, string word2){
        if(i==word1.size()) return word2.size()-j;
        if(j==word2.size()) return word1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=solve(i+1,j+1,word1,word2);
        return dp[i][j]=1+min({solve(i+1,j+1,word1,word2),
        solve(i,j+1,word1,word2),
        solve(i+1,j,word1,word2)});
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(0,0,word1,word2);
    }
};
