class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        int m=triplets[0].size();
        vector<int>curr(m,0);
        for(auto & it : triplets){
            if(it[0]>target[0] || it[1] > target[1] || it[2] > target[2]) continue;
            curr[0]=max(curr[0],it[0]);
            curr[1]=max(curr[1],it[1]);
            curr[2]=max(curr[2],it[2]);
            if(curr[0]==target[0] && curr[1]==target[1] && curr[2]==target[2]) return true;
        }
        return false;
    }
};
