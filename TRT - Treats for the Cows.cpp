#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int treats[2000];
int arr[2000][2000];
int money(int treats[],int s,int e){
  if(s>e){
    return 0;
  }
  if(arr[s][e]!=-1){
    return arr[s][e];
  }
  int day=n-(e-s);
  return arr[s][e]=max(money(treats,s+1,e)+treats[s]*day,money(treats,s,e-1)+treats[e]*day);
}
int main(){
  while(cin>>n){
    int i;
    for(i=0;i<n;i++){
      cin>>treats[i];
    }
    memset(arr,-1,sizeof(arr));
    int ans=money(treats,0,n-1);
    cout<<ans<<"\n";
  }
}
