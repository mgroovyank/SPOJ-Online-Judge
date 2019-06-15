#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n;
    int i;
    int arr1[n];
    for(i=0;i<n;i++){
      cin>>arr1[i];
    }
    cin>>m;
    int arr2[m];
    for(i=0;i<m;i++){
      cin>>arr2[i];
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int j=0,min=abs(arr1[0]-arr2[0]);
    i=0;
    int temp;
    while(i<n && j<m){
      temp=abs(arr1[i]-arr2[j]);
      if(temp<min){
        min=abs(arr1[i]-arr2[j]);
        if(min==0){
          break;
        }
      }
      if(arr1[i]>arr2[j]){
        j++;
      }else{
        i++;
      }
    }
    cout<<min<<"\n";
  }
  return 0;
}
