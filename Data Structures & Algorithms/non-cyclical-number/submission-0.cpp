class Solution {
public:
    int sumofsquare(int n){
        int sum=0;
        while(n>0){
            int one=n%10;
            n=n/10;
            sum=one*one+sum;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fast=sumofsquare(n);
        int slow=n;
        while(fast!=slow && fast!=1){
            slow=sumofsquare(slow);
            fast=sumofsquare(sumofsquare(fast));
        }
        return fast==1;
    }
};
