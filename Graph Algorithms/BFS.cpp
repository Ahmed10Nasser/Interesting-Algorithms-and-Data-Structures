// Ahmed Nasser Zaki

/*
--Problem description : Traverse a graph Level by Level
--Solution : 1- Represent graph as adjacency list where each node has its neighbours
             2- Use queue so can traversing level by level
--Time complexity : O((V+E)) where V is number of nodes, and E is number of edges 
*/

#include<bits/stdc++.h>
using namespace std;

struct  Node{
  bool vis=0;
  vector<Node*>neighbours=vector<Node*>();
};


void BFS(Node* src){
  queue<Node*>q;
  src->vis=1;
  q.push(src);
  while(!q.empty()){
    Node* node=q.front();
    q.pop();
    for(auto& neighbour : node->neighbours){
      if(neighbour->vis==0){
        neighbour->vis=1;
        q.push(neighbour);
      }
    }    
  }
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
  BFS(nodes[0]);
  
  return 0;
}
