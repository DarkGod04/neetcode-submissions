class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l,int r, vector<int>& nums){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        for(int i=l ; i<=r;i++){
            int coins = nums[l-1]*nums[i]*nums[r+1];
            coins+=solve(l,i-1,nums);
            coins+=solve(i+1,r,nums);
            ans=max(coins,ans);
        }
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newNums(n + 2, 1);
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
        }
        dp.assign(n + 3, vector<int>(n + 3, -1));
        return solve( 1, newNums.size() - 2, newNums);
    }

    // int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
    //     if (l > r) return 0;
    //     if (dp[l][r] != -1) return dp[l][r];

    //     dp[l][r] = 0;
    //     for (int i = l; i <= r; i++) {
    //         int coins = nums[l - 1] * nums[i] * nums[r + 1];
    //         coins += dfs(nums, l, i - 1, dp) + dfs(nums, i + 1, r, dp);
    //         dp[l][r] = max(dp[l][r], coins);
    //     }
    //     return dp[l][r];
    // }
};