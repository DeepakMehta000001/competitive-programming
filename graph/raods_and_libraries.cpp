/*  Problem - https://www.hackerrank.com/challenges/torque-and-development/problem
    Difficulty - Medium
    Graph - Connected Component + Simple implementation. 
*/

#include<bits/stdc++.h>
#define pb push_back
#define p(a) pair<int,int>
#define mp make_pair
#define NAX 100001
#define mod 1000000007
#define v(a) vector<int>
#define fastio ios::sync_with_stdio(false)
#define si(a) scanf("%d",&a)
#define ll long long
using namespace std;
#define gc getchar_unlocked
int read_int() {
    char c = gc();
    while(c<'0' || c>'9') c = gc();
    int ret = 0;
    while(c>='0' && c<='9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return ret;
}

int n,m,libCost, roadCost;
vector<int> components;
bool vis[NAX];
int count_components=0;

void init(){
    fill(vis,vis+NAX,false);
    components.clear();
}

void dfs(int i,vector<int> graph[]){
    count_components++;
    vis[i] = true;
    for(int k=0;k<graph[i].size();++k){
        if(!vis[graph[i][k]]){
            dfs(graph[i][k],graph);
        }
    }    
}


int main(){
    int tests;
    tests = read_int();
    for(;tests;--tests){
        vector<int> graph[NAX];
        init();
        n = read_int();
        m = read_int();
        libCost = read_int();
        roadCost = read_int();
        for(;m--;){
            int x,y;
            x=read_int();
            y=read_int();
            graph[x].pb(y);
            graph[y].pb(x);
        }
        for(int i=1;i<=n;++i){
            if(!vis[i]){
                count_components=0;
                dfs(i,graph);
                components.pb(count_components);
            }
        }
        long long ans=0;
        for(int i=0;i<components.size();++i){
            int k = components[i];
            int j=0;
            long long res=LLONG_MAX;
            while(j<k){
                res = min(res,(long long)((k-j)*libCost)+(j*roadCost));
                j++;
            }
            ans+=res;
        }
        cout<<ans<<endl;
    }
    return 0;
}
