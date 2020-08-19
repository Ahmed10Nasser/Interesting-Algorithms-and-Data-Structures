/// Ahmed Nasser Mohamed
/// 17/08/2020

/*
--Problem description : find all occurrences of string P in string S.
--Solution :  1- append S to P with '$' between them
              2- build prefix array for the new string which holds ,for each i, the longest length for the same prefix and suffix from 0 to i
              3- for each i greater than |P|, if prefix[i]==|P|, so position i-2*|P| is an occurrence for P in S
--Time complexity : O(|S|+|P|)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=2e5+5, M=200+5, MOD=1e9+7, OO=0x3f3f3f3f;


int n,m;
string s,p;
vector<int>prefix,ans;

void buildPrefix()
{
    prefix=vector<int>(n);
    int border=0;
    prefix[0]=0;
    for(int i=1; i<n; i++)
    {
        while(border>0 && s[i]!=s[border])
            border=prefix[border-1];
        if(s[i]==s[border])
            border++;
        else
            border=0;
        prefix[i]=border;
    }
}


int main()
{
    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    cin>>s>>p;
    s=p+'$'+s;
    n=s.size();
    m=p.size();
    buildPrefix();
    for(int i=m+1; i<n; i++)
        if(prefix[i]==m)
            ans.push_back(i-2*m);
    cout<<ans.size()<<"\n";
    for(int x : ans)
        cout<<x<<" ";
    cout<<"\n";

    return 0;
}
