class Solution {
public:
    vector<vector<vector<int>>>t;
    bool solve(int i,int j, int k,string &s1, string&s2 , string &s3){
        int n=s1.length();
        int m=s2.length();
        int z=s3.length();
        if(i==n && j==m && k==z) return true;
        if(k>=z) return false;
        if(t[i][j][k]!=-1) return t[i][j][k];
        bool result=false;
        if(s1[i]==s3[k]){
            t[i][j][k]=result=solve(i+1, j,k+1,s1,s2,s3);
        }
        if(s2[j]==s3[k]){
            t[i][j][k]=result=solve(i,j+1,k+1,s1,s2,s3);
        }
        return t[i][j][k]=result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        int z=s3.length();
        t.assign(n+1,vector<vector<int>>(m+1,vector<int>(z+1,-1)));
        return solve(0,0,0,s1,s2,s3);
    }
};