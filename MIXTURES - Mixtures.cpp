#include <iostream>
#include <algorithm>
using namespace std;
#define INT_MAX 10000000
long long int dp[110][110];
int colors[100];
long long int sum(int i,int j){
  long long int ans=0;
  for(int k=i;k<=j;k++){
    ans=ans+colors[k];
    ans=ans%100;
  }
  return ans;
}
long long int solveMixtures(int i,int j){
  if(i>=j){
    return 0;
  }
  if(dp[i][j]!=-1){
    return dp[i][j];
  }
  int k;
  dp[i][j]=INT_MAX;
  for(k=i;k<=j;k++){
    dp[i][j]=min(dp[i][j],solveMixtures(i,k)+solveMixtures(k+1,j)+sum(i,k)*sum(k+1,j));
  }
  return dp[i][j];
}
int main(){
  int n;
  while(cin>>n){
    int i,j;
    for(i=0;i<n;i++){
      cin>>colors[i];
    }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        dp[i][j]=-1;
      }
    }
    cout<<solveMixtures(0,n-1)<<"\n";
  }
  return 0;
}
