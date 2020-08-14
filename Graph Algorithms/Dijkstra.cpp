/// Ahmed Nasser Mohamed
/// 10/08/2020

/*
--Problem description : find the shortest paths form a node to all other nodes
--Solution : 1- use a priority queue to pick the minimum weight each time  
             2- relax the reached nodes with minimum
--Time complexity : O((V+E)*log(V))
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=1e5, MOD=1e9+7, OO=0x3f3f3f3f;

int n,m,u,v,w;
vector<int>dis;
vector<pair<int,int>>adj[N];


void dijkstra(int src)
{
    int u,v,c;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    dis[src]=0;
    q.push({0,src});
    while(!q.empty())
    {
        u=q.top().second;
        c=q.top().first;
        q.pop();
        if(c!=dis[u])
            continue;
        for(pair<int,int> p : adj[u])
        {
            v=p.first;
            c=p.second;
            if(dis[v]>dis[u]+c)
            {
                dis[v]=dis[u]+c;
                q.push({dis[v],v});
            }
        }
    }
}



int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d",&n, &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u, &v, &w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dis=vector<int>(n+1,OO);
    dijkstra(1);
    for(int i=1; i<=n; i++)
        printf("%d %d\n",i,dis[i]);


    return 0;
}
