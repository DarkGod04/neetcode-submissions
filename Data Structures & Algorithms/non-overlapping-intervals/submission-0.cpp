class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int cnt=0;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<ans.back()[1]){
                ans.back()[1]=min(intervals[i][1],ans.back()[1]);
                cnt++;
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return cnt;
    }
};
