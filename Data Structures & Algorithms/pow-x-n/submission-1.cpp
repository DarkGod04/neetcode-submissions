class Solution {
public:
    double myPow(double x, int n) {
        if(n>0){
            double mul=x;
            while(n-1!=0){
            mul=x*mul;
            n--;
            }
            return mul;
        }
        else if(n<0){
            double mul=x;
            while((abs(n)-1)!=0){
                mul=x*mul;
                n++;
            }
            return 1/mul;
        }
        return 1;
    }
};
