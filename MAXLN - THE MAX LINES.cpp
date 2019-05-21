#include <iostream>
using namespace std;
int main(){
  int t;
  cin>>t;
  int i;
  for(i=1;i<=t;i++){
    long long int r,s;
    cin>>r;
    s=(4*r*r)+0.25;
    cout<<"Case "<<i<<": "<<s<<".25"<<"\n";
  }
  return 0;
}
