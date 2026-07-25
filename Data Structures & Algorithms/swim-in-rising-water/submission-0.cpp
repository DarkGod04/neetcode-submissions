class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>visited(n,vector<int>(n,INT_MAX));
        visited[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int time=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==n-1) return time;
            if(time<grid[i][j]) continue;
            for(auto dirs : dir){
                int i_new=i+dirs[0];
                int j_new=j+dirs[1];
                if(i_new>=0 && i_new<n && j_new>=0 && j_new<n){
                    int nexttime=max(time,grid[i_new][j_new]);
                    if(nexttime<visited[i_new][j_new]){
                        visited[i_new][j_new]=nexttime;
                        pq.push({nexttime,{i_new,j_new}});
                    }
                }
            }
        }
        return -1;
    }
};
