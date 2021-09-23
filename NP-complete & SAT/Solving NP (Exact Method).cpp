/// Ahmed Nasser Mohamed
/// 31/08/2020

/*
--Problem description : Solving NP problem by exact method. this problem is Traveling Salesman Problem (TSP)
                        which is to find the minimum cost to visit all n nodes traveling from one to another.
--Solution :  1- Use Floyed algorithm to calculate the shortest paths between each node and all other nodes.
              2- Use DP with masks (Dynamic Programming) with minimization concept to find the minimum cost between all possible paths combinations. 
--Time complexity : O((2^n) * (n^2))
*/

#include<bits/stdc++.h>
using namespace std;

int const N=16+5, M=(1<<N), OO = 0x3f3f3f3f;

int n,st,ans;
int mat[N][N];

void floyed()
{
    for(int k=0; k<n; k++)
      for(int u=0; u<n; u++)
        for(int v=0; v<n; v++)
          mat[u][v]=min(mat[u][v],mat[u][k]+mat[k][v]);
}

int mem[N][M];
int solve(int cur, int mask)
{
    if(mask==(1<<n)-1)
        return mat[cur][st];
    if(mem[cur][mask]!=-1)
        return mem[cur][mask];
    int ret=OO;
    for(int nxt=0; nxt<n; nxt++)
    {
        if((mask>>nxt)&1)
            continue;
        ret=min(ret,mat[cur][nxt]+solve(nxt,mask|(1<<nxt)));
    }
    return mem[cur][mask]=ret;
}



int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d",&n, &st);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",mat[i]+j);
    floyed();
    memset(mem, -1, sizeof mem);
    ans=solve(st,(1<<st));
    printf("%d\n",ans);
    return 0;
}
