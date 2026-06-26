class Solution {
public:
    vector<vector<int>>dp;
    int target;
    bool solve(int i, int currsum , vector<int>& nums ){
        if(currsum==target) return true;
        if(i==nums.size() || currsum>target) return false;
        if(dp[i][currsum] != -1) return dp[i][currsum];
        bool take=solve(i+1,currsum+nums[i],nums);
        bool not_take=solve(i+1,currsum,nums);
        return dp[i][currsum]=take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        target=sum/2;
        if(sum%2) return false;
        dp.assign(n,vector<int>(target+1,-1));
        return solve(0,0,nums);
    }
};
