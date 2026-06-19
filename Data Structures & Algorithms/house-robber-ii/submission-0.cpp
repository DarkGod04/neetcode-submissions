class Solution {
public:
    int rob_helper(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1,temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(rob_helper(temp1),rob_helper(temp2));
    }
};
