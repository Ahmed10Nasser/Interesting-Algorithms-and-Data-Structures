/// Ahmed Nasser Mohamed
/// 29/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- Convert the given sequence into max heap using sift-down technique
              2- iterating n times
              3- for each iteration, take the root of the heap (max element so far) and remove it from the heap
--Time complexity : O(N*log(N))
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e2+5, M=17+5, MOD=1e9+7, OO=0x3f3f3f3f;

int n,sz;
int arr[N];


void siftDown(int i)    /// O(log(n))
{
    int mxi=i;
    int l=2*i;
    if(l<=sz && arr[l]>arr[mxi])
        mxi=l;
    int r=2*i+1;
    if(r<=sz && arr[r]>arr[mxi])
        mxi=r;
    if(mxi!=i)
    {
        swap(arr[i],arr[mxi]);
        siftDown(mxi);
    }
}


void buildHeap()    /// O(n)
{
    for(int i=n/2; i>0; i--)
        siftDown(i);
}

void heapSort()     /// O(nlog(n))
{
    buildHeap();
    for(int i=1; i<n; i++)
    {
        swap(arr[sz--],arr[1]);
        siftDown(1);
    }
}



int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d",&n);
    sz=n;
    for(int i=1; i<=n; i++)
        scanf("%d",arr+i);
    heapSort();
    for(int i=1; i<=n; i++)
        printf("%d ",arr[i]);
    puts("");


    return 0;
}
