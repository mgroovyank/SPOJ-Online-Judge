#include <iostream>
#include <cmath>
#include <iomanip>
#define pi 3.14159
using namespace std;
int main(){
  int n;
  cin>>n;
  while(n){
    double a;
    a=(pow((n/pi),2)*pi)/2;
    cout<<fixed<<setprecision(2)<<a<<"\n";
    cin>>n;
  }
  return 0;
}
