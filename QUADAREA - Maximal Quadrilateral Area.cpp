#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    double a,b,c,d,s,area;
    cin>>a>>b>>c>>d;
    s=(a+b+c+d)/2;
    area=sqrt((s-a)*(s-b)*(s-c)*(s-d));
    printf("%.2f\n",area);
  }
  return 0;
}
