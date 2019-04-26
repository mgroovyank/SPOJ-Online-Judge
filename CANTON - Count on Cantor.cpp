#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int i,sum=0;
    for(i=1;sum<n;i++){
      sum+=i;
    }
    i--;
    sum=sum-i;
    i++;
    int num,den,j;
    if(i%2==0){
      num=i-1;
      den=1;
      for(j=sum+1;j<n;j++){
        num--;
        den++;
      }
    }else{
      num=1;
      den=i-1;
      for(j=sum+1;j<n;j++){
        num++;
        den--;
      }
    }
    cout<<"TERM "<<n<<" IS "<<num<<"/"<<den<<"\n";
  }
  return 0;
}
