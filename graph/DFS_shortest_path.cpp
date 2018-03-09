//Problem - https://www.hackerrank.com/challenges/dijkstrashortreach/problem
//Nature - Classical graph , BFS. 
// It shall result in TLE for this problem, slow approach. Probably require Dijkastra to solve it.

#include<bits/stdc++.h>
using namespace std;
#define NAX 3001
#define pb push_back
#define G vector<vector<pair<int,int> > >
int tests,n,m,x,y,c,src;
int cost[NAX];
int res[NAX];
bool vis[NAX];

void minDFS(G &graph,int p){ 
    vis[p]=true;
    for(int i=0;i<graph[p].size();++i){
        if(!vis[graph[p][i].first] || res[a]+graph[a][i].second < res[graph[a][i].first] ){
            res[graph[p][i].first] = min(res[graph[p][i].first],res[p]+graph[p][i].second);
            minDFS(graph,graph[p][i].first);
        }
    }
}


int main(){
    cin>>tests;
    for(;tests--;){
        cin>>n>>m;
        G graph(n+1);
        fill(vis,vis+NAX,false);
        fill(res,res+NAX,INT_MAX);
        for(int i=1;i<=m;++i){
            cin>>x>>y>>c;
            graph[x].pb(make_pair(y,c));
            graph[y].pb(make_pair(x,c));
        }
        cin>>src;
        res[src]=0;
        minDFS(graph,src);
        //minBFS(graph,src);
        for(int i=1;i<=n;++i){
            if(src==i)
                continue;
            if(res[i]==INT_MAX){
                cout<<-1<<" ";
            }else{
                cout<<res[i]<<" ";
            }
        }
        cout<<endl;
    } 
    return 0;
}