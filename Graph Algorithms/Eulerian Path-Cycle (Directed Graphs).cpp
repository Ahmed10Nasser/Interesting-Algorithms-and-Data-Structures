/// Ahmed Nasser Mohamed
/// 27/08/2020

/*
--Problem description : find Eulerian path or cycle which goes through each edge exactly once
--Solution : 1- calculate the in and the out degrees for each node
             2- if in and out degrees are equal for all nodes, the Eulerian cycle exists
             3- else if exactly one node has (out - in =1)  and exactly another node has (in - out =1), the Eulerian path exists
             4- do DFS until you stuck, push the current node to the front of the answer
--Time complexity : O(E)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=300+5, MOD=1e9+7, OO=0x3f3f3f3f;
double const EPS=1e-11;

bool ans=1;
int n,m,u,v,st=-1,en=-1;
int in[N],out[N];
vector<int>adj[N],res;



void solve(int u)
{
    while(out[u]!=0)
    {
        int v=adj[u][--out[u]];
        solve(v);
    }
    res.push_back(u);
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
        out[u]++;
        in[v]++;
    }
    for(int i=1; i<=n && ans; i++)
    {
        if(abs(in[i]-out[i])>1)
            ans=0;
        else if(out[i]-in[i]==1)
        {
            if(st==-1)st=i;
            else
                ans=0;
        }
        else if(in[i]-out[i]==1)
        {
            if(en==-1)en=i;
            else ans=0;
        }
    }
    if(!(ans && ((st==-1 && en==-1)||(st!=-1 && en!=-1))))
    {
        puts("NO Eulerian Path/Cycle");
        return 0;
    }
    if(st==-1)
        for(int i=1; i<=n && st==-1; i++)
            if(out[i]>0)
                st=i;
    solve(st);
    if((int)res.size()==m+1)
    {
        for(int i=m; i>=0; i--)
            printf("%d ",res[i]);
        puts("");
    }
    else
        puts("NO Eulerian Path/Cycle");

    return 0;
}
