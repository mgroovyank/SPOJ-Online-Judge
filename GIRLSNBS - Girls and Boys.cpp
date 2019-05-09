#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int g,b;
  cin>>g>>b;
  while(g!=-1 && b!=-1){
    int t,m,q,r;
    t=min(b,g)+1;
    m=max(b,g);
    q=m/t;
    r=m%t;
    if(t==1){
      cout<<m<<"\n";
    }else{
      if(r==0){
        cout<<q<<"\n";
      }else{
        cout<<q+1<<"\n";
      }
    }
    cin>>g>>b;
  }
  return 0;
}
 
