class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>>t;
    int solve(int i,int j,vector<vector<int>>& matrix){
        if(t[i][j]!=-1) return t[i][j];
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=1;
        for(auto &it : dir){
            int new_i=i+it[0];
            int new_j=j+it[1];
            if(new_i<n && new_j<m && new_i>=0 && new_j>=0 && matrix[i][j]<matrix[new_i][new_j]){
                ans=max(ans,1+solve(new_i,new_j,matrix));
            }
        }
        return t[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        t.assign(n+1,vector<int>(m+1,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,solve(i,j,matrix));
            }
        }
        return ans;
    }
};
