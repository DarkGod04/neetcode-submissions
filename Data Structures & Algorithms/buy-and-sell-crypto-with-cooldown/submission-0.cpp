class Solution {
public:
    vector<vector<int>>t ;
    int solve(int i,vector<int>& prices,bool buy){
        if(i>=prices.size()) return 0;
        if(t[i][buy]!=-1) return t[i][buy];
        int profit=0;
        if(buy){
            int take_to_buy=solve(i+1,prices,false)-prices[i];
            int not_take_buy=solve(i+1,prices,true);
            t[i][buy]=profit=max({profit,take_to_buy,not_take_buy});
        }
        else{
            int sell=prices[i]+solve(i+2,prices,true);
            int not_sell=solve(i+1,prices,false);
            t[i][buy]=profit=max({profit,sell,not_sell});
        }
        return t[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        t.assign(prices.size()+1,vector<int>(2,-1));
        return solve(0,prices,true);
    }
};
