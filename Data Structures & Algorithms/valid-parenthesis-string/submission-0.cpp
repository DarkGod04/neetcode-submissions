class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int open=0;
        int close=0;
        //left to right check
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='*') open++;
            if(s[i]==')') open--;
            if(open<0) return false;
        }
        //right to left check 
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(') close--;
            if(s[i]==')' || s[i]=='*') close++;
            if(close<0) return false;
        }
        return true;
    }
};
