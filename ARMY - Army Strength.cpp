#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    cout<<"\n";
    int ng,nm;
    cin>>ng>>nm;
    int i,pg[ng],pm[nm];
    int maxg=0,maxm=0;
    for(i=0;i<ng;i++){
      cin>>pg[i];
      if(maxg<pg[i]){
        maxg=pg[i];
      }
    }
    for(i=0;i<nm;i++){
      cin>>pm[i];
      if(maxm<pm[i]){
        maxm=pm[i];
      }
    }
    if(maxg>=maxm){
      cout<<"Godzilla";
    }else if(maxg<maxm){
      cout<<"MechaGodzilla";
    }
  }
  return 0;
}
