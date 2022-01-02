// Ahmed Nasser Zaki

/*
--Problem description : find the shortest paths form all nodes to all nodes
--Solution : 1- iterate over three nested loops representing u,v, and k
             2- see if it is the minimum to go from u to v directly or go through k
--Time complexity : O(n^3)
*/

#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;

struct Edge{
  int weight=INF;
};


void Floyed(vector<vector<Edge>>& edgeMatrix){
  for(int k=0; k<edgeMatrix.size(); k++)
    for(int u=0; u<edgeMatrix.size(); u++)
      for(int v=0; v<edgeMatrix.size(); v++)  
        edgeMatrix[u][v].weight=min(edgeMatrix[u][v].weight, edgeMatrix[u][k].weight + edgeMatrix[k][v].weight);
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<Edge>>edgeMatrix(n, vector<Edge>(n));
  for(int i=0; i<n; i++) edgeMatrix[i][i].weight=0;
  while(m--){
    int u,v,c;
    cin>>u>>v>>c;
    u--,v--;
    edgeMatrix[u][v].weight=edgeMatrix[v][u].weight=min(edgeMatrix[u][v].weight, c);
  }
  Floyed(edgeMatrix);

  return 0;
}
