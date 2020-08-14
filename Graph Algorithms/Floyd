/// Ahmed Nasser Mohamed
/// 10/08/2020

/*
--Problem description : find the shortest paths form all nodes to all nodes
--Solution : 1- iterate over three nested loops representing u,v, and k
             2- see if it is the minimum to go from u to v directly or go through k
--Time complexity : O(n^3)
*/

#include<bits/stdc++.h>
using namespace std;

int const N=100+5, M=1e5+5, OO = 0x3f3f3f3f;

int n,m,q,u,v,w;
vector<vector<int>> mat;

void floyd()
{
    for(int u=0; u<n; u++)
        for(int v=0; v<n; v++)
            for(int k=0; k<n; k++)
                mat[u][v]=min(mat[u][v],mat[u][k]+mat[k][v]);
}



int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d %d",&n, &m, &q);
    mat=vector<vector<int>>(n+5,vector<int>(n+5,OO));
    for(int i=1; i<=n; i++)
        mat[i][i]=0;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u, &v, &w);
        mat[u][v]=min(w,mat[u][v]);
        mat[v][u]=min(w,mat[v][u]);
    }
    floyd();
    while(q--)
    {
        scanf("%d %d",&u, &v);
        printf("%d\n",mat[u][v]);
    }

}
