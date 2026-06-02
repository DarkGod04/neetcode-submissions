class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<bool>& visit,int node){
        visit[node]=true;
        for(int obj: adj[node]){
            if(!visit[obj]){
                dfs(adj,visit,obj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visit(n,false);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int res=0;
        for(int node=0;node<n;node++){
            if(!visit[node]){
                dfs(adj,visit,node);
                res++;
            }
        }
        return res;
    }
};
