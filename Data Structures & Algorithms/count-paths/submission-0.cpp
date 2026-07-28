class Solution {
public:
    int routes(int i,int j,int m,int n,vector<vector<int>>&t){
        if(i==m-1 && j==n-1) return 1;
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int right=routes(i,j+1,m,n,t);
        int down=routes(i+1,j,m,n,t);
        return t[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>t(m+1,vector<int>(n+1,-1));
        return routes(0,0,m,n,t);
    }
};
