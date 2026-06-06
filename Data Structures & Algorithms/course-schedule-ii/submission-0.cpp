class Solution {
public:
    unordered_map<int,vector<int>>premap;
    unordered_set<int>visited;
    unordered_set<int>cycle;
    vector<int>output;
    bool dfs(int course){
        if(cycle.count(course)) return false;
        if(visited.count(course)) return true;
        cycle.insert(course);
        if(premap.count(course)) 
        for(auto & pre : premap[course]){
            if(!dfs(pre)) return false;
        }
        cycle.erase(course);
        visited.insert(course);
        output.push_back(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            premap[i]={};
        }
        for(auto & num: prerequisites){
            premap[num[0]].push_back(num[1]);
        }
        for(int course=0;course<numCourses;course++){
            if(!dfs(course)) return {};
        }
        return output;
    }
};
