/// Ahmed Nasser Mohamed
/// 19/08/2020

/*
--Problem description : find all occurrences of N strings (P) in string S.
--Solution :  1- construct the suffix array for the string S
              2- construct the BWT(S) from using the suffix array
              3- for each string P, use last first property of Burrows-Wheeler to find the matches
--Time complexity : |T|log(|T|)  	    ---> for construction suffix array and BWT
                    +
                    |T| + |P|         ---> for search for ALL match for a pattern
*/


#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=2e5+5, M=200+5, MOD=1e9+7, OO=0x3f3f3f3f;

int t,n,m,L;
string s,ss,BWT,a;
vector<int>suffArr,classArr;
unordered_map<char,int>fo;
unordered_map<char,vector<int>>cnt;


void sortChars()
{
    vector<int>cntSort(27,0);
    for(int i=0; i<n; i++)
        cntSort[max(0,s[i]-96)]++;
    ss+=string(cntSort[0],'$');
    for(int i=1; i<27; i++)
    {
        ss+=string(cntSort[i],(char)(i+96));
        cntSort[i]+=cntSort[i-1];
    }
    for(int i=0; i<n; i++)
        suffArr[--cntSort[max(0,s[i]-96)]]=i;
}

void charsClasses()
{
    classArr[suffArr[0]]=0;
    for(int i=1; i<n; i++)
    {
        if(s[suffArr[i]]==s[suffArr[i-1]])
            classArr[suffArr[i]]=classArr[suffArr[i-1]];
        else
            classArr[suffArr[i]]=classArr[suffArr[i-1]]+1;
    }
}


void sortDoubleL()
{
    vector<int>cntSort(n,0),newSuff(n,0);
    for(int i=0; i<n; i++)
        cntSort[classArr[i]]++;
    for(int i=1; i<n; i++)
        cntSort[i]+=cntSort[i-1];
    for(int i=n-1; i>=0; i--)
    {
        int st=(((suffArr[i]-L)%n)+n)%n;
        newSuff[--cntSort[classArr[st]]]=st;
    }
    suffArr=newSuff;
}

void doubleLClasses()
{
    vector<int>newClass(n,0);
    newClass[suffArr[0]]=0;
    for(int i=1; i<n; i++)
    {
        int cur, midCur, prev, midPrev;
        cur=suffArr[i];
        midCur=(cur+L)%n;
        prev=suffArr[i-1];
        midPrev=(prev+L)%n;
        if(classArr[cur]!=classArr[prev] || classArr[midCur]!=classArr[midPrev])
            newClass[cur]=newClass[prev]+1;
        else
            newClass[cur]=newClass[prev];
    }
    classArr=newClass;
}



pair<int,int> solve()
{
    int top=0, bottom=n-1;
    for(int i=m-1; i>=0 && top<=bottom; i--)
    {
        if(fo.find(a[i])!=fo.end())
        {
            if(cnt[a[i]][bottom+1]-cnt[a[i]][top]>0)
            {
                top=fo[a[i]]+cnt[a[i]][top];
                bottom=fo[a[i]]+cnt[a[i]][bottom+1]-1;
            }
            else
                return {-1,-1};
        }
        else
            return {-1,-1};
    }
    return {top,bottom};

}

int main()
{
    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    cin>>s>>t;
    s+='$';
    n=s.size();
    vector<int>v(n+1,0);
    suffArr=vector<int>(n,0);
    classArr=vector<int>(n,0);
    sortChars();
    charsClasses();
    L=1;
    while(L<n)
    {
        sortDoubleL();
        doubleLClasses();
        L*=2;
    }
    for(int i=0; i<n; i++)
        BWT+=s[(((suffArr[i]-1)%n)+n)%n];
    s=BWT;
    for(int i=0; i<n; i++)
    {
        if(fo.find(ss[i])==fo.end())
            fo[ss[i]]=i;
        if(cnt.find(s[i])==cnt.end())
            cnt[s[i]]=v;
        cnt[s[i]][i+1]++;
    }
    for(int i=1; i<=n; i++)
        for(pair<char,int> p : fo)
            cnt[p.first][i]+=cnt[p.first][i-1];
    while(t--)
    {
        cin>>a;
        m=a.size();
        pair<int,int>ans=solve();
        if(ans.first!=-1)
        {
            cout<<ans.second-ans.first+1<<"\n";
                for(int i=ans.first; i<=ans.second; i++)
                    cout<<suffArr[i]<<" ";
            cout<<"\n";
        }
        else
            cout<<"0\n";
    }



    return 0;
}
