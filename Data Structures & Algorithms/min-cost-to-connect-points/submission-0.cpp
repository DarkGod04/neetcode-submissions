class Solution {
public:
    typedef pair<int,int>P;
    int prismalgo(vector<vector<P>>&adj, int n){
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<bool>visited(n,false);
        int sum=0;
        pq.push({0,0});
        while(!pq.empty()){
            int weight=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(visited[node]==true) continue;
            visited[node]=true;
            sum+=weight;
            for(auto &edge: adj[node] ){
                int neighbour_node=edge.first;
                int neighbour_weight=edge.second;
                if(visited[neighbour_node]==false){
                    pq.push({neighbour_weight,neighbour_node});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<P>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int x2=points[j][0];
                int y1=points[i][1];
                int y2=points[j][1];
                int dist=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        return prismalgo(adj,n);
    }
};
