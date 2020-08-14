/// Ahmed Nasser Mohamed
/// 06/08/2020

/*
--Problem description : find all occurrences of string T in string S.
--Solution :  1- Hash all sub-strings in S of length |T| using two different polynomial hash functions
              2- Hash T with the same two hash functions
              3- Compare the hash values of all sub-strings in S of length |T| with the hash values of T
              4- If the first hash function values are the same and the second hash function values are the same, so the strings are the same.
              5- Else, the strings are not the same
--Time complexity : O(|S|) with probability of wrong answers less than (|T|/p1)*(|T|/p2) which is <= 1e-18 almost zero,
                    and it is better to use more different hash functions.
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=5e5+5, M=1e5, MOD=1e9+7, OO=0x3f3f3f3f;


string s,t;
int n,m;
ll x,p1=1e9+7,p2=1e9+9,tHash1,tHash2,Hash1[N],Hash2[N];
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


ll polyHash(string a, ll p)
{
    int sz=a.size();
    ll ret=0;
    for(int i=sz-1; i>=0; i--)
        ret=(ret*x+a[i])%p;
    return ret;
}


void buildHash()
{
    Hash1[n-m]=polyHash(s.substr(n-m),p1);
    Hash2[n-m]=polyHash(s.substr(n-m),p2);
    ll y1=modPower(x,m,p1);
    ll y2=modPower(x,m,p2);
    for(int i=n-m-1; i>=0; i--)
    {
        Hash1[i]=(((x*Hash1[i+1]+s[i]-y1*s[i+m])%p1)+p1)%p1;
        Hash2[i]=(((x*Hash2[i+1]+s[i]-y2*s[i+m])%p2)+p2)%p2;

    }
}


int main()
{
    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    cin>>s>>t;
    n=s.size();
    m=t.size();
    x=random(1,1e9);
    tHash1=polyHash(t,p1);
    tHash2=polyHash(t,p2);
    buildHash();
    for(int i=0; i<=n-m; i++)
    {
        if(Hash1[i]==tHash1 && Hash2[i]==tHash2)
            ans.push_back(i);
    }
    for(int i : ans)
        cout<<i<<" ";
    cout<<"\n";



    return 0;
}
