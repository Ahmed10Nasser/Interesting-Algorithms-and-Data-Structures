/// Ahmed Nasser Mohamed
/// 16/08/2020

/*
--Description : Trie is a tree of charaters used in search and auto complete 
--Operations with time complexity: Add  O(|S|) - Find O(|S|) - PrintTrie O(sum of all |S|)
*/

#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=1e5+5, M=200+5, MOD=1e9+7, OO=0x3f3f3f3f;


class trie
{
    private:
        int sz;
        vector<vector<pair<int,char>>>adj;
        unordered_set<string>st;
    public:
        trie()
        {
            sz=0;
            vector<pair<int,char>>v;
            adj.push_back(v);
        }
        int getSize()
        {
            return sz;
        }
        void add(string s)
        {
            st.insert(s);
            int sn=s.size();
            int u=0;
            for(int i=0; i<sn; i++)
            {
                bool f=0;
                for(pair<int,char> p : adj[u])
                {
                    if(p.second==s[i])
                    {
                        u=p.first;
                        f=1;
                        break;
                    }
                }
                if(!f)
                {
                    vector<pair<int,char>>v;
                    adj.push_back(v);
                    adj[u].push_back({++sz,s[i]});
                    u=sz;
                }
            }
        }
        pair<bool,string> Find(string s) /// If it finds a match in the given string, returns {1,the first match}
        {                                /// else, returns {0,""};
            int sn=s.size();
            int u=0;
            string ret="";
            for(int i=0; i<sn; i++)
            {
                if((int)(adj[u].size())==0 || st.find(ret)!=st.end())
                    return {1,ret};
                bool f=0;
                for(pair<int,char> p : adj[u])
                {
                    if(p.second==s[i])
                    {
                        u=p.first;
                        ret+=s[i];
                        f=1;
                        break;
                    }
                }
                if(!f)
                    break;
            }
            if((int)(adj[u].size())==0 || st.find(ret)!=st.end())
                    return {1,ret};
            return {0,""};

        }
        void printTrie()
        {
            for(int i=0; i<=sz; i++)
                for(pair<int,char> p : adj[i])
                    cout<<i<<"->"<<p.first<<":"<<p.second<<"\n";
        }

};


int n;
string s;

int main()
{
    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    trie t=trie();
    cin>>n;
    while(n--)
    {
        cin>>s;
        t.add(s);
    }
	t.printTrie();

    return 0;
}
