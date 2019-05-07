#include <bits/stdc++.h> 
using namespace std;
class graph{
  int v;
  list<int> *adj;
  public:
    graph(int v);
    void addEdge(int v,int w);
    void longestPathLength();
    pair<int,int> bfs(int u);
};
graph::graph(int v){
  this->v=v;
  adj=new list<int>[v];
}
void graph::addEdge(int v,int w){
  adj[v].push_back(w);
  adj[w].push_back(v);
}
pair<int,int> graph::bfs(int u){
  int dis[v];
  memset(dis,-1,sizeof(dis));
  queue<int> q;
  q.push(u);
  dis[u]=0;
  while(!q.empty()){
    int t=q.front();
    q.pop();
    for(auto it=adj[t].begin();it!=adj[t].end();it++){
      int v=*it;
      if(dis[v]==-1){
        q.push(v);
        dis[v]=dis[t]+1;
      }
    }
  }
  int maxDis=0;
  int nodeIdx;
  for(int i=1;i<v;i++){
    if(dis[i]>maxDis){
      maxDis=dis[i];
      nodeIdx=i;
    }
  }
  return make_pair(nodeIdx,maxDis);
}
void graph::longestPathLength(){
  pair<int,int> t1,t2;
  t1=bfs(1);
  t2=bfs(t1.first);
  cout<<t2.second;
}
int main(){
  int n,i,v,w;
  while(cin>>n){
    graph g(n+1);
    for(i=1;i<n;i++){
      cin>>v>>w;
      g.addEdge(v,w);
    }
    g.longestPathLength();
    cout<<"\n";
  }
  return 0;
}
