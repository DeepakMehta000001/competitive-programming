//Problem - https://www.hackerrank.com/challenges/dijkstrashortreach/problem
//Nature - Classical graph , Dijkstra , using priority_queue 

#include<bits/stdc++.h>
using namespace std;
#define NAX 3001
#define pb push_back
#define G vector<vector<pair<int,int> > >
int tests,n,m,x,y,c,src;
int cost[NAX];
int res[NAX];
bool vis[NAX];


void minBFS(G &graph,int p){ 
    res[p] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, p));
        while(!pq.empty())
        {
            int v = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(vis[v]) continue;
            vis[v] = 1;
            //for(auto it: graph[v])
            for(int i=0;i<graph[v].size();++i)
            {
                pair<int,int> it=graph[v][i];
                int u = it.first;
                int w = it.second;
                if(res[v] + w < res[u])
                {
                    res[u] = res[v] + w;
                    pq.push(make_pair(res[u],u));
                }
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
        minBFS(graph,src);
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