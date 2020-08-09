/// Ahmed Nasser Mohamed
/// 04/04/2020

/*
--Problem description : find the minimum spanning tree in a weighted graph
--Solution : 1- use DSU (Disjoint Set Union) data structure
             2- sort the weighted edges
             3- Pick only the needed edges (so far)
--Time complexity : O(nlog(n))
*/

#include<bits/stdc++.h>
using namespace std;

int const N=1e5+5, M=1e5+5, OO = 0x3f3f3f3f, MOD=1e9+7;

#define cost first
#define from second.first
#define to  second.second


int n,m,c,u,v;
pair<int,pair<int,int>> edges[M];
int par[N];

int findParent(int u)
{
    if(par[u]==u)
        return u;
    return par[u]=findParent(par[u]);

}

void join(int a, int b)
{
    a=findParent(a);
    b=findParent(b);
    if(a!=b)
        par[b]=a;
}



int kruskal()
{
    int ret=0;
    iota(par,par+n+1,0);
    sort(edges,edges+m);
    for(int i=0; i<m; i++)
    {
        if(findParent(edges[i].to)!=findParent(edges[i].from))
        {
            join(edges[i].from,edges[i].to);
            ret+=edges[i].cost;
        }
    }
    return ret;
}


int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d",&n, &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u,&v,&c);
        edges[i]={c,{u,v}};
    }
    printf("%d\n",kruskal());

    return 0;
}
