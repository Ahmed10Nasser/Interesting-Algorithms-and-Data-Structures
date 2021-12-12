/// Ahmed Nasser Mohamed
/// 09/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Iterate over the N elements
              2- for each itration, find the right postion to put (insert) the current element
--Time complexity : O(N^2)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=2e5+5, M=127+5, MOD=1e9+7, OO=0x3f3f3f3f;

int n;
int arr[N];




int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",arr+i);
    for(int i=1; i<n; i++)
    {
        int cur=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>cur)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=cur;
    }
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);

}
