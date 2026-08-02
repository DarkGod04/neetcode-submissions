class Solution {
public:
    int solve(vector<int>& nums, int idx, int target, int sum){
        if(idx==nums.size()){
            if(target==sum) return 1;
            else{
                return 0;
            }
        }
        int take=solve(nums,idx+1,target,sum+nums[idx]);
        int not_take=solve(nums,idx+1,target,sum-nums[idx]);
        return take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,target,0);
    }
};
