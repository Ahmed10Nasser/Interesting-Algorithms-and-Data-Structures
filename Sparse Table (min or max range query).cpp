/// Ahmed Nasser Mohamed
/// 30/06/2020

/*
--Problem description : answering min/max range queries in a given sequence
--Solution : use logarithmic base 2 function to build the a N*log(N) table, then answering in O(1)
--Time complexity : O(nlog(n)) for preprocessing and O(1) for answering a query
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=2e5+5, M=17+5, MOD=1e9+7, OO=0x3f3f3f3f;

int n,q,a,b;
int arr[N];
int table[N][M];

int Log(int x)
{
    return 32-__builtin_clz(x)-1;
}

void bulidTable()
{
    for(int i=0; i<n; i++)
        table[i][0]=arr[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=0; i+(1<<j)-1<n; i++)
            table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
}

int quary(int i, int j)
{
    int l=j-i+1;
    int k=Log(l);
    return min(table[i][k],table[i+l-(1<<k)][k]);
}



int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d",&n,&q);
    for(int i=0; i<n; i++)
        scanf("%d",arr+i);
    bulidTable();
    while(q--)
    {
        scanf("%d %d",&a, &b);
        printf("%d\n",quary(a,b));
    }
    return 0;
}
