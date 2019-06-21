#include <iostream>
#include <cstring>
using namespace std;
int dp[1000001];
int k,l,m;
bool isWinning(int x){
  if(dp[x]==1){
    return true;
  }
  if(dp[x]==0){
    return false;
  }
  int moves[]={x-1,x-k,x-l};
  for(int i=0;i<3;i++){
    if(moves[i]>=0 && !isWinning(moves[i])){
      dp[x]=1;
      return true;
    }
  }
  dp[x]=0;
  return false;
}
int main(){
  while(cin>>k>>l>>m){
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    dp[1]=1;
    dp[k]=dp[l]=1;
    int p;
    while(m--){
      cin>>p;
      if(isWinning(p)){
        cout<<'A';
      }else{
        cout<<'B';
      }
    }
  }
}
