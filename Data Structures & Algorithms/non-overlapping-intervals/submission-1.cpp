class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int prevIndx=intervals[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prevIndx){
                cnt++;
                prevIndx=min(intervals[i][1],prevIndx);
            }
            else{
                prevIndx=intervals[i][1];
            }
        }
        return cnt;
    }
};
