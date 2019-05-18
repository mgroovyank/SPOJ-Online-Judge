#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n,t;
  cin>>n;
  while(n!=-1){
    if(n%2){
      n--;
      if(n%3==0){
        n=n/3;
        n=4*n+1;
        t=sqrt(n);
        if(t*t==n){
          if(n%2){
            cout<<"Y";
          }else{
            cout<<"N";
          }
        }else{
          cout<<"N";
        }
      }else{
        cout<<"N";
      }
    }else{
      cout<<"N";
    }
    cout<<"\n";
    cin>>n;
  }
  return 0;
}
