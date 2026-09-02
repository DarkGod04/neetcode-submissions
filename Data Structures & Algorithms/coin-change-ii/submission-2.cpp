class Solution {
public:
    vector<vector<int>>t;
    int solve(int amount,int idx,vector<int>& coins){
        if(idx>=coins.size()) return amount=0;
        if(amount<0) return 0;
        if(amount==0) return 1;
        if(t[amount][idx]!=-1) return t[amount][idx];
        int take=solve(amount-coins[idx],idx,coins);
        int not_take=solve(amount,idx+1,coins);
        return t[amount][idx]=take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        t.assign(amount+1,vector<int>(n,-1));
        return solve(amount,0,coins);
    }
};
