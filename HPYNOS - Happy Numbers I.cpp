// the cycle always contains 4
#include <iostream>
using namespace std;
int breakNum(int n){
  int ans=0;
  while(n){
    ans+=(n%10)*(n%10);
    n=n/10;
  }
  return ans;
}
int main(){
  int n,count=0;
  while(cin>>n){
    while(1){
      n=breakNum(n);
      count+=1;
      if(n==4){
        cout<<-1;
        break;
      }
      if(n==1){
        cout<<count<<"\n";
        break;
      }
    }   
  }
}
