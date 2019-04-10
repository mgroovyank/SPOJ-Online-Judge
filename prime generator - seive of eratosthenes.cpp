#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
  int m;//m is smaller of range
  int x;//x is larger of range
  
  cin>>m;
  cin>>x;
  
  //code to find sqrt of x 
  double a=x;
  int n=floor(sqrt(a));
  
  int arr1[n+1];//array storing primality of numbers till n
  int i;
  
  //intialising every number till n to be prime- 1 indicates prime
  for(i=1;i<n+1;i++){
    arr1[i]=1;
  }
  
  //finding prime numbers till n
  int j=2;
  while(j<=n/2){
    for(i=j+j;i<n+1;i+=j){
      arr1[i]=0;
    }
    j=j+1;
    while(arr1[j]!=1){
      j+=1;
    }
  }
  
  //printing out prime numbers till n
  for(i=2;i<n+1;i++){
    if(arr1[i]==1){
      cout<<i;
    }
  }
  
  cout<<"\n";
  
  int arr2[x-m+1];//array to store primality of numbers in range
  
  for(i=0;i<x-m+1;i++){
    arr2[i]=1;
  }
  
  //finding prime numbers in the range
  int k;
  for(i=2;i<n+1;i++){
    if(arr1[i]==1){
      j=m/i;
      j=j*i;
      for(k=j;k<=x;k+=i){
        if(k>=m){
          arr2[k-m]=0;
        }
      }
    }
  }
  
  //printing out prime numbers in the range
  for(i=0;i<x-m+1;i++){
    if(arr2[i]==1){
      cout<<m+i;
    }
  }
}
