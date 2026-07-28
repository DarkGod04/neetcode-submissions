class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights,int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for( auto & it : flights){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{src,0}});
        dist[src][0]=0;
        while(!pq.empty()){
            int weight=pq.top().first;
            int node=pq.top().second.first;
            int stop=pq.top().second.second;
            pq.pop();
            if(node==dst) return weight;
            if(stop==k+1) continue;
            for(auto &it : adj[node]){
                int next=it.first;
                int newweight=it.second;
                int newprize=weight+newweight;
                if(newprize<dist[next][stop+1]){
                    dist[next][stop+1]=newprize;
                    pq.push({newprize,{next,stop+1}});
                }
            }
        }
        return -1;
    }
};