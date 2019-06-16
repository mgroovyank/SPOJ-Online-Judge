#include <iostream>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int h,a;
    cin>>h>>a;
    int moves=1;
    h=h+3;
    a=a+2;
    while(h && a){
      if(h>20 && a<=10){
        h=h-17;
        a=a+7;
        moves+=2;
      }else if(h>5 && a>10){
        h=h-2;
        a=a-8;
        moves+=2;
      }else{
        break;
      }
    }
    cout<<moves<<"\n";
  }
}
