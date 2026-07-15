class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>vec(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int col=0;col<m;col++){
                        vec[i][col]=0;
                    }
                    for(int row=0;row<n;row++){
                        vec[row][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec[i][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
