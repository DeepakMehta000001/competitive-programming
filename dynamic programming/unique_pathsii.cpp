//problem - https://leetcode.com/problems/unique-paths-ii/description/
class Solution {
public:
    bool ok(vector<vector<int>>& obstacleGrid,int i, int j){
        if(!obstacleGrid[i][j])
            return true;
        return false;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int dp[n][m];
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0){
                    if(j==0){
                        if(ok(obstacleGrid, i ,j)){
                            dp[i][j]=1;
                        }else{
                            dp[i][j]=0;
                        }
                    }else{
                        if(ok(obstacleGrid, i ,j)){
                            dp[i][j]=dp[i][j-1];
                        }else{
                            dp[i][j]=0;
                        }
                    }
                }
                if(j==0){
                    if(i==0){
                        if(ok(obstacleGrid, i ,j)){
                            dp[i][j]=1;
                        }else{
                            dp[i][j]=0;
                        }
                    }else{
                        if(ok(obstacleGrid, i ,j)){
                            dp[i][j]=dp[i-1][j];
                        }else{
                            dp[i][j]=0;
                        }
                    }
                }

                if(i>0 && j>0){
                      if(ok(obstacleGrid, i ,j)){
                            dp[i][j]=dp[i-1][j] + dp[i][j-1];
                        }else{
                            dp[i][j]=0;
                       }
                }
                
            }
        }
        return dp[n-1][m-1];
    }
};