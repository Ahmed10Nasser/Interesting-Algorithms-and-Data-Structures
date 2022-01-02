// Ahmed Nasser Zaki

/*
--Problem description : find the shortest paths form a node to all other nodes
--Solution : 1- use a priority queue to pick the minimum weight each time  
             2- relax the reached nodes with minimum
--Time complexity : O((V+E)*log(V))
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX=1e8+1;

struct Node;
struct Edge;

struct Node{
  int distance=MAX; 
  vector<Edge>neighbours={}; 
};

struct Edge{
  int weight=0;
  Node* toNode=NULL;
  Edge(int _weight, Node* _toNode) : weight(_weight), toNode(_toNode) {}
  bool operator >(const Edge & e2) const{
    return weight > e2.weight;
  }
};


void Dijkstra(Node* src){
  priority_queue<Edge, vector<Edge>, greater<Edge>>q;
  src->distance=0;
  q.push(Edge(src->distance,src));
  while(!q.empty()){
    Edge tp=q.top();
    q.pop();

    int soFarWeight=tp.weight; 
    Node* node=tp.toNode; 
    if(soFarWeight != node->distance) continue;

    for(auto& edge : node->neighbours){
      int weight=edge.weight;
      Node* neighbour=edge.toNode;
      if(neighbour->distance > soFarWeight+weight){
        neighbour->distance=soFarWeight+weight;
        q.push(Edge(neighbour->distance, neighbour));
      }
    }
  }
}


int main(){
  int n,m,src;
  cin>>n>>m>>src;
  src--;
  vector<Node*> nodes(n);
  for(auto& node : nodes) node=new Node;
  while(m--){
    int u,v,c;
    cin>>u>>v>>c;
    u--,v--;
    nodes[u]->neighbours.push_back(Edge(c,nodes[v]));
    nodes[v]->neighbours.push_back(Edge(c,nodes[u]));
  }
  Dijkstra(nodes[src]);
  for(int i=0; i<n; i++)
    cout<<nodes[i]->distance<<'\n';
  
  return 0;
  
}
