class Solution {
public:
    vector<vector<int>>t;
    int total;
    int solve(vector<int>& nums, int idx, int target, int sum){
        if(idx==nums.size()){
            if(target==sum) return 1;
            else{
                return 0;
            }
        }
        if(t[idx][sum+total]!=-1) return t[idx][sum+total];
        int take=solve(nums,idx+1,target,sum+nums[idx]);
        int not_take=solve(nums,idx+1,target,sum-nums[idx]);
        return t[idx][sum+total]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        for(int &it: nums){
            total+=it;
        }
        t.assign(nums.size()+1,vector<int>(total*2+1,-1));
        return solve(nums,0,target,0);
    }
};
