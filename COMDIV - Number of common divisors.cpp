#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a,int b){
  if(a==0){
    return b;
  }
  return gcd(b%a,a);
}
int comdiv(int n){
  int count=0;
  for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
      if(n/i==i){
        count++;
      }else{
        count+=2;
      }
    }
  }
  return count;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int a,b;
    cin>>a>>b;
    cout<<comdiv(gcd(a,b))<<"\n";
  }
  return 0;
}
