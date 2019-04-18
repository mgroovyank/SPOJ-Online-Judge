#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int a,b;
    cin>>a>>b;
    int z,x,c,v;
    z=a;
    x=x*a;
    c=x*a;
    v=c*a;
    if(a==0){
      cout<<0;
    }else if(b==0){
      cout<<1;
    }else if(b%4==1){
      cout<<z%10;
    }else if(b%4==2){
      cout<<x%10;
    }else if(b%4==3){
      cout<<c%10;
    }else if(b%4==0){
      cout<<v%10;
    }
    cout<<"\n";
  }
}
