#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int b,n;
  cin>>b>>n;
  while(b!=0 && n!=0){
    int i;
    int fee[n],fun[n];
    for(i=0;i<n;i++){
      cin>>fee[i]>>fun[i];
    }
    int sack[n][b+1];
    int j;
    for(i=0;i<n;i++){
      sack[i][0]=0;
    }
    for(i=0;i<n;i++){
      for(j=1;j<b+1;j++){
        if(fee[i]>j){
          if(i==0){
            sack[0][j]=sack[0][0];
          }else{
            sack[i][j]=sack[i-1][j];
          }
        }else if(fee[i]<=j){
          if(i==0){
            sack[0][j]=fun[0];
          }else{
            sack[i][j]=max(fun[i]+sack[i-1][j-fee[i]],sack[i-1][j]);
          }
        }
      }
    }
    int totalFees=0;
    for(j=1;j<b+1;j++){
      if(sack[n-1][j]==sack[n-1][b]){
        totalFees=j;
        break;
      }
    }
    cout<<totalFees<<" "<<sack[n-1][b]<<"\n";
    cin>>b>>n;
  }
  return 0; 
}
