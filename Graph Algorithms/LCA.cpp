#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
 
const int N=2e5+5, M=17+5, MOD=1073741824, OO=0x3f3f3f3f;
const long double ESP=1e-8;
 
 
 
int n,m;
vector<vector<int>>adj,anc;
vector<int>depth;
 
 
int LOG(int x){
    return 32-__builtin_clz(x)-1;
}
 
 
void DFS(int u){
    for(int v : adj[u]){
        depth[v]=depth[u]+1;
        anc[v][0]=u;
        for(int i=1; i<m; i++)
            anc[v][i]=anc[anc[v][i-1]][i-1];
        DFS(v);
    }
}   
 
 
int LCA(int u, int v){
    if(depth[u]<depth[v]) 
        swap(u,v);
    int k=depth[u]-depth[v];
    for(int i=m-1; i>=0; i--)
        if(k & (1<<i))
            u=anc[u][i];
    if(u==v)
        return u;
    for(int i=m-1; i>=0; i--){
        if(anc[u][i]!=anc[v][i]){
            u=anc[u][i];
            v=anc[v][i];
        }
    }
    return anc[u][0];
}
 
 
 
int main(){
    FIO
//    freopen("mahdi.in","rt",stdin);
//    freopen("output.txt","wt",stdout);
    cin>>n;
    m=LOG(n)+1;
    adj.resize(n);
    depth.resize(n);
    anc=vector<vector<int>>(n,vector<int>(m));
    for(int i=0; i<n; i++){
        int k,u;
        cin>>k;
        while(k--){
            cin>>u;
            adj[i].push_back(u);
        }
    }
    DFS(0);
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<LCA(u,v)<<'\n';
    }
 
 
    return 0;
 
}
