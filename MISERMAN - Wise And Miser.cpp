#include <iostream>
using namespace std;
int main(){
  int n,m;
  while(cin>>n>>m){
    int arr[n][m];
    int i,j;
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
        cin>>arr[i][j];
      }
    }
    for(i=1;i<n;i++){
      for(j=0;j<m;j++){
        if(j==0){
          arr[i][j]+=min(arr[i-1][j],arr[i-1][j+1]);
        }else if(j==n-1){
          arr[i][j]+=min(arr[i-1][j],arr[i-1][j-1]);
        }else{
          arr[i][j]+=min(arr[i-1][j],min(arr[i-1][j-1],arr[i-1][j+1]));
        }
      }
    }
    int ans=arr[n-1][0];
    for(j=1;j<m;j++){
      ans=min(ans,arr[n-1][j]);
    }
    cout<<ans<<"\n";
  }
}
