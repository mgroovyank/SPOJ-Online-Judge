#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double n;
  cin>>n;
  double k;
  k=log2(n);
  if(ceil(k)==floor(k)){
    cout<<"TAK";
  }else{
    cout<<"NIE";
  }
  return 0;
}
