#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int t,j=1;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int i;
    int arr[n];
    for(i=0;i<n;i++){
      cin>>arr[i];
    }
    if(n==0){
      cout<<"Case "<<j<<": "<<0<<"\n";
    }else if(n==1){
      cout<<"Case "<<j<<": "<<arr[0]<<"\n";
    }else{
      long long int res1,res2,temp;
      res1=arr[0];
      res2=max(arr[0],arr[1]);
      for(i=2;i<n;i++){
        temp=max(res2,res1+arr[i]);
        res1=res2;
        res2=temp;
    }
    cout<<"Case "<<j<<": "<<res2<<"\n";
    }
    j++;
  }
}
