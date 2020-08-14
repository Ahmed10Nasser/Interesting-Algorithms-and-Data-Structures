/// Ahmed Nasser Mohamed
/// 10/08/2020

/*
--Problem description : find the minimum spanning tree in a weighted graph
--Solution : 1- start with a random node
             2- pick the minimum available edge
--Time complexity : O(nlog(n))
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=1e6+5, MOD=1e9+7, OO=0x3f3f3f3f;


int n,m,u,v,w,ans;
bool vis[N];
vector<pair<int,int>>adj[N];

void prim()
{
    int u,v,c;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    q.push({0,1});
    while(!q.empty())
    {
        u=q.top().second;
        c=q.top().first;
        q.pop();
        if(vis[u])
            continue;
        ans+=c;
        vis[u]=1;
        for(pair<int,int> p : adj[u])
        {
            v=p.first;
            c=p.second;
            if(!vis[v])
                q.push({c,v});
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
    prim();
    printf("%d\n",ans);

    return 0;
}
