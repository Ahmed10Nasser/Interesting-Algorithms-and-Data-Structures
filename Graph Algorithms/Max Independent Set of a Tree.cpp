/// Ahmed Nasser Mohamed
/// 1/09/2020

/*
--Problem description : find the maximum set of vertices such that there is no edge between any two of them
--Solution : 1- take the current leaves
             2- remove the leaves and their parents 
             3- repeat
--Time complexity : O(V+E)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=300+5, MOD=1e9+7, OO=0x3f3f3f3f;
double const EPS=1e-11;

int n,m,u,v;
int par[N],deg[N];
vector<int>adj[N];
vector<bool>take;
queue<int>q;
vector<int>ans;


void DFS(int u, int pr)
{
    par[u]=pr;
    for(int v : adj[u])
        if(v!=pr)
            DFS(v,u);
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
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    take=vector<bool>(n,1);
    for(int i=0; i<n; i++)
        if(deg[i]==1)
            q.push(i);
    DFS(0,n);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        deg[x]--;
        deg[par[x]]--;
        if(deg[par[x]]==1)
            q.push(par[x]);
        if(take[x])
        {
            ans.push_back(x);
            take[par[x]]=0;
        }
    }
    printf("%d\n",(int)ans.size());
    for(int x : ans)
        printf("%d ",x);
    puts("");
    
    return 0;
}
