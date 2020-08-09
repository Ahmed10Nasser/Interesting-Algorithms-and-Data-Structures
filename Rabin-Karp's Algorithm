/// Ahmed Nasser Mohamed
/// 06/08/2020

/*
--Problem description : find all occurrences of string T in string S.
--Solution :  1- Hash all sub-strings in S of length |T| using polynomial hash function
              2- Hash T with the same hash function
              3- Compare the hash values of all sub-strings in S of length |T| with the hash value of T
              4- If the hash values are not the same, so they are definitely not the same strings
              5- Else, there may be a collusion, so compare the two strings character by character to see if they are the same or not
--Time complexity : O(|S| + q*|T|) where q is the number of times for T occurrence in S
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=5e5+5, M=1e5, MOD=1e9+7, OO=0x3f3f3f3f;


string s,t;
int n,m;
ll x,p,tHash,Hash[N];
vector<int>ans;


ll random(ll mn, ll mx)
{
   static bool first=true;
   if(first)
   {
      srand(time(NULL));
      first=false;
   }
   return mn+rand()%((mx+1)-mn);
}

ll modPower(ll a, ll b, ll m)
{
    if(!b)
        return 1;
    ll t= (modPower(a, b>>1,m))%m;
    return ((t*t)%m*((b&1) ? a : 1)%m)%m;
}


ll polyHash(string a)
{
    int sz=a.size();
    ll ret=0;
    for(int i=sz-1; i>=0; i--)
        ret=(ret*x+a[i])%p;
    return ret;
}


void buildHash()
{
    Hash[n-m]=polyHash(s.substr(n-m));
    ll y=modPower(x,m,p);
    for(int i=n-m-1; i>=0; i--)
        Hash[i]=(((x*Hash[i+1]+s[i]-y*s[i+m])%p)+p)%p;
}


int main()
{
    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    cin>>s>>t;
    n=s.size();
    m=t.size();
    p=1e9+7;
    x=random(1,p-1);
    tHash=polyHash(t);
    buildHash();
    for(int i=0; i<=n-m; i++)
    {
        if(Hash[i]!=tHash)
            continue;
        if(t==s.substr(i,m))
            ans.push_back(i);
    }
    for(int i : ans)
        cout<<i<<" ";
    cout<<"\n";



    return 0;
}
