// Ahmed Nasser Mohamed

/*
--Problem description : find the shortest paths form a node to all other nodes
--Solution : 1- loop with number of vertices
             2- each time iterate over all edges and relax its node with minimum 
--Time complexity : O(V*E)
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX=1e3+1, MAX_DIS=2e6+1;

struct Node{
  int distance=MAX_DIS;
};

struct Edge{
  Node* fromNode=NULL;
  Node* toNode=NULL;
  int weight=MAX;
  Edge(Node* _fromNode, Node* _toNode, int _weight) : fromNode(_fromNode), toNode(_toNode), weight(_weight) {}
};


bool Bellman(vector<Edge>& edges, Node* src, int n){
  bool hasNegCycle=0;
  src->distance=0;
  for(int i=1; i<=n; i++){
    bool isUpdated=0;
    for(auto& edge : edges){
      if(edge.toNode->distance > edge.fromNode->distance + edge.weight){
        edge.toNode->distance = edge.fromNode->distance + edge.weight;
        isUpdated=1;
      }
    }
    if(isUpdated==0) break;
    else if(i==n) hasNegCycle=1;
  }
  return hasNegCycle;
}

int main(){
  int n,m,src;
  cin>>n>>m>>src;
  src--;
  vector<Node*>nodes(n);
  for(auto& node : nodes) node=new Node;
  vector<Edge>edges;
  while(m--){
    int u,v,c;
    cin>>u>>v>>c;
    u--,v--;
    edges.push_back(Edge(nodes[u], nodes[v], c));
  }
  
  bool hasNegCycle=Bellman(edges, nodes[src], n);
  if(hasNegCycle) cout<<"There is a negative cycle\n";
  else cout<<"There is no negative cycle\n";

  return 0;
}
