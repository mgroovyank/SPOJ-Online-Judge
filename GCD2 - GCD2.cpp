#include <iostream>
#include <string>
using namespace std;
int gcd(int a, int b){
  if(b==0){
    return a;
  }
  return gcd(b,a%b);
}
int main(){
  int t;
  cin>>t;
  while(t--){
    int a,ans=0;
    string b;
    cin>>a>>b;
    if(a==0){
      cout<<b<<"\n";
      continue;
    }
    for(int i=0;i<b.length();i++){
      ans=((b[i]-'0')+(ans*10))%a;
    }
    ans=gcd(a, ans);
    cout<<ans<<"\n";
  }
  return 0;
}
