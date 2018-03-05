//problem - https://leetcode.com/problems/longest-increasing-subsequence/description/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int dp[n];
        dp[0]=1;
        //memset(dp,1,sizeof(dp));
        int maxi=1;
        for(int i=1;i<n;++i){
            dp[i]=1;
            for(int j=i-1;j>=0;--j){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxi = max(maxi,dp[i]);
                }
            }
        }
        /*for(int i=0;i<n;++i)
            cout<<dp[i]<<" ";
        cout<<endl;*/
        return maxi;
    }
};

/*
    //Non DP Solution. Impressive.
    int lengthOfLIS(vector<int>& nums) {
    vector<int> res;
    for(int i=0; i<nums.size(); i++) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if(it==res.end()) res.push_back(nums[i]);
        else *it = nums[i];
    }
    return res.size();
}
*/
