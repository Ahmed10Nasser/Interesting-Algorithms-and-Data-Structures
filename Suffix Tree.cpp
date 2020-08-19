/// Ahmed Nasser Mohamed
/// 16/08/2020

/*
--Description : a tree holds all suffixes of a string in memory efficient way
--Operations with time complexity: build  O(|S|^2) - Find O(|S|+|P|) - PrintTree O(|S|^2)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=200+5, MOD=1e9+7, OO=0x3f3f3f3f;


#define V first
#define I second.first
#define L second.second


class suffTree
{
    private:
        int sz;
        string s;
        vector<vector<pair<int,pair<int,int>>>>adj;
        int common(string a, int i, int n, string b, int j, int m)
        {
            int lo=0, md, hi=min(n,m);
            while(hi-lo>0)
            {
                md=(lo+hi+1)/2;
                if(a.substr(i,md)==b.substr(j,md))
                    lo=md;
                else
                    hi=md-1;
            }
            return hi;
        }
        void add(int i, int l)
        {
            int u=0;
            vector<pair<int,pair<int,int>>>v;
            while(true)
            {
                bool f=0;
                for(pair<int,pair<int,int>> &p : adj[u])
                {
                    int c=common(s,i,l,s,p.I,p.L);
                    if(c)
                    {
                        if(p.L-c)
                        {
                            adj.push_back(v);
                            swap(adj[++sz],adj[p.V]);
                            adj[p.V].push_back({sz,{p.I+c,p.L-c}});
                        }
                        i+=c;
                        l-=c;
                        p.L=c;
                        u=p.V;
                        f=1;
                        break;
                    }
                }
                if(!f)
                {
                    adj.push_back(v);
                    adj[u].push_back({++sz,{i,l}});
                    break;
                }
            }
        }
    public:
        suffTree(string S)
        {
            sz=0;
            s=S+'$';
            vector<pair<int,pair<int,int>>>v;
            adj.push_back(v);
        }
        int Find(string a)
        {
            int u,i,l,an,sum=0;
            u=i=0;
            an=l=a.size();
            while(true)
            {
                bool f=0, fb=0;
                for(pair<int,pair<int,int>> p : adj[u])
                {
                    int c=common(s,p.I,p.L,a,i,l);
                    if(c)
                    {
                        i+=c;
                        if(i==an)
                            return p.I-sum;
                        if(c!=p.L)
                            return -1;
                        sum+=c;
                        l-=c;
                        f=1;
                        u=p.V;
                        break;
                    }
                }
                if(!f)
                    return -1;
            }
        }
        void buildTree()
        {
            int n=s.size();
            for(int i=0; i<n-1; i++)
                add(i,n-i);
        }
        void printTree()
        {
            for(int i=0; i<=sz; i++)
                for(pair<int,pair<int,int>> p : adj[i])
                    cout<<i<<"->"<<p.V<<":"<<s.substr(p.I,p.L)<<"\n";
        }
};

string a;

int main()
{
    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    cin>>a;
    suffTree t=suffTree(a);
    t.buildTree();
    t.printTree();



    return 0;
}
