//problem - https://leetcode.com/problems/climbing-stairs/description/
#include<bits/stdc++.h>
#define pb push_back
#define p(a) pair<int,int>
#define mp make_pair
#define NAX 200001
#define mod 1000000007
#define v(a) vector<int>
#define fastio ios::sync_with_stdio(false)
#define si(a) scanf("%d",&a)
#define ll long long
using namespace std;

int recurr(int n){
    if(n==0){
        return 1;
    }
        
    if(n<0){
        return 0;
    }
        
    return recurr(n-1)+recurr(n-2);
}

int climbStairs(int n) {
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;++i){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){

    int n;
    si(n);
    cout<<recurr(n)<<endl;
    cout<<climbStairs(n)<<endl;
    return 0;
}