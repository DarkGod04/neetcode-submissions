class Solution {
public:
    vector<vector<int>>t;
    int solve(string s1,string s2,int i,int j){
        if(i>=s1.length() || j>=s2.length()) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(s1[i]==s2[j]) return 1+solve(s1,s2,i+1,j+1);
        return t[i][j]=max(solve(s1,s2,i,j+1),solve(s1,s2,i+1,j));
    }
    int longestCommonSubsequence(string text1, string text2) {
        t.assign(1001,vector<int>(1001,-1));
        return solve(text1,text2,0,0);
    }
};
