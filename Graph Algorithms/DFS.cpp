/// Ahmed Nasser Mohamed
/// 2/01/2022

/*
--Problem description : Traverse a graph
--Solution : 1- Represent graph as adjacency list where each node has its neighbours
             2- Recurse over the nodes without visiting each node more than once
--Time complexity : O((V+E)) where V is number of nodes, and E is number of edges 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
  bool vis=0;
  vector<Node*>neighbours={};
};

void DFS(Node* node){
  // pre-order (befor DFS call)

  node->vis=1;
  for(auto& neighbour : node->neighbours)
    if(neighbour->vis==0)
      DFS(neighbour);

  // post-order (after DFS calls)
}


int main(){
  int n,m;
  cin>>n>>m;
  vector<Node*>nodes(n);
  for(auto& node : nodes) node=new Node;
  while(m--){
    int u,v;
    cin>>u>>v;
    u--,v--;
    nodes[u]->neighbours.push_back(nodes[v]);
    nodes[v]->neighbours.push_back(nodes[u]);
  }
  DFS(nodes[0]);
  return 0;
}
