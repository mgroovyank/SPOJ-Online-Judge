#include <iostream>
using namespace std;
int main(){
  int n,i;
  cin>>n;
  while(n){
    int arr[n],k;
    for(i=0;i<n;i++){
      cin>>arr[i];
    }
    for(i=0;i<n;i++){
      k=arr[i];
      if(arr[k-1]==i+1){
        continue;
      }
      break;
    }
    if(i!=n){
      cout<<"not ambiguous"<<"\n";
    }else{
      cout<<"ambiguous"<<"\n";
    }
    cin>>n;
  }
  return 0;
}
