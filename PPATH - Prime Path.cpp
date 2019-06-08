#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;
bool isPrime[10000];
int visited[10000];
int dist[10000];
void genPrimes(int a,int b){
  int i,j,k;
  for(i=0;i<10000;i++){
    isPrime[i]=true;
  }
  for(i=2;i*i<=b;i++){
    j=a/i;
    j*=i;
    for(k=j;k<=b;k+=i){
      isPrime[k]=false;
    }
  }
}
int bfs(int a,int b){
  int i,j,temp;
  memset(visited,false,sizeof(visited));
  memset(dist,-1,sizeof(dist));
  dist[a]=0;
  queue<int> q;
  q.push(a);
  visited[a]=true;
  char num[8];
  while(!q.empty()){
    int u=q.front();
    q.pop();
    sprintf(num,"%d",u);
    for(i=0;i<4;i++){
      for(j=0;j<=9;j++){
        if(i==0 && j==0){
          continue;
        }else{
          num[i]=j+'0';
          temp=atoi(num);
          if(!visited[temp] && isPrime[temp] && temp!=u){
            q.push(temp);
            visited[temp]=true;
            dist[temp]=dist[u]+1;
            if(temp==b){
              return dist[b];
            }
          }
        }
      }
      sprintf(num,"%d",u);
    }
  }
  return dist[b];
}
int main(){
  int t;
  cin>>t;
  genPrimes(1000,9999);
  while(t--){
    int a,b;
    cin>>a>>b;
    int ans=bfs(a,b);
    if(ans==-1){
      cout<<"Impossible"<<"\n";
    }else{
      cout<<ans<<"\n";
    }
  }
}
