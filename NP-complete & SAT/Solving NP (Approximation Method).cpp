/// Ahmed Nasser Mohamed
/// 31/08/2020

/*
--Problem description : solve NP problem by approximation method. this problem is vertex cover
--Solution :  1- chose a random edge
              2- insert their endpoints in the answer
              3- remove all other edges connected to these endpoints
              4- repeat
              5- This gives a 2-approximate solution <= 2*optimal solution
--Time complexity : O(n)
*/


#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=300+5, MOD=1e9+7, OO=0x3f3f3f3f;
double const EPS=1e-11;

int n,m,u,v;
unordered_set<int>st;
vector<pair<int,int>>edge;


int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d",&n, &ma);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&u, &v);
        edge.push_back({u,v});
    }
    for(int i=0; i<m; i++)
    {
        if(st.find(edge[i].first)==st.end() && st.find(edge[i].second)==st.end())
        {
            st.insert(edge[i].first);
            st.insert(edge[i].second);
        }
    }
    printf("%d\n",(int)st.size());
    for(int x : st)
        printf("%d ",x);
    puts("");


    return 0;
}
