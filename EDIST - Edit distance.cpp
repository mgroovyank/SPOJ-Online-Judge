#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  int t;
  cin>>t;
  string a,b;
  while(t--){
    cin>>a;
    cin>>b;
    int arr[b.length()+1][a.length()+1];
    int i,j;
    for(j=0;j<a.length()+1;j++){
      arr[0][j]=j;
    }
    for(i=0;i<b.length()+1;i++){
      arr[i][0]=i;
    }
    for(i=0;i<b.length();i++){
      for(j=0;j<a.length();j++){
        if(a[j]==b[i]){
          arr[i+1][j+1]=arr[i][j];
        }else{
          arr[i+1][j+1]=min(arr[i][j+1],min(arr[i][j],arr[i+1][j]))+1;
        }
      }
    }
    cout<<arr[b.length()][a.length()]<<"\n";
  }
  return 0;
} 
