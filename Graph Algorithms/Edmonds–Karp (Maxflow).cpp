/// Ahmed Nasser Mohamed
/// 20/08/2020

/*
--Problem description : find the maximum flow from a source node to a target node
--Solution : 1- use BFS to get the shortest path from source to target in terms of the number of edges
             2- find the minimum weight through the shortest path and add it to the flow value
             3- update the graph by subtracting the minimum weight from all same-direction path edges
                and adding the minimum weight from all opposite-direction path edges
             4- repeat until there is no path from the source to the target
--Time complexity : O(E^2 * V)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e2+5, M=200+5, MOD=1e9+7, OO=0x3f3f3f3f;

int n,m,u,v,c,f;
int adj[N][N];


int getFlow(int src, int tar)
{
    int u;
    vector<bool>vis(n+1,0);
    vector<int>par(n+1);
    queue<int>q;
    vis[src]=1;
    par[src]=-1;
    q.push(src);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(u==tar)
            break;
        for(int v=1; v<=n; v++)
        {
            if(adj[u][v] && !vis[v])
            {
                vis[v]=1;
                par[v]=u;
                q.push(v);
            }
        }
    }
    if(u!=tar)
        return 0;
    int mn=OO,v=u;
    while(par[v]!=-1)
    {
        mn=min(mn,adj[par[v]][v]);
        v=par[v];
    }
    while(par[u]!=-1)
    {
        adj[par[u]][u]-=mn;
        adj[u][par[u]]+=mn;
        u=par[u];
    }
    return mn;
}



int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d",&n, &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u, &v, &c);
        adj[u][v]+=c;
    }
    int ans;
    do
    {
        ans=getFlow(1,n);
        f+=ans;
    }
    while(ans);
    printf("%d\n",f);



    return 0;
}
