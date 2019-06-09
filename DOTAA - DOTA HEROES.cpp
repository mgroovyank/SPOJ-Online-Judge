#include <iostream>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m,d;
    cin>>n>>m>>d;
    int l,ans=0;
    while(n--){
      cin>>l;
      if(l-d>0){
        if(l%d>0){
          ans=ans+l/d;
        }else{
          ans=ans+l/d-1;
        }
      }
    }
    if(ans>=m){
      cout<<"YES";
    }else{
      cout<<"NO";
    }
    cout<<"\n";
  }
  return 0;
}
