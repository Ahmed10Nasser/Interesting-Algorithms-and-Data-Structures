// Ahmed Nasser Zaki

/*
--Problem description : Find the lowest common ancestor for two nodes in a tree
--Solution : 1- Use spare table to save the power of 2s ancestors for each node 
             2- Use binary lifting to get the kth ancestor for any node
             3- Get LCA using kth ancestor and binary search
--Time complexity : Preprocessing: O((N+E)*Log(N)), kth ancestor: Log(N), LCA: Log(N) 
*/


#include<bits/stdc++.h>
using namespace std;


struct Node{
  int id=-1;
  int depth=-1;
  vector<Node*> neighbours=vector<Node*>();
  vector<Node*> ancestors=vector<Node*>();
  Node(int _id) : id(_id) {}
};


int Log(int x){
  return 31-__builtin_clz(x);
}

void DFS(Node* node, Node* par){
  for(auto& neighbour : node->neighbours){
    if(neighbour==par) continue;
    neighbour->depth=node->depth+1;
    neighbour->ancestors.push_back(node);
    for(int j=1; (1<<j)<=neighbour->depth; j++)
      neighbour->ancestors.push_back(neighbour->ancestors[j-1]->ancestors[j-1]);
    DFS(neighbour, node);
  }
}

Node* kAnc(Node* node, int k){
  k=min(k, node->depth);
  for(int j=0; (1<<j)<=k; j++)
    if(k & (1<<j))
      node=node->ancestors[j];
  return node;
}

Node* LCA(Node* u, Node* v){
  if(u->depth < v->depth) swap(u,v);
  int d=u->depth - v->depth;
  u=kAnc(u,d);

  if(u==v) return u;

  int m=Log(u->depth);
  for(int j=m; j>=0; j--){
    if(u->ancestors[j]!=v->ancestors[j]){
      u=u->ancestors[j];
      v=v->ancestors[j];
    }
  }
  return u->ancestors[0];
}

int main(){
  int n;
  cin>>n;
  vector<Node*>nodes(n);
  for(int i=0; i<n; i++) nodes[i]=new Node(i);
  for(auto& node : nodes){
    int m;
    cin>>m;
    while(m--){
      int child;
      cin>>child;
      node->neighbours.push_back(nodes[child]);
    }  
  }
  int root=0;
  nodes[root]->depth=0;
  DFS(nodes[root], nodes[root]);
  int q;
  cin>>q;
  while(q--){
    int u,v;
    cin>>u>>v;
    cout<<LCA(nodes[u],nodes[v])->id<<'\n';
  }
  
  return 0;
}
