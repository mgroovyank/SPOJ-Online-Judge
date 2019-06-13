#include <iostream>
using namespace std;
bool ans(long long int n){
  for(long long int i=2;i*i<=n;i++){
    int count=0;
    if(n%i==0){
      while(n%i==0){
        count++;
        n=n/i;
      }
      if(i%4==3 && count%2!=0){
        return false;
      }
    }
  }
  return n%4!=3;
}
int main(){
  long long int c;
  cin>>c;
  while(c--){
    long long int n;
    cin>>n;
    bool t=ans(n);
    if(t){
      cout<<"Yes"<<"\n";
    }else{
      cout<<"No"<<"\n";
    }
  }
}
