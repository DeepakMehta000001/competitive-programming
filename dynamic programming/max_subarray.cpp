//Problem: https://leetcode.com/problems/maximum-subarray/description/ 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int res= INT_MIN;
        for(int i=0;i<n;++i){
            if(!i){
                res = nums[i];
                dp[i] = nums[i];
                continue;
            }
            dp[i] = max(nums[i]+dp[i-1],nums[i]);
            res = max(res,dp[i]);
        }
        return res;
    }
};