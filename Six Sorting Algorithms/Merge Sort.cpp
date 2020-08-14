/// Ahmed Nasser Mohamed
/// 09/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Use divide and conquer technique
              2- divide a sequence into two small sequences
              3- merge the two small sequences in a sorted way
--Time complexity : O(N*log(N))
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=2e5+5, M=127+5, MOD=1e9+7, OO=0x3f3f3f3f;

int n;
int arr[N];


void Merge(int l,int md, int r)
{
    vector <int> L;
    vector <int> R;
    for(int i=l; i<=md; i++)
        L.push_back(arr[i]);
    for(int i=md+1; i<=r; i++)
        R.push_back(arr[i]);
    L.push_back(OO);
    R.push_back(OO);
    int i=0,j=0;
    for(int k=l; k<=r; k++)
    {
        if(L[i]<=R[j])
            arr[k]=L[i++];
        else
            arr[k]=R[j++];
    }
}


void mergeSort(int l, int r)
{
    if(l>=r)
        return;
    int md=(l+r)/2;
    mergeSort(l,md);
    mergeSort(md+1,r);
    Merge(l,md,r);
}




int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",arr+i);
    mergeSort(0,n-1);
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);

}
