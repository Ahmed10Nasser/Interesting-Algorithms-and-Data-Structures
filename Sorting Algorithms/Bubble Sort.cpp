/// Ahmed Nasser Mohamed
/// 09/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Iterate over two nested loops
              2- swap two elements if they are not in order
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
    for(int i=0; i<n; i++)
        for(int j=0; j<n-1; j++)
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);

    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);

}
