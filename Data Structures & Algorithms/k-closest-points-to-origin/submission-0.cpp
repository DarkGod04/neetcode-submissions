class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        int n=points.size();
        priority_queue<pair<long long,int>>pq;
        for(int i=0;i<n;i++){
            long long x=points[i][0];
            long long y=points[i][1];
            long long dist=x*x + y*y;
            if(pq.size()<k) pq.push({dist,i});
            else if(dist<pq.top().first){
                pq.pop();
                pq.push({dist,i});
            }
        }
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
