#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int a,d;
  cin>>a>>d;
  while(a!=0 && d!=0){
    int t[a],f[d];
    int i;
    for(i=0;i<a;i++){
      cin>>t[i];
    }
    for(i=0;i<d;i++){
      cin>>f[i];
    }
    sort(t,t+a);
    sort(f,f+d);
    if(t[0]<f[1]){
      cout<<"Y"<<"\n";
    }else{
      cout<<"N"<<"\n";
    }
    cin>>a>>d;
  }
}
