#include <iostream>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    long long int c,x,s,n,d,a;
    cin>>c>>x>>s;
    n=(2*s)/(c+x);
    d=(x-c)/(n-5);
    a=c-2*d;
    cout<<n<<"\n";
    long long int i;
    for(i=1;i<=n;i++){
      if(i==1){
        cout<<a;
        continue;
      }
      cout<<" ";
      cout<<a+(i-1)*d;
    }
    cout<<"\n";
  }
  return 0;
}
