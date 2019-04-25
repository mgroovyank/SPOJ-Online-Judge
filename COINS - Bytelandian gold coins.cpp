#include <iostream>
#include <map>
using namespace std;
map <int,long long int> dp;
long long int fun(int n){
  if(n==0){
    return 0;
  }
  if(dp[n]!=0){
    return dp[n];
  }
  long long int temp=fun(n/2)+fun(n/3)+fun(n/4);
  if(temp>n){
    dp[n]=temp;
  }else{
    dp[n]=n;
  }
  return dp[n];
}
int main(){
  int n;
  while(cin>>n){
    cout<<fun(n)<<"\n";
  }
  return 0;
}
