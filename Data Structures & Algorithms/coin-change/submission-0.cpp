class Solution {
public:
    vector<vector<int>>dp;
    int f(int idx,int amount,vector<int>& coins){
        if(amount==0) return 0;
        if(idx>=coins.size()) return 1e9;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int take=1e9;
        if(coins[idx]<=amount) take=1+f(idx,amount-coins[idx],coins);
        int skip=f(idx+1,amount,coins);
        return dp[idx][amount]=min(skip,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.assign(n+1,vector<int>(amount+1,-1));
        int ans=f(0,amount,coins);
        return ans>=1e9 ? -1 : ans;
    }
};
