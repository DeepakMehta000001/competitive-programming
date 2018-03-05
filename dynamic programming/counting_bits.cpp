//problem : https://leetcode.com/problems/counting-bits/description/
/*class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);
        //dp.push_back(0);
        vector<int> pow2(num+1,0);
        for(int i=1;;++i){
            int k=pow(2, i);
            if(k>num){
                break;
            }
            pow2[k]=1;
        }
        for(int i=1;i<=num;++i){
            if(pow2[i]){
                dp[i]=1;
                continue;
            }

            if(i%2!=0){
                dp[i]=dp[i/2]+1;
            }else{
                dp[i]=dp[i/2];
            }
        }
        return dp;
    }
};*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};
