#include <iostream>
using namespace std;
int ans,h,w;
char grid[50][50];
int visited[50][50];
void dfs(int i,int j,int currentDepth){
  ans=max(ans,currentDepth);
  int r[]={-1,-1,-1,0,0,1,1,1};
  int c[]={-1,0,1,-1,1,-1,0,1};
  for(int x=0;x<8;x++){
    int tempr=i+r[x];
    int tempc=j+c[x];
    if((tempr>=0 && tempc>=0) && (tempr<h && tempc<w) && !visited[tempr][tempc]){
      if(grid[tempr][tempc]==grid[i][j]+1){
        visited[tempr][tempc]=1;
        dfs(tempr,tempc,currentDepth+1);
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int c=0;
  cin>>h>>w;
  while(h && w){
    ans=0;
    int i,j;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        cin>>grid[i][j];
        visited[i][j]=0;
      }
    }
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        if(grid[i][j]=='A'){
          visited[i][j]=1;
          dfs(i,j,1);
        }
      }
    }
    c++;
    cout<<"Case "<<c<<": "<<ans<<"\n";
    cin>>h>>w;
  }
}
