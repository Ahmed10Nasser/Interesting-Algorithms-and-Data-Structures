/// Ahmed Nasser Mohamed
/// 26/03/2020

/*
--Problem description : find the max sum for a consecutive segment in a 1D array
--Solution : 1- use DP approach
             2- iterate over the n element
             3- sum and maximize
             4- if the sum becomes less than zero, initialize sum with zero
--Time complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int const N=1e2+5, M=4e4+5, OO = 0x3f3f3f3f;

int n,a,sum,ans;

int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    sum=ans=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a);
        sum+=a;
        ans=max(ans,sum);
        if(sum<0)
            sum=0;
    }
    printf("%d\n",ans);


}
