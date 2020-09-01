/// Ahmed Nasser Mohamed
/// 31/08/2020

/*
--Problem description : solve NP problem by special cases method. this problem is 2-SAT and solved by implication graph
--Solution :  1- construct the implication graph 
              2- construct the strongly connected components of the implication graph
 3- If there is a SCC containing a variable an its negation, so the problem is unsatisfiable
4- else, assign ones to SCC in topological order, and zero to its negation SCCs
--Time complexity : O(V+E)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=2e6+5, M=300+5, MOD=1e9+7, OO=0x3f3f3f3f;
double const EPS=1e-11;

int var,c,u,v,n,sccn;
int par[N];
bool isSat=1;
vector<int>adj[N],adjT[N];
vector<vector<int>>scc;
vector<int>vc,ans,sccAns;
vector<bool>vis;
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
    scc[sccn].push_back(u);
    par[u]=sccn;
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
            scc.push_back(vc);
            DFS2(i);
            sccn++;
        }
    }
}


int nag(int x)
{
    if(x>var)
        return x-var;
    return x+var;
}

int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d",&var, &c);
    n=2*var;
    for(int i=0; i<c; i++)
    {
        scanf("%d %d",&u, &v);
        if(u<0)
            u=-u+var;
        if(v<0)
            v=-v+var;
        adj[nag(u)].push_back(v);
        adjT[v].push_back(nag(u));
        adj[nag(v)].push_back(u);
        adjT[u].push_back(nag(v));
    }
    kosaraju();
    for(int i=1; i<=var && isSat; i++)
        if(par[i]==par[i+var])
            isSat=0;
    if(!isSat)
    {

        puts("UNSATISFIABLE");
        return 0;
    }
    sccAns=vector<int>(sccn,0);
    ans=vector<int>(n+1);
    for(int i=0; i<sccn; i++)
    {
        int sz=scc[i].size();
        int tt=sccAns[i];
        if(tt==0)
            tt=1;
        for(int j=0; j<sz; j++)
        {
            ans[scc[i][j]]=scc[i][j]*tt;
            ans[nag(scc[i][j])]=nag(scc[i][j])*tt*-1;
            sccAns[par[nag(scc[i][j])]]=tt*-1;
        }
    }
    puts("SATISFIABLE");
    for(int i=1; i<=var; i++)
        printf("%d ",ans[i]);
    puts("");




    return 0;
}
