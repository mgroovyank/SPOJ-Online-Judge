#include <iostream>
using namespace std;
int main(){
  int n;
  while(cin>>n){
    if(n%10==0){
    cout<<2;
  }else{
    cout<<1<<"\n";
    cout<<n%10;
  }
  cout<<"\n";
  }
  
}
