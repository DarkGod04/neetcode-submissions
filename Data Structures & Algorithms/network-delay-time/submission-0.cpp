class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &it: times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>pq;
        vector<int>res(n+1,INT_MAX);
        pq.push({0,k});
        res[k]=0;
        while(!pq.empty()){
            int neigh=pq.top().second;
            int weigh=pq.top().first;
            pq.pop();
            for(auto [next,wgt]: adj[neigh]){
                if(weigh+wgt<res[next]){
                    res[next]=weigh+wgt;
                    pq.push({weigh+wgt,next});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n+1;i++){
            ans=max(ans,res[i]);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};
