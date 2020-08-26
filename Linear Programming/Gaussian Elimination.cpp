/// Ahmed Nasser Mohamed
/// 24/08/2020

/*
--Problem description : solving system of linear equations.
--Solution :  Use the known Gaussian elimination technique 
--Time complexity : O(n^2)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=20+5, M=200+5, MOD=1e9+7, OO=0x3f3f3f3f;

int n;
double arr[N][N],ans[N];


int main()
{
    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<=n; j++)
            cin>>arr[i][j];
    for(int i=0; i<n; i++)
        for(int k=i+1; k<n; k++)
            if(fabs(arr[i][i])<fabs(arr[k][i]))
                swap(arr[i],arr[k]);
    for(int i=0; i<n-1; i++)
    {
        for(int k=i+1; k<n; k++)
        {
            double tt=arr[k][i]/arr[i][i];
            for(int j=0; j<=n; j++)
                arr[k][j]-=tt*arr[i][j];
        }
    }

    for(int i=n; i>=0; i--)
    {
        ans[i]=arr[i][n];
        for(int j=i+1; j<n; j++)
            ans[i]-=arr[i][j]*ans[j];
        ans[i]/=arr[i][i];
    }
    cout<<setprecision(6)<<fixed;
    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
    return 0;
}
