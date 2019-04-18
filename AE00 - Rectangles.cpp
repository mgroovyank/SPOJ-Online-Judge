#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int n;
  cin>>n;
  int i,j,k=0;
  int u=int(floor(sqrt(n)));
  for(i=1;i<=u;i+=1){//i depicts no of rows
    k+=n/i-i+1;
  }
  cout<<k;
  return 0;
}
