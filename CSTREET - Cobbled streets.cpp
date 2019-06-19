#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class Subset{
  public:
  int parent;
  int rank;
};
class Edge{
  public:
  int src,dest,weight;
};
class Graph{
  public:
  int v,e;
  Edge *edge;
};
Graph* createGraph(int v,int e){
  Graph* graph = new Graph();
  graph->v=v;
  graph->e=e;
  graph->edge=new Edge[graph->e * sizeof(Edge)];
  return graph;
}
int find(Subset *subsets,int node){
  if(subsets[node].parent!=node){
    subsets[node].parent=find(subsets,subsets[node].parent);
  }
  return subsets[node].parent;
}
void younion(Subset *subsets,int x,int y){
  int xset=find(subsets,x);
  int yset=find(subsets,y);
  if(subsets[xset].rank>subsets[yset].rank){
    subsets[yset].parent=xset;
  }else if(subsets[xset].rank<subsets[yset].rank){
    subsets[xset].parent=yset;
  }else{
    subsets[yset].parent=xset;
    subsets[xset].rank++; 
  }
}
bool comparator(Edge edge1, Edge edge2){
  return edge1.weight<edge2.weight;
}
int kruskal(Graph *graph){
  int ans=0;
  sort(graph->edge,graph->edge+graph->e,comparator);
  Edge resultant_MST[graph->v-1];
  int i;
  int numEdges=0;
  Subset *subsets=new Subset[graph->v*sizeof(Subset)];
  for(i=0;i<graph->v;i++){
    subsets[i].parent=i;
    subsets[i].rank=0;
  }
  i=0;
  while(numEdges<graph->v-1){
    Edge tempEdge = graph->edge[i++];
    int x=find(subsets,tempEdge.src);
    int y=find(subsets,tempEdge.dest);
    if(x!=y){
      ans=ans+tempEdge.weight;
      resultant_MST[numEdges++]=tempEdge;
      younion(subsets,x,y);
    }
  }
  return ans;
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int p,n,m;
    cin>>p;
    cin>>n;
    cin>>m;
    Graph *graph=createGraph(n,m);
    int i;
    for(i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      graph->edge[i].src=a-1;
      graph->edge[i].dest=b-1;
      graph->edge[i].weight=c;
    }
    cout<<kruskal(graph)*p<<"\n";
  }
  return 0;
}
