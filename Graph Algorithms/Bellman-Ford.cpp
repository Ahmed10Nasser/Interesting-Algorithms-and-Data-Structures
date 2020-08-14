/// Ahmed Nasser Mohamed
/// 10/08/2020

/*
--Problem description : find the shortest paths form a node to all other nodes
--Solution : 1- loop with number of vertices
             2- each time iterate over all edges and relax its node with minimum 
--Time complexity : O(V*E)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=1e6+5, MOD=1e9+7, OO=0x3f3f3f3f;

#define from first.first
#define to first.second
#define cost second


int n,m,u,v,w,s;
bool hasCycle;
vector<pair<pair<int,int>,int>>edges;
vector<int> dis;

void bellman(int src)
{
    dis=vector<int>(n+5,OO);
    dis[src]=0;
    for(int i=1; i<=n; i++)
    {
        bool f=0;
        for(auto e : edges)
        {
            if(dis[e.to]>dis[e.from]+e.cost)
            {
                dis[e.to]=dis[e.from]+e.cost;
                f=1;
            }
        }
        if(!f)
            break;
        else if(i==n)
            hasCycle=1;
    }
}


int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d %d",&n, &m, &s);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u, &v, &w);
        edges.push_back({{u,v},w});
    }
    bellman(s);
    if(hasCycle)
        puts("There is a negative cycle");
    else
    {
        for(int i=1; i<=n; i++)
            printf("%d %d\n",i,dis[i]);
    }

}
