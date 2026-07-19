class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.length();
        int m=num2.length();
        vector<int>res(n+m+1,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i+j]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        reverse(res.begin(),res.end());
        for(int i=n+m;i>=1;i--){
            res[i-1]+=res[i]/10;
            res[i]%=10;
        }
        int first=0;
        string s="";
        while(first<=n+m && res[first]==0) first++;
        if(first==n+m+1) return "0";
        for(int i=first;i<n+m+1;i++){
            s+=(res[i]+'0');
        }
        return s;
    }
};
