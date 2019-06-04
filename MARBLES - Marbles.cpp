#include <iostream>
using namespace std;
long long int c(int n,int k){
  long long int res=1;
  if(k>n-k){
    k=n-k;
  }
  int i;
  for(i=0;i<k;i++){
    res=res*(n-i);
    res=res/(i+1);
  }
  return res;
}
int main() {
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    cout<<c(n-1,k-1)<<"\n";
  }
  return 0;
}
