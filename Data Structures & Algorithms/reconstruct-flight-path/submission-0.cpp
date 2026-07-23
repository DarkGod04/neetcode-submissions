class Solution {
public:
    unordered_map<string,vector<string>>adj;
    vector<string>result;
    int numtickets=0;
    bool DFS(string fromCity, vector<string>&path){
        path.push_back(fromCity);
        if(path.size()==numtickets+1) {
            result=path;
            return true;
        }
        vector<string>& neighbour = adj[fromCity];
        for(int i=0;i<neighbour.size();i++){
            string tocity=neighbour[i];
            neighbour.erase(neighbour.begin()+i);
            if(DFS(tocity,path)==true) return true; 
            neighbour.insert(neighbour.begin()+i,tocity);
        }
        path.pop_back();
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numtickets=tickets.size();
        for(auto & it : tickets){
            string u=it[0];
            string v=it[1];
            adj[u].push_back(v);
        }
        for( auto & edges: adj){
            sort(begin(edges.second),end(edges.second));
        }
        vector<string>path;
        DFS("JFK",path);
        return result;
    }
};
