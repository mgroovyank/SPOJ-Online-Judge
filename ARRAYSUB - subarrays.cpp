#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int findMax(int ql,int qr,int *st,int l,int r,int cn){
  if(ql<=l && qr>=r){
    return st[cn];
  }
  if(ql>r || qr<l){
    return 0;
  }
  int mid=l+(r-l)/2;
  return max(findMax(ql,qr,st,l,mid,2*cn+1),findMax(ql,qr,st,mid+1,r,2*cn+2));
}
int createSTUtil(int arr[],int l,int r,int *st,int cn){
  if(l==r){
    st[cn]=arr[l];
    return arr[l];
  }
  int mid=l+(r-l)/2;
  st[cn]=max(createSTUtil(arr,l,mid,st,2*cn+1),createSTUtil(arr,mid+1,r,st,2*cn+2));
  return st[cn];
}
int* createST(int arr[],int n){
  int h=ceil(log2(n));
  int nodes=2*(int)pow(2,h)-1;
  int *st=new int[nodes];
  createSTUtil(arr,0,n-1,st,0);
  return st;
}
int main(){
  int n;
  while(cin>>n){
    int arr[n];
    int i;
    for(i=0;i<n;i++){
      cin>>arr[i];
    }
    int k;
    cin>>k;
    int *st=createST(arr,n);
    for(i=0;i<=n-k;i++){
      cout<<findMax(i,i+k-1,st,0,n-1,0)<<"\n";
    }
  }
}
