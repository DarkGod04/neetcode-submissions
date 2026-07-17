class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        string s="";
        for(int i=0;i<n;i++){
            s+=to_string(digits[i]);
        }
        long long ans=stoll(s);
        ans=ans+1;
        string s1=to_string(ans);
        vector<int>sol;
        for(int i=0;i<s1.size();i++){
            sol.push_back(s1[i]-'0');
        }
        return sol;
    }
};
