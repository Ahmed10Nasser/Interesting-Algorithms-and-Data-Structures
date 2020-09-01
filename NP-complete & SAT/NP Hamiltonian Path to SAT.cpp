/// Ahmed Nasser Mohamed
/// 30/08/2020

/*
--Problem description :Convert the NP problem Hamiltonian path into SAT to be solved by SAT-solver
--Solution :  1- each node must exist exactly once in the path---> first SAT condition
              2- each position must exist exactly once in the path (No position contains more than one node) ---> second SAT condition
              3- No two different non-adjacent nodes are adjacent in position of the path ---> third SAT condition
--Time complexity : O(n^3)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=300+5, MOD=1e9+7, OO=0x3f3f3f3f;
double const EPS=1e-11;


int n,m,c,var,u,v;
vector<vector<int>>ans;
set<pair<int,int>>st;

int num(int i, int j)
{
    return ((i-1)*n)+j;
}
/// i node
/// j position
int main()
{
//    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d %d",&n, &m);
    var=n*n;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&u, &v);
        st.insert({u,v});
        st.insert({v,u});
    }
    /// Exactly One for each node i
    for(int i=1; i<=n; i++)
    {
        vector<int>v1;
        for(int j=1; j<=n; j++)
            v1.push_back(num(i,j));
        ans.push_back(v1);
        int sz=v1.size();
        for(int a=0; a<sz; a++)
            for(int b=a+1; b<sz; b++)
                ans.push_back(vector<int>{-v1[a],-v1[b]});
    }
    /// Exactly One for each position j (Ex : no two nodes occupy same position)
    for(int j=1; j<=n; j++)
    {
        vector<int>v1;
        for(int i=1; i<=n; i++)
            v1.push_back(num(i,j));
        ans.push_back(v1);
        int sz=v1.size();
        for(int a=0; a<sz; a++)
            for(int b=a+1; b<sz; b++)
                ans.push_back(vector<int>{-v1[a],-v1[b]});
    }
    /// No two different non-adjacent nodes are adjacent in position of the path
    for(int a=1; a<=n; a++)
        for(int b=1; b<=n; b++)
            if(a!=b && st.find({a,b})==st.end())
                for(int j=1; j<n; j++)
                    ans.push_back(vector<int>{-num(a,j),-num(b,j+1)});
    c=ans.size();
    printf("%d %d\n",c,var);
    for(vector<int> v : ans)
    {
        for(int x : v)
            printf("%d ",x);
        puts("0");
    }

    return 0;
}
