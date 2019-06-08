#include <iostream>
#include <cstring>
#include <algorithm>
#define INT_MAX 9999999
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int e,f;
    cin>>e>>f;
    int n;
    cin>>n;
    int i;
    int p[n],w[n];
    for(i=0;i<n;i++){
      cin>>p[i]>>w[i];
    }
    int total_weight=f-e;
    int dp[f-e+1];
    for(i=1;i<=total_weight;i++){
      dp[i] = INT_MAX;
    }
    dp[0]=0;
    int j;
    for(i=1;i<=total_weight;i++){
      for(j=0;j<n;j++){
        if(w[j]<=i){
          dp[i]=min(dp[i],dp[i-w[j]]+p[j]);
        }
      }
    }
    if(dp[total_weight]==INT_MAX){
      cout<<"This is impossible."<<"\n";
    }else{
      cout<<"The minimum amount of money in the piggy-bank is "<<dp[total_weight]<<"."<<"\n";
    }
  }
}
