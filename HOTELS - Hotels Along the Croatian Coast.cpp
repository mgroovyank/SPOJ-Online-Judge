#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  long long int n,m;
  cin>>n>>m;
  while(n && m){
    long long int arr[n],i;
    for(i=0;i<n;i++){
      cin>>arr[i];
    }
    long long int sum=0,max=0,j=0;
    for(i=0;i<n;i++){
      if(sum+arr[i]<m){
        sum=sum+arr[i];
      }else if(sum+arr[i]==m){
        max=m;
        break;
      }else{
        while(sum+arr[i]>m){
          sum=sum-arr[j];
          j++;
        }
        if(sum+arr[i]==m){
          max=m;
          break;
        }else if(sum+arr[i]<m){
          sum=sum+arr[i];
        }
      }
      if(sum>=max){
        max=sum;
      }
    }
    cout<<max<<"\n";
    cin>>n>>m;
  }
  return 0;
}
