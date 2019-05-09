#include <iostream>
using namespace std;
int main(){
  int t;
  long long int n;
  cin>>t;
  while(t--){
    cin>>n;
    cout<<((n*(3*n+1))/2)%1000007<<"\n";
  }
  return 0;
}
