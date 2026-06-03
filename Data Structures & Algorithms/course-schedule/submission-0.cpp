class Solution {
public:
    unordered_map<int , vector<int> >premap;
    unordered_set<int>visited;
    bool dfs(int crs){
        if(visited.count(crs)) return false;
        if(premap[crs].empty()) return true;
        visited.insert(crs);
        for(int pre: premap[crs]){
            if(!dfs(pre)) return false;
        }
        visited.erase(crs);
        premap[crs].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            premap[i]={};
        }
        for( auto & prereq : prerequisites){
            premap[prereq[0]].push_back(prereq[1]);
        }
        for(int c=0;c<numCourses;c++){
            if(!dfs(c)) return false;
        }
        return true;
    }
};
