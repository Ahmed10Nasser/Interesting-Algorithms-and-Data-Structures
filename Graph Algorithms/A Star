/// Ahmed Nasser Mohamed
/// 14/08/2020

/*
--Problem description : find the shortest paths form a node to a target node
--Solution : 1- use a priority queue to pick the minimum weight each time  
             2- use heuristic function like (Euclidean distance) to choose the right direction  
             3- relax the reached nodes with minimum
             4- stop when reaching the target node
--Time complexity : O((V+E)*log(V))
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=1e5, MOD=1e9+7, OO=0x3f3f3f3f;

#define node    second
#define Hcost   first.first
#define cost    first.second


pair<int,int> xy[N];
int n,m,u,v,w;
vector<int>dis;
vector<pair<int,int>>adj[N];


double euclidean(int u, int v)
{
    double x1=xy[u].first;
    double y1=xy[u].second;
    double x2=xy[v].first;
    double y2=xy[v].second;
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}


void AStar(int src, int tar)
{
    int u,v,c;
    double hc;
    priority_queue<pair<pair<double,int>,int>,vector<pair<pair<double,int>,int>>,greater<pair<pair<double,int>,int>>>q;
    dis=vector<int>(n+1,OO);
    dis[src]=0;
    q.push({{euclidean(src,tar)+0,0},src});
    while(!q.empty())
    {
        u=q.top().node;
        c=q.top().cost;
        q.pop();
        if(u==tar)
            return;
        if(c!=dis[u])
            continue;
        for(pair<int,int> p : adj[u])
        {
            v=p.first;
            c=p.second;
            if(dis[v]>dis[u]+c)
            {
                dis[v]=dis[u]+c;
                q.push({{euclidean(v,tar)+dis[v],dis[v]},v});
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
    for(int i=1; i<=n; i++)
        scanf("%d %d",&xy[i].first,&xy[i].second);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u, &v, &w);
        adj[u].push_back({v,w});
    }
    scanf("%d %d",&u, &v);
    AStar(u,v);
    if(dis[v]==OO)
        puts("-1");
    else
        printf("%d\n",dis[v]);


    return 0;
}
