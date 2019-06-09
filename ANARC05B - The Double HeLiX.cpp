#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n,m;
  cin>>n;
  while(n){
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
    int j;
    int sum1,sum2,res;
    sum1=sum2=res=j=i=0;
    while(i<n || j<m){
      if(i==n){
        while(j<m){
          sum2+=arr2[j];
          j++;
        }
      }else if(j==m){
        while(i<n){
          sum1+=arr1[i];
          i++;
        }
      }else if(arr1[i]<arr2[j]){
        sum1+=arr1[i];
        i++;
      }else if(arr1[i]>arr2[j]){
        sum2+=arr2[j];
        j++;
      }else{
        res+=max(sum1,sum2);
        sum1=sum2=arr1[i];
        i++;
        j++;
      }
    }
    res+=max(sum1,sum2);
    cout<<res<<"\n";
    cin>>n;
  }
}
