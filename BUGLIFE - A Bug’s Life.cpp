#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int b;
bool isBipartiteUtil(int i,int color[],vector<int> g[]){
  color[i]=1;
  queue<int> q;
  q.push(i);
  int x,j;
  while(!q.empty()){
    x=q.front();
    q.pop();
    for(j=0;j<g[x].size();j++){
      if(color[g[x][j]]==-1){
        color[g[x][j]]=color[x]^1;
        q.push(g[x][j]);
      }else if(color[g[x][j]]==color[x]){
        return false;
      }
    }
  }
  return true;
}
bool isBipartite(vector<int> g[]){
  int color[2001];
  int i;
  for(i=1;i<=b;i++){
    color[i]=-1;
  }
  for(i=1;i<=b;i++){
    if(color[i]==-1){
      if(isBipartiteUtil(i,color,g)==false){
        return false;
        }
    }
   
  }
  return true;
}
int main(){
  int s,c;
  cin>>s;
  for(c=1;c<=s;c++){
    int e;
    cin>>b>>e;
    vector<int> g[b+1];
    int u,v;
    while(e--){
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cout<<"Scenario #"<<c<<":"<<"\n";
    if(isBipartite(g)){
      cout<<"No suspicious bugs found!";
    }else{
      cout<<"Suspicious bugs found!";
    }
    cout<<"\n";
  }
  return 0;
}
