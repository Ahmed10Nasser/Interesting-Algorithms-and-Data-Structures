/// Ahmed Nasser Mohamed
/// 10/08/2020

/*
--Problem description : find the strongly connected components in a directed graph 
--Solution : 1- DFS to find the sort the nodes with maximum post-order number
             2- Another DFS to visit the nodes
--Time complexity : O(V+E)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=5e5+5, M=1e5, MOD=1e9+7, OO=0x3f3f3f3f;

int n,m,u,v;
vector<int>adj[N],adjT[N];
vector <bool>vis;
stack<int>post;


void DFS1(int u)
{
    vis[u]=1;
    for(int v : adjT[u])
        if(!vis[v])
            DFS1(v);
    post.push(u);
}

void DFS2(int u)
{
    vis[u]=1;
    printf("%d ",u);
    for(int v : adj[u])
        if(!vis[v])
            DFS2(v);
}


void kosaraju()
{
    vis=vector<bool>(n+1,0);
    for(int i=1; i<=n; i++)
        if(!vis[i])
            DFS1(i);
    vis=vector<bool>(n+1,0);
    while(!post.empty())
    {
        int i=post.top();
        post.pop();
        if(!vis[i])
        {
            DFS2(i);
            puts("");
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
        scanf("%d %d",&u, &v);
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }
    kosaraju();

    return 0;
}
