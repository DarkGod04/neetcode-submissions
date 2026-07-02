class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxindex=0;
        for(int i=0;i<n;i++){
            if(i>maxindex) return false;
            maxindex=max(i+nums[i],maxindex);
        }
        return true;
    }
};
