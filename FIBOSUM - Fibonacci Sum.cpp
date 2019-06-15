#include <iostream>
#include <cmath>
#include <map>
#define MOD 1000000007
using namespace std;
map<long long int,long long int> f;
long long int fib(long long int n){
  if(n==0){
    return 0; 
  } 
  if(n==1 || n==2){
    return(f[n] = 1); 
  }
  if(f[n]){
    return f[n]; 
  }
  int k = (n & 1)? (n+1)/2 : n/2; 
  f[n]=(n & 1)?(fib(k)*fib(k) + fib(k-1)*fib(k-1))%MOD:((2*fib(k-1) + fib(k))*fib(k))%MOD; 
  return f[n];
}
int main(){
  long long int t;
  cin>>t;
  while(t--){
    long long int n,m;
    cin>>n>>m;
    cout<<(fib(m+2)-fib(n+1) + MOD)%MOD<<"\n";
  }
  return 0;
}
