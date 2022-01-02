// Ahmed Nasser Mohamed

/*
--Problem description : find the shortest paths form a node to a target node
--Solution : 1- use a priority queue to pick the minimum weight each time  
             2- use heuristic function like (Euclidean distance) to choose the right direction  
             3- relax the reached nodes with minimum
             4- stop when reaching the target node
--Time complexity : O((V+E)*log(V))
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX=1e8+1;

struct Node;
struct Edge;

struct Node{
  int x=0;
  int y=0;
  int distance=MAX; 
  vector<Edge>neighbours={}; 
  Node(int _x, int _y) : x(_x), y(_y) {}
};

struct Edge{
  double euclidean=0;
  int weight=0;
  Node* toNode=NULL;
  Edge(double _euclidean, int _weight, Node* _toNode) : euclidean(_euclidean), weight(_weight), toNode(_toNode) {}
  bool operator >(const Edge & e2) const{
    if(euclidean != e2.euclidean) return euclidean > e2.euclidean;
    return weight > e2.weight;
  }
};

double Euclidean(Node* a, Node* b){
  return hypot(a->x - b->x, a->y - b->y);
}

int AStar(Node* src, Node* tar){
  priority_queue<Edge, vector<Edge>, greater<Edge>>q;
  src->distance=0;
  q.push(Edge(Euclidean(src,tar),src->distance,src));
  while(!q.empty()){
    Edge tp=q.top();
    q.pop();

    int soFarWeight=tp.weight; 
    Node* node=tp.toNode; 
    if(node==tar) break;
    if(soFarWeight != node->distance) continue;

    for(auto& edge : node->neighbours){
      int weight=edge.weight;
      Node* neighbour=edge.toNode;
      if(neighbour->distance > soFarWeight+weight){
        neighbour->distance=soFarWeight+weight;
        q.push(Edge(Euclidean(neighbour,tar), neighbour->distance, neighbour));
      }
    }
  }
  return tar->distance;
}


int main(){
  int n,m,src,tar;
  cin>>n>>m>>src>>tar;
  src--,tar--;
  vector<Node*> nodes(n);
  for(auto& node : nodes){
    int x,y;
    cin>>x>>y;
    node=new Node(x,y);
  }
  while(m--){
    int u,v,c;
    cin>>u>>v>>c;
    u--,v--;
    double euclidean=Euclidean(nodes[u],nodes[v]);
    nodes[u]->neighbours.push_back(Edge(euclidean,c,nodes[v]));
    nodes[v]->neighbours.push_back(Edge(euclidean,c,nodes[u]));
  }
  int ans=AStar(nodes[src],nodes[tar]);
  cout<<ans<<'\n';

  return 0;
  
}
