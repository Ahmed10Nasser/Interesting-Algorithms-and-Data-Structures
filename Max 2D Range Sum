/// Ahmed Nasser Mohamed
/// 26/03/2020

/*
--Problem description : find the max sum for a rectangle in a 2D array
--Solution : 1- use DP approach with prefix sum
             2- iterate over two nested loops representing left and right columns
             3- run max 1D range sum over the prefix sums for the rows between the selected left and right columns
--Time complexity : O(n*(m^2))
*/

#include<bits/stdc++.h>
using namespace std;

int const N=1e2+5, M=4e4+5, OO = 0x3f3f3f3f;

int n,m,mx=-OO,ans=-OO,sum,u,d,ansl,ansr,ansu,ansd,tu;
int arr[N][N];

int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d",&n, &m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&arr[i][j]);
            arr[i][j]+=arr[i][j-1];
        }
    for(int l=1; l<=m; l++)
    {
        for(int r=l; r<=m; r++)
        {
            mx=-OO;
            sum=u=d=tu=0;
            for(int k=1; k<=n; k++)
            {
                sum+=arr[k][r]-arr[k][l-1];
                if(sum>mx)
                {
                    mx=sum;
                    u=tu;
                    d=k;
                }
                if(sum<0)
                {
                    sum=0;
                    tu=k+1;
                }
            }
            if(mx>ans)
            {
                ans=mx;
                ansl=l;
                ansr=r;
                ansu=u;
                ansd=d;
            }
        }
    }
    printf("Max sum is: %d\nleft: %d right: %d top: %d bottom: %d\n",ans,ansl,ansr,ansu,ansd);


}
