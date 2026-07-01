class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1) return nums[0];
        int sum=INT_MIN;
        for(int i=0;i<n;i++){
            int maxsum=0;
            for(int j=i;j<n;j++){
                maxsum+=nums[j];
                sum=max(sum,maxsum);
            }
        }
        return sum;
    }
};
