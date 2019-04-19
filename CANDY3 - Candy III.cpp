#include <iostream>
using namespace std;
int main() {
  int t;
  long long int n;
  cin>>t;
  cout<<"\n";
  while(t--){
    cin>>n;
    long long int x,y,sum=0;
    x=n;
    while(x--){
      cin>>y;
      sum=(sum+y)%n;
    }
    if(sum==0){
      cout<<"YES"<<"\n"<<"\n";
    }else{
      cout<<"NO"<<"\n"<<"\n";
    }
  }
}
