/// Ahmed Nasser Mohamed
/// 30/08/2020

/*
--Problem description :Convert the NP problem 3-grah coloring into SAT to be solved by SAT-solver
--Solution :  1- each node must be colored by exactly one color ---> first SAT condition
              2- each edge must have different colored two nodes ---> second SAT condition
--Time complexity : O(n)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=300+5, MOD=1e9+7, OO=0x3f3f3f3f;
double const EPS=1e-11;


int n,m,c,var,u,v;

int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d",&n, &m);
    var=3*n;
    c=4*n + 3*m;
    printf("%d %d\n",c,var);
    for(int i=0, j=0; i<n; i++,j+=3)
    {
        printf("%d %d %d 0\n",j+1,j+2,j+3);
        printf("%d %d 0\n",-(j+1),-(j+2));
        printf("%d %d 0\n",-(j+1),-(j+3));
        printf("%d %d 0\n",-(j+2),-(j+3));
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&u ,&v);
        u=(u-1)*3;
        v=(v-1)*3;
        printf("%d %d 0\n",-(u+1),-(v+1));
        printf("%d %d 0\n",-(u+2),-(v+2));
        printf("%d %d 0\n",-(u+3),-(v+3));
    }


    return 0;
}
