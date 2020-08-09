/// Ahmed Nasser Mohamed
/// 13/07/2020

/*
--Problem description : sort a given sequence of N elements.
--Solution :  1- recursively, choose an element as a pivot 
              2- insert the pivot in its right position
              3- repeat the same two steps for the right and the left partitions for the pivot
--Time complexity : O(N*log(N))
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=2e5+5, M=1e3+5, MOD=1e9+7, OO=0x3f3f3f3f;

int n;
int arr[N];



int random(int mn, int mx)
{
   static bool first=true;
   if(first)
   {
      srand(time(NULL));
      first=false;
   }
   return mn+rand()%((mx+1)-mn);
}


pair<int,int> Partition(int l, int r)
{
    int m1=l-1,m2=l;
    for(int i=l+1; i<=r; i++)
    {
        if(arr[i]<arr[m2])
        {
            swap(arr[++m1],arr[i]);
            swap(arr[++m2],arr[i]);
        }
        else if(arr[i]==arr[m2])
            swap(arr[++m2],arr[i]);
    }
    return {m1+1,m2};
}


// MAX stack space is log(n)
void quickSort(int l, int r)
{
    while(l<r)
    {

//        swap(arr[l],arr[random(l,r)]); /// Randomized Pivot
//        pair<int,int>md[]={{arr[l],l},{arr[(l+r)/2],(l+r)/2},{arr[r],r}}; /// Median Pivot
//        sort(md,md+3);
//        swap(arr[l],arr[md[1].second]);
        pair<int,int> m1m2=Partition(l,r);
        if(m1m2.first-l<r-m1m2.second)
        {
            quickSort(l,m1m2.first-1);
            l=m1m2.second+1;
        }
        else
        {
            quickSort(m1m2.second+1,r);
            r=m1m2.first-1;
        }
    }
}

// MAX stack space is n and AVARAGE stack space is log(n)
//void quickSort(int l, int r)
//{
//    if(l>=r)
//        return;
////    swap(arr[l],arr[random(l,r)]); /// Randomized Pivot
////    pair<int,int>md[]={{arr[l],l},{arr[(l+r)/2],(l+r)/2},{arr[r],r}}; /// Median Pivot
////    sort(md,md+3);
////    swap(arr[l],arr[md[1].second]);
//    pair<int,int> m1m2=Partition(l,r);
//    quickSort(l,m1m2.first-1);
//    quickSort(m1m2.second+1,r);
//}




int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",arr+i);
    quickSort(0,n-1);
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
    puts("");
    return 0;
}
